#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/slab.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>
#include <linux/delay.h>
#include <linux/poll.h>

#include "exynos4_adc.h"
//========硬件相关函数============
void exynos4_adc_init(struct adc_st *a)
{
	u32 tmp;

	a->adccon = (1 << 16) | (1 << 14) | (24 << 6);
	iowrite32(a->adccon, a->v + ADCCON);
	a->adcdly = 0xffff;
	iowrite32(a->adcdly, a->v + ADCDLY);
	
	tmp = ioread32(a->v_iesr + IESR2);
	tmp |= 1 << 19;
	iowrite32(tmp, a->v_iesr + IESR2);

	iowrite32(0, a->v + ADCMUX);
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

void exynos4_clrintadc(struct adc_st *a)
{
	iowrite32(1, a->v + CLRINTADC);
}

//==========硬件相关======================= 

//==========硬件无关======================= 
ssize_t adc_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct adc_st *a;
	struct adc_value_st avs;
	int ret;

	a = fp->private_data;

	if (count != sizeof(avs)) {
		return -EINVAL;
	}

	while (a->flag == NO_DATA) {
		//exynos4_adc_start(a);
		if (fp->f_flags & O_NONBLOCK) {
			return -EAGAIN;
		}
		ret = wait_event_interruptible(a->rq, a->flag == HAVE_DATA);
		if (ret < 0) {
			return -EINTR;
		}
	}	

	avs.value = a->value;	

	ret = copy_to_user(buffer, &avs, sizeof(avs));
	if (ret) {
		return -EFAULT;	
	}

	a->flag = NO_DATA;

	return count;
}

unsigned int adc_poll(struct file *fp, struct poll_table_struct *table)
{
	struct adc_st *a;
	unsigned int mask = 0;
	
	a = fp->private_data;

	poll_wait(fp, &a->rq, table);
	
	if (a->flag == HAVE_DATA) {
		mask |= POLLIN;
	}
	
	return mask;
}

int adc_open(struct inode *no, struct file *fp)
{
	struct adc_st *a;

	a = container_of(no->i_cdev, struct adc_st, dev);
	fp->private_data = a;

//	exynos4_adc_start(a);

	return 0;
}

int adc_close(struct inode *no, struct file *fp)
{
	return 0;
}

long adc_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	struct adc_st *a;
	
	a = fp->private_data;

	exynos4_adc_start(a);

	return 0;
}

irqreturn_t read_adc_handler(int irq, void *data)
{
	struct adc_st *a;

	a = data;

	a->value = exynos4_get_adc(a);

	a->flag = HAVE_DATA;
	
	wake_up(&a->rq);
	
	exynos4_clrintadc(a);
	
	return IRQ_HANDLED;
}

struct adc_st *adc;

static __init int test_init(void)
{
	int ret;

	adc = kzalloc(sizeof(*adc), GFP_KERNEL);
	if (!adc) {
		ret = -ENOMEM;
		goto alloc_adc_error;
	}

	adc->flag = NO_DATA;

	ret = alloc_chrdev_region(&adc->no, 1, 1, "new_adc");	
	if (ret) {
		goto alloc_no_error;
	}

	adc->adc_ops.open = adc_open;
	adc->adc_ops.release = adc_close;
	adc->adc_ops.read = adc_read;
	adc->adc_ops.poll = adc_poll;
	adc->adc_ops.unlocked_ioctl = adc_ioctl;
	
	cdev_init(&adc->dev, &adc->adc_ops);

	ret = cdev_add(&adc->dev, adc->no, 1);
	if (ret) {
		goto cdev_add_error;
	}

	init_waitqueue_head(&adc->rq);

	//arch/arm/mach-exynos/clock-exynos4.c
	//off
	adc->clk = clk_get(NULL, "adc");
	clk_enable(adc->clk);
	adc->clkphy = clk_get(NULL, "adcphy");
	clk_enable(adc->clkphy);
	adc->fsys_clk = clk_get(NULL, "fsys_adc");
	clk_enable(adc->fsys_clk);

	adc->v = ioremap(EXYNOS4_PA_ADC, EXYNOS4_SZ_ADC);
	if (!adc->v) {
		ret = -ENOMEM;
		goto remap_adc_error;
	}

	adc->v_iesr = ioremap(EXYNOS4_PA_IESR, EXYNOS4_SZ_IESR);
	if (!adc->v_iesr) {
		ret = -ENOMEM;
		goto remap_iesr_error;
	}
	//arch/arm/mach-exynos/include/mach/irqs.h
	adc->irq = IRQ_ADC;
	ret = request_irq(adc->irq, read_adc_handler, 0, "new_adc", adc);
	if (ret) {
		goto request_irq_error;
	}
	
	exynos4_adc_init(adc);
	
	return 0;
request_irq_error:
	iounmap(adc->v_iesr);	
remap_iesr_error:
	iounmap(adc->v);	
remap_adc_error:
	clk_disable(adc->clk);
	clk_disable(adc->clkphy);
	clk_disable(adc->fsys_clk);
	clk_put(adc->clk);
	clk_put(adc->clkphy);
	clk_put(adc->fsys_clk);
	cdev_del(&adc->dev);
cdev_add_error:
	unregister_chrdev_region(adc->no, 1);
alloc_no_error:
	kfree(adc);
alloc_adc_error:
	return ret;
}

static __exit void test_exit(void)
{
	exynos4_adc_exit(adc);
	free_irq(adc->irq, adc);
	iounmap(adc->v_iesr);	
	iounmap(adc->v);	
	clk_disable(adc->clk);
	clk_disable(adc->clkphy);
	clk_disable(adc->fsys_clk);
	clk_put(adc->clk);
	clk_put(adc->clkphy);
	clk_put(adc->fsys_clk);
	cdev_del(&adc->dev);
	unregister_chrdev_region(adc->no, 1);
	kfree(adc);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");






