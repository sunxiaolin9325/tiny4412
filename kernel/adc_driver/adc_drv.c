#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/cdev.h>
#include <linux/kdev_t.h>

#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

#include <linux/spinlock.h>

#include <linux/gpio.h>
#include <linux/interrupt.h>

#include <linux/poll.h>

#include <linux/io.h>
#include <linux/clk.h>

#include "exynos4_adc.h"
#include <linux/platform_device.h>
#include <linux/miscdevice.h>

void exynos4_adc_init(struct adc_st *a)
{
	a->adccon = (1 << 16) | (1 << 14) | (24 << 6);
	writel(a->adccon, a->v + ADCCON);

	a->adcdly = 0xffff;
	writel(a->adcdly, a->v + ADCDLY);

	writel(0, a->v + ADCMUX);

	a->iesr2 = readl(a->v_iesr + IESR2);
	a->iesr2 |= (1 << 19);
	writel(a->iesr2, a->v_iesr + IESR2);
}

void exynos4_adc_exit(struct adc_st *a)
{
}

void exynos4_adc_start(struct adc_st *a)
{
	a->adccon = readl(a->v + ADCCON);
	a->adccon |= (1 << 0);
	writel(a->adccon, a->v + ADCCON);
}

int exynos4_get_adc(struct adc_st *a)
{
	return readl(a->v + ADCDAT) & 0xfff;
}

void exynos4_adc_clrint(struct adc_st *a)
{
	writel(1, a->v + CLRINTADC);
}

//硬件无关
int adc_open(struct inode *no, struct file *fp)
{
	struct adc_st *a;

	a = container_of(fp->f_op, struct adc_st, adc_ops);
	fp->private_data = a;

	spin_lock(&a->lock);
	if (a->count) {
		spin_unlock(&a->lock);
		return -EBUSY;
	}

	a->count++;
	spin_unlock(&a->lock);

	return 0;
}

int adc_close(struct inode *no, struct file *fp)
{
	struct adc_st *a;
	
	a = fp->private_data;

	spin_lock(&a->lock);
	if (!a->count) {
		spin_unlock(&a->lock);
		return -ENODEV;
	}

	a->count--;
	spin_unlock(&a->lock);

	return 0;
}

ssize_t adc_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct adc_st *a;
	struct adc_pro_st aps;
	int ret;

	if (count != sizeof(aps)) {
		return -EINVAL;
	}

	a = fp->private_data;
	while (a->flag == NO_DATA) {
		if (fp->f_flags & O_NONBLOCK) {
			//非阻塞访问
			return -EAGAIN;
		} else {
			//阻塞访问
			//进程睡眠
			ret = wait_event_interruptible(a->rq, a->flag == HAVE_DATA);        
			if (ret < 0) {
				return -EINTR;
			}
		}
	}

	aps.value = a->value;
	ret = copy_to_user(buffer, &aps, count);
	if (ret) {
		return -EFAULT;
	}

	a->flag = NO_DATA;

	return count;
}

long adc_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	struct adc_st *a;

	a = fp->private_data;

	exynos4_adc_start(a);
	
	return 0;
}

unsigned int adc_poll(struct file *fp, struct poll_table_struct *table)
{
	struct adc_st *m;
	static int mask = 0;

	m = fp->private_data;
	poll_wait(fp, &m->rq, table);
	if (m->flag == HAVE_DATA) {
		mask |= POLLIN;
	} else {
		//...
	}
	
	return mask;
}

irqreturn_t read_adc_handler(int irq, void *data)
{
	struct adc_st *a;

	a = data;
	a->value = exynos4_get_adc(a);

	a->flag = HAVE_DATA;
	wake_up(&a->rq);

	exynos4_adc_clrint(a);

	return IRQ_HANDLED;
}

int adc_probe(struct platform_device *pdev)
{
	int ret;
	struct adc_st *adc;
	struct resource *adc_res;
	struct resource *iesr_res;

	//1
	adc_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!adc_res) {
		return -EBUSY;
	}
	
	iesr_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (!iesr_res) {
		return -EBUSY;
	}
	
	//2
	adc = kzalloc(sizeof(*adc), GFP_KERNEL);
	if (!adc) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	//3
	adc->v = ioremap(adc_res->start, adc_res->end - adc_res->start + 1);
	if (!adc->v) {
		ret = -ENOMEM;
		goto ioremap_adc_error;
	}

	adc->v_iesr = ioremap(iesr_res->start, iesr_res->end - iesr_res->start + 1);
	if (!adc->v_iesr) {
		ret = -ENOMEM;
		goto ioremap_iesr_error;
	}

	//4
	adc->adc_ops.open = adc_open;
	adc->adc_ops.release = adc_close;
	adc->adc_ops.read = adc_read;
	adc->adc_ops.unlocked_ioctl = adc_ioctl;
	adc->adc_ops.poll = adc_poll;

	adc->misc.minor = MISC_DYNAMIC_MINOR;
	adc->misc.name = pdev->name;
	adc->misc.fops = &adc->adc_ops;

	ret = misc_register(&adc->misc);
	if (ret) {
		goto misc_error;
	}

	//5
	adc->flag = NO_DATA;
	spin_lock_init(&adc->lock);
	init_waitqueue_head(&adc->rq);

	adc->irq = IRQ_ADC;
	ret = request_irq(adc->irq, read_adc_handler, 0, "myadc", adc);
	if (ret) {
		goto request_irq_error;
	}

	adc->clk_adc = clk_get(NULL, "adc");
	clk_enable(adc->clk_adc);
	adc->clk_adcphy = clk_get(NULL, "adcphy");
	clk_enable(adc->clk_adcphy);
	adc->clk_fsys_adc = clk_get(NULL, "fsys_adc");
	clk_enable(adc->clk_fsys_adc);

	exynos4_adc_init(adc);

	//6
	platform_set_drvdata(pdev, adc);

	return 0;

request_irq_error:
	misc_deregister(&adc->misc);
misc_error:
	iounmap(adc->v_iesr);
ioremap_iesr_error:
	iounmap(adc->v);
ioremap_adc_error:
	kfree(adc);
alloc_dev_error:
	return ret;
}

int adc_remove(struct platform_device *pdev)
{
	struct adc_st *adc;

	adc = platform_get_drvdata(pdev);

	exynos4_adc_exit(adc);

	clk_disable(adc->clk_fsys_adc);
	clk_put(adc->clk_fsys_adc);
	clk_disable(adc->clk_adcphy);
	clk_put(adc->clk_adcphy);
	clk_disable(adc->clk_adc);
	clk_put(adc->clk_adc);

	free_irq(adc->irq, adc);
	misc_deregister(&adc->misc);
	iounmap(adc->v_iesr);
	iounmap(adc->v);
	kfree(adc);

	return 0;
}

struct platform_device_id adc_id_table[] = {
	{"myadc", 0},
	{"xxxxx", 0},
	{"yyyyy", 0},
	{},
};


struct platform_driver drv = {
	.probe = adc_probe,
	.remove = adc_remove,
	.driver = {
		.name = "myadc"
	},
	.id_table = adc_id_table,
};

static __init int adc_drv_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void adc_drv_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(adc_drv_init);
module_exit(adc_drv_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LIN");




