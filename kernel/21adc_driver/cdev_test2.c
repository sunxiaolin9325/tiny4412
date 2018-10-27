#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/wait.h>
#include <linux/clk.h>
#include <asm/io.h>

#define ADC_BASE	0x126c0000

#define ADCCON 	  0x0000
#define ADCDLY 	  0x0008
#define ADCDAT 	  0x000C
#define CLRINTADC 0x0018

struct adc_value_st {
	int value;
};

struct adc_st {
	char buf[256];
	dev_t no;
	struct cdev dev;
	int count;

	void *__iomem v;

	struct clk *clk;
	struct clk *clkphy;
	struct clk *fsys_clk;

	u32 adccon, adcdly, adcdat, clrintadc;

	int irq;

	#define HAVE_DATA	0
	#define NO_DATA		1
	int flag;	

	spinlock_t lock;

	wait_queue_head_t rq, wq;
};

void exynos4_adc_init(struct adc_st *a)
{
	a->adccon = (1 << 16) | (1 << 14) | (24 << 6);
	iowrite32(a->adccon, a->v + ADCCON);
	a->adcdly = 0xffff;
	iowrite32(a->adcdly, a->v + ADCDLY);
}

void exynos4_adc_exit(struct adc_st *a)
{

}

void exynos4_adc_start(struct adc_st *a)
{
	a->adccon = ioread32(a->v + ADCCON);
	a->adccon |= 1;
	iowrite32(a->adccon, a->v + ADCCON);
}

void exynos4_wait_for_adc(struct adc_st *a)
{
	while (!(ioread32(a->v + ADCCON) & (1 << 15)));
}

int exynos4_get_adc(struct adc_st *a)
{
	return ioread32(a->v + ADCDAT) & 0xfff;	
}

// /dev/test/mydev
int adc_open(struct inode *no, struct file *fp)
{
	struct adc_st *m;

	m = container_of(no->i_cdev, struct adc_st, dev);
	memset(m->buf, 0, 256);
	fp->private_data = m;

	spin_lock(&m->lock);
	//if (m->count) {
	//	spin_unlock(&m->lock);
	//	return -EBUSY;
	//}
	//m->count = 1;
	m->count++;
	spin_unlock(&m->lock);

	return 0;
}

int adc_close(struct inode *no, struct file *fp)
{
	struct adc_st *m;

	m = container_of(no->i_cdev, struct adc_st, dev);
	spin_lock(&m->lock);
	//if (!m->count) {
	//	spin_unlock(&m->lock);
	//	return -ENODEV;
	//}
	//m->count = 0;
	m->count--;
	spin_unlock(&m->lock);

	return 0;
}

// open("/dev/test/mydev", O_RDWR | O_NONBLOCK);
// open("/dev/test/mydev", O_RDWR);
ssize_t adc_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
/*
	while (m->flag == NO_DATA) {
		if (fp->f_flags & O_NONBLOCK) {
			//非阻塞访问
			return -EAGAIN;
		} else {
			//阻塞访问
			//进程睡眠
		//	wait_event(m->rq, m->flag == HAVE_DATA);	
			ret = wait_event_interruptible(m->rq, m->flag == HAVE_DATA);	
			if (ret < 0) {
				return -EINTR;
			}
		}
	}

	count = min((int)count, 10);	
	
	ret = copy_to_user(buffer, m->buf, count);
	if (ret) {
		ret = -EFAULT;	
		goto copy_error;
	}

	m->flag = NO_DATA;

	return count;
copy_error:
	return ret;
*/
	struct adc_st *m;
	int ret;
	struct adc_value_st avs;

	m = fp->private_data;
	if (count != sizeof(avs)) {
		return -EINVAL;
	}
	exynos4_adc_start(m);
	exynos4_wait_for_adc(m);
	avs.value = exynos4_get_adc(m);	
	ret = copy_to_user(buffer, &avs, sizeof(avs));
	if (ret) {
		return -EFAULT;

	}

	return count;
}


struct file_operations adc_ops = {
	.open = adc_open,
	.release = adc_close,
	.read = adc_read,
};

irqreturn_t read_sensor(int irq, void *data)
{
/*
	//如果读传感器的操作有可能睡眠的话，这里需要使用中断下半部分（工作队列）
	
	struct mydev_st *m;
	static int a = 0;

	m = data;
	
	//把传感器的数据读到设备的缓存中
	sprintf(m->buf, "%010d", a++);	

	m->flag = HAVE_DATA;

	wake_up(&m->rq);
	
*/
	return IRQ_HANDLED;
}

struct adc_st *adc;

//当模块安装的时候执行
static __init int test_init(void)
{
	int ret;
	
	adc = kzalloc(sizeof(*adc), GFP_KERNEL);
	if (!adc) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	adc->flag = NO_DATA;

	ret = alloc_chrdev_region(&adc->no, 1, 1, "myadc");
	if (ret < 0) {
		goto alloc_no_error;
	}

	cdev_init(&adc->dev, &adc_ops);
	ret = cdev_add(&adc->dev, adc->no, 1);
	if (ret < 0) {
		goto cdev_add_error;
	}
	
	spin_lock_init(&adc->lock);

	init_waitqueue_head(&adc->rq);

	adc->clk = clk_get(NULL, "adc");
	clk_enable(adc->clk);
	adc->clkphy = clk_get(NULL, "adcphy");
	clk_enable(adc->clkphy);
	adc->fsys_clk = clk_get(NULL, "fsys_adc");
	clk_enable(adc->fsys_clk);

	adc->v = ioremap(ADC_BASE, SZ_4K);
	if (!adc->v) {
		ret = -ENOMEM;
		goto remap_adc_error;
	}

	exynos4_adc_init(adc);
	
	//adc->irq = IRQ_ADC;
	//ret = request_irq(adc->irq, read_sensor, 0, "myadc", adc);
	//if (ret) {
	//	goto request_irq_error;
	//}

	printk("major=%d minor=%d\n", MAJOR(adc->no), MINOR(adc->no));
	
	return 0;
remap_adc_error:
	clk_disable(adc->fsys_clk);
	clk_disable(adc->clkphy);
	clk_disable(adc->clk);
	clk_put(adc->fsys_clk);
	clk_put(adc->clkphy);
	clk_put(adc->clk);
//request_irq_error:
	cdev_del(&adc->dev);
cdev_add_error:
	unregister_chrdev_region(adc->no, 1);
alloc_no_error:
	kfree(adc);
alloc_dev_error:
	return ret;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	exynos4_adc_exit(adc);
	iounmap(adc->v);
	clk_disable(adc->fsys_clk);
	clk_disable(adc->clkphy);
	clk_disable(adc->clk);
	clk_put(adc->fsys_clk);
	clk_put(adc->clkphy);
	clk_put(adc->clk);
	//free_irq(adc->irq, adc);
	cdev_del(&adc->dev);
	unregister_chrdev_region(adc->no, 1);
	kfree(adc);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










