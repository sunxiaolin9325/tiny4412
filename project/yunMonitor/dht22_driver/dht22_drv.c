#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>

#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/delay.h>

#include <linux/gpio.h>		//gpio_set_value
#include <plat/gpio-cfg.h>	//S3C_GPIO_INPUT

#include "dht22.h"

//====硬件相关=====================
//拉高
void set_gpio_high(unsigned gpio)
{
	//配置gpio模式
	s3c_gpio_cfgpin(gpio, S3C_GPIO_OUTPUT);
	//设置gpio的值
	gpio_set_value(gpio, 1);
}

//拉低
void set_gpio_low(unsigned gpio)
{
	s3c_gpio_cfgpin(gpio, S3C_GPIO_OUTPUT);
	gpio_set_value(gpio, 0);
}

//读电平值
int get_gpio_value(unsigned gpio)
{
	s3c_gpio_cfgpin(gpio, S3C_GPIO_INPUT);
	return gpio_get_value(gpio);
}

//读数据
int __read_dht22(unsigned gpio, char *buf)
{
	int i, j;
	int count;

	count = 0;
	memset(buf, 0, 5);

	//起始信号
	set_gpio_high(gpio);
	udelay(10);
	set_gpio_low(gpio);
	udelay(600);
	set_gpio_high(gpio);

	//检测到低电平跳出
	count = 0;
	do {
		udelay(2);
		count++;
	}
	while (get_gpio_value(gpio) && (count < TIMEOUT));
	if (count >= TIMEOUT) {
		return -1;
	}

	//检测到高电平跳出
	count = 0;
	do {
		udelay(2);
		count++;
	}
	while (!get_gpio_value(gpio) && count < TIMEOUT);
	if (count >= TIMEOUT) {
		return -1;
	}

	//循环接收每一位数据
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 8; j++) {
			//检测到低电平跳出
			count = 0;
			do {
				udelay(2);
				count++;
			}
			while (get_gpio_value(gpio) && count < TIMEOUT);
			if (count >= TIMEOUT) {
				return -1;
			}

			//检测到高电平跳出
			count = 0;
			do {
				udelay(2);
				count++;
			}
			while (!get_gpio_value(gpio) && count < TIMEOUT);
			if (count >= TIMEOUT) {
				return -1;
			}

			//高电平为1,保存数据
			udelay(40);
			if (get_gpio_value(gpio)) {
				buf[i] |= 1 << (7 - j);
			}
		}
	}

	//释放总线
	set_gpio_high(gpio);
	return 0;
}

int read_dht22(unsigned gpio, int *temp, int *humi)
{
	char buf[5];
	int ret;

//要支持阻塞访问
	ret = __read_dht22(gpio, buf);
	if (ret < 0) {
		printk("read_dht22: timeout gpio: %d\n", gpio);
		return -1;
	} else {
	//	if (buf[0] + buf[1] + buf[2] + buf[3] == buf[4]) {
			*temp = buf[2] << 8 | buf[3];
			*humi = buf[0] << 8 | buf[1];
			printk("%d %d\n", *temp, *humi);
	/*	} else {
			//不把错误返回给用户态
			memset(buf, 0, 5);
			printk("data error gpio: %d\n", gpio);
			return -2;
		}
		*/
	}

	return 0;
}

//====硬件无关=====================
// /dev/dht22 dht22->misc 
int dht22_open(struct inode *no, struct file *fp)
{
	struct dht22_st *d;

	d = container_of(fp->f_op, struct dht22_st, dht22_ops);
	fp->private_data = d;

	spin_lock(&d->lock);
	/*if (d->count) {
		spin_unlock(&d->lock);
		return -EBUSY;
	}*/
	d->count++;
	spin_unlock(&d->lock);

	return 0;
}

int dht22_close(struct inode *no, struct file *fp)
{
	struct dht22_st *d;

	d = fp->private_data;
	spin_lock(&d->lock);
	/*if (!d->count) {
		spin_unlock(&d->lock);
		return -ENODEV;	
	}*/
	d->count--;
	spin_unlock(&d->lock);

	return 0;
}

ssize_t dht22_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct dht22_st *d;
	struct dht22_pro_st pro;
	int ret;
	int no;

	if (count != sizeof(pro)) {
		return -EINVAL;
	}

	d = fp->private_data;

	//保证数据干净,没读到数据,传给用户态的是0,不要垃圾值
	memset(&pro, 0, sizeof(pro));
	//根据用户态的选择来读取指定GPIO
	no = ((struct dht22_pro_st *)buffer)->no;
	//支持多线程读取
	read_dht22(d->gpio[no], &pro.temp, &pro.humi);

	//这步必须做,buffer中传过来的no在copy_to_user已被清除
	pro.no = no;
	ret = copy_to_user(buffer, &pro, sizeof(pro));
	if (ret) {
		return -EFAULT;
	}

	return count;
}

//设备模型
int dht22_probe(struct platform_device *pdev)
{
	int ret;
	struct dht22_st *dht22;
	struct resource *dht22_res, *dht22_res1, *dht22_res2;
	struct dht22_info_st *info;
	int i;

	//注意：0代表IORESOURCE_MEM类型资源的第0个
	//1.获得资源	
	dht22_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	dht22_res1 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	dht22_res2 = platform_get_resource(pdev, IORESOURCE_MEM, 2);
	if (!dht22_res || !dht22_res1 || !dht22_res2) {
		return -EBUSY;
	}

	//2.分配设备结构体
	info = pdev->dev.platform_data; 
	dht22 = kzalloc(sizeof(*dht22) + sizeof(unsigned) * info->num, GFP_KERNEL);
	if (!dht22) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	//3.将GPIO地址统一存入数组
	dht22->num = info->num;
	for (i=0; i<dht22_res->end-dht22_res->start+1; i++) {
		dht22->gpio[i] = dht22_res->start + i;
	}
	dht22->gpio[i++] = dht22_res1->start;
	dht22->gpio[i] = dht22_res2->start;

	//4.misc设备注册,一个设备文件,支持NUM个物理设备
	dht22->dht22_ops.open = dht22_open;
	dht22->dht22_ops.release = dht22_close;
	dht22->dht22_ops.read = dht22_read;
	// /dev/dht22
	dht22->misc.name = pdev->name;
	dht22->misc.minor = MISC_DYNAMIC_MINOR;
	dht22->misc.fops = &dht22->dht22_ops; 
	//
	ret = misc_register(&dht22->misc);
	if (ret) {
		goto misc_error;
	}

	//5.申请GPIO
	for (i=0; i<dht22->num; i++) {
		ret = gpio_request(dht22->gpio[i], "dht22_dataio");
		if (ret < 0) { 
			ret = -EBUSY;
			goto gpio_request_error;
		}
	}

	spin_lock_init(&dht22->lock);

	//6.保存设备结构体指针
	platform_set_drvdata(pdev, dht22);

	return 0;
gpio_request_error:
	while (i--) {
		gpio_free(dht22->gpio[i]);
	}
misc_error:
	kfree(dht22);
alloc_dev_error:
	return ret;
}

int dht22_remove(struct platform_device *pdev)
{
	struct dht22_st *dht22;
	int i;

	dht22 = platform_get_drvdata(pdev);

	for (i=0; i<dht22->num; i++) {
		gpio_free(dht22->gpio[i]);
	}

	misc_deregister(&dht22->misc);
	kfree(dht22);
	return 0;
}

void dht22_shutdown(struct platform_device *pdev)
{

}

int dht22_suspend(struct platform_device *pdev, pm_message_t state)
{
	return 0;
}

int dht22_resume(struct platform_device *pdev)
{
	return 0;
}

struct platform_device_id dht22_id_table[] = {
	{"dht11", 123},
	{"dht22", 123}, 
	{"dht33", 123},
	{},
};

struct platform_driver drv = {
	.probe = dht22_probe,
	.remove = dht22_remove,
	.suspend = dht22_suspend,
	.shutdown = dht22_shutdown,
	.resume = dht22_resume,
	.driver = {
		.name = "dht22",
	},
	.id_table = dht22_id_table,
};

static __init int dht22_drv_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void dht22_drv_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(dht22_drv_init);
module_exit(dht22_drv_exit);

MODULE_LICENSE("GPL");










