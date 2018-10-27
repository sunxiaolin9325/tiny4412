#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>//ioremap
#include <linux/platform_device.h>

#include "led.h"

//====硬件相关=====================
void exynos4_led_init(struct led_st *l)
{
	//ioread32 ioread16 ioread8
		    //readb
		    //readw
	l->ledcon = readl(l->v + 0x2e0);
	l->ledcon &= ~0xffff;
	l->ledcon |= 0x1111;
	writel(l->ledcon, l->v + 0x2e0);

	l->leddat = readl(l->v + 0x2e4);
	l->leddat |= 0xf;
	writel(l->leddat, l->v + 0x2e4);
}

void exynos4_led_exit(struct led_st *l)
{
	l->leddat = readl(l->v + 0x2e4);
	l->leddat |= 0xf;
	writel(l->leddat, l->v + 0x2e4);
}

void exynos4_led_on(struct led_st *l, int no)
{
	if (no > 3 && no < 0) {
		return;
	}
	l->leddat = readl(l->v + 0x2e4);
	l->leddat &= ~(1 << no);
	writel(l->leddat, l->v + 0x2e4);
}

void exynos4_led_off(struct led_st *l, int no)
{
	if (no > 3 && no < 0) {
		return;
	}
	l->leddat = readl(l->v + 0x2e4);
	l->leddat |= (1 << no);
	writel(l->leddat, l->v + 0x2e4);
}

//====硬件无关=====================
// /dev/test/led
int led_open(struct inode *no, struct file *fp)
{
	struct led_st *m;

	m = container_of(no->i_cdev, struct led_st, dev);
	fp->private_data = m;

	//加锁
	if (m->count) {
		//解锁
		return -EBUSY;
	}
	m->count = 1;
	//解锁
	return 0;
}

int led_close(struct inode *no, struct file *fp)
{
	struct led_st *m;

	m = container_of(no->i_cdev, struct led_st, dev);
	//加锁
	if (!m->count) {
		//解锁
		return -ENODEV;	
	}
	m->count = 0;
	//解锁

	return 0;
}

ssize_t led_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct led_st *m;
	struct led_pro_st lps;
	int ret;

	if (count != sizeof(lps)) {
		return -EINVAL;
	}

	m = fp->private_data;

	lps.status = m->status;

	ret = copy_to_user(buffer, &lps, sizeof(lps));
	if (ret) {
		return -EFAULT;
	}

	return count;
}

ssize_t led_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	int ret;

	struct led_st *m;
	struct led_pro_st lps;

	m = fp->private_data;
	
	if (count != sizeof(lps)) {
		return -EINVAL;
	}

	ret = copy_from_user(&lps, buffer, sizeof(lps));
	if (ret) {
		return -EFAULT;
	}

	if (lps.light) {
		m->on(m, lps.led_no);
		m->status |= 1 << lps.led_no;
	} else {
		m->off(m, lps.led_no);
		m->status &= ~(1 << lps.led_no);
	}

	return count;
}
//cmd : 0 all led on
//cmd : 1 all led off
long led_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	struct led_st *l;

	l = fp->private_data;

	switch (cmd) {
		case 0:
			l->on(l, 0);
			l->on(l, 1);
			l->on(l, 2);
			l->on(l, 3);
			break;
		case 1:
		default:	
			l->off(l, 0);
			l->off(l, 1);
			l->off(l, 2);
			l->off(l, 3);
			break;
	}

	return 0;
}

struct file_operations led_ops = {
	.open = led_open,
	.release = led_close,
	.write = led_write,
	.read = led_read,
	.unlocked_ioctl = led_ioctl,
};

//设备模型
int led_probe(struct platform_device *pdev)
{
	int ret;
	struct led_st *led;
	struct resource *led_res;
	//注意：0代表IORESOURCE_MEM类型资源的第0个
	//1.获得资源	
//////////////////
	led_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!led_res) {
		return -EBUSY;
	}

	//2.分配设备结构体
	led = kzalloc(sizeof(*led), GFP_KERNEL);
	if (!led) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}
	
	//3.字符设备
	ret = alloc_chrdev_region(&led->no, 1, 1, "led");
	if (ret < 0) {
		goto alloc_no_error;
	}

	cdev_init(&led->dev, &led_ops);
	ret = cdev_add(&led->dev, led->no, 1);
	if (ret < 0) {
		goto cdev_add_error;
	}

	printk("major=%d minor=%d\n", MAJOR(led->no), MINOR(led->no));

	//GPM4 0,1,2,3
	//GPM4CON  0x2e0
	//GPM4DAT  0x2e4
	//led->v+0xaaa--->0x11000aaa
	//led->v+0x2e4--->0x110002e4
	//led->v+0x2e0--->0x110002e0
	//4.映射地址
////////////////////
	led->v = ioremap(led_res->start, led_res->end - led_res->start + 1);
	if (!led->v) {
		ret = -ENOMEM;
		goto ioremap_error;
	}

	led->on = exynos4_led_on;
	led->off = exynos4_led_off;
	
	//5.初始化硬件
	exynos4_led_init(led);
/////////////////////////
	//6.保存设备结构体指针
	platform_set_drvdata(pdev, led);
	
	return 0;
ioremap_error:
	cdev_del(&led->dev);
cdev_add_error:
	unregister_chrdev_region(led->no, 1);
alloc_no_error:
	kfree(led);
alloc_dev_error:
	return ret;
}

int led_remove(struct platform_device *pdev)
{
	struct led_st *led;

/////////////////////
	led = platform_get_drvdata(pdev);
	
	exynos4_led_exit(led);
	iounmap(led->v);
	cdev_del(&led->dev);
	unregister_chrdev_region(led->no, 1);
	kfree(led);
	return 0;
}

void led_shutdown(struct platform_device *pdev)
{
	
}

int led_suspend(struct platform_device *pdev, pm_message_t state)
{
	return 0;
}

int led_resume(struct platform_device *pdev)
{
	return 0;
}

struct platform_device_id led_id_table[] = {
	{"myled", 123}, 
	{"yourled", 123},
	{"herled", 123},
	{},
};

struct platform_driver drv = {
	.probe = led_probe,
	.remove = led_remove,
	.suspend = led_suspend,
	.shutdown = led_shutdown,
	.resume = led_resume,
	.driver = {
		//如果没有id_table,会使用name唯一匹配
		.name = "myled",
	},
	.id_table = led_id_table,
};

static __init int led_test_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void led_test_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(led_test_init);
module_exit(led_test_exit);

MODULE_LICENSE("GPL");










