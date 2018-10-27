#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/clk.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/spinlock.h>

#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <mach/gpio.h>
#include <linux/delay.h>

struct tasklet_struct ts, ts1;

// GPX3 2 3 4 5
//EXYNOS4_GPX3(2)
int irq;

void tasklet_isr1(unsigned long data)
{
	if (in_interrupt()) {
		printk("%s in interrupt content %ld\n", __FUNCTION__, data);	
	} else {
		printk("%s in process content %ld\n", __FUNCTION__, data);	
	}
}

void tasklet_isr(unsigned long data)
{
	if (in_interrupt()) {
		printk("%s in interrupt content %ld\n", __FUNCTION__, data);	
	} else {
		printk("%s in process content %ld\n", __FUNCTION__, data);	
	}
}

void irq_bh(struct softirq_action *action)
{
	if (in_interrupt()) {
		printk("%s in interrupt content\n", __FUNCTION__);	
	} else {
		printk("%s in process content\n", __FUNCTION__);	
	}
}

irqreturn_t button0_isr(int irq, void *data)
{
	printk("irq irq irq....\n");

	//需要立即处理的在中断处理函数中执行
	//硬件相关
	
	//可以延迟执行的都放到中断下半部分
	open_softirq(MY_SOFTIRQ, irq_bh);
	raise_softirq(MY_SOFTIRQ);

	tasklet_schedule(&ts);	
	tasklet_hi_schedule(&ts1);	

	if (in_interrupt()) {
		printk("%s in interrupt content\n", __FUNCTION__);	
	} else {
		printk("%s in process content\n", __FUNCTION__);	
	}

	return IRQ_HANDLED;	
	//IRQ_NONE;
}

static __init int test_init(void)
{
	int ret;

	tasklet_init(&ts, tasklet_isr, 123);
	tasklet_init(&ts1, tasklet_isr1, 123);	
	if (in_interrupt()) {
		printk("%s in interrupt content\n", __FUNCTION__);	
	} else {
		printk("%s in process content\n", __FUNCTION__);	
	}

	irq = gpio_to_irq(EXYNOS4_GPX3(2));	
	//proc/interrupts
	ret = request_irq(irq, button0_isr, IRQF_TRIGGER_FALLING | IRQF_SAMPLE_RANDOM | IRQF_DISABLED, "my_irq", NULL);
	if (ret) {
		return ret;
	}

	return 0;
}

static __exit void test_exit(void)
{
	free_irq(irq, NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");








