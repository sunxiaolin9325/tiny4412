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

//共享中断号(线)
// GPX3 2 3 4 5
//EXYNOS4_GPX3(2)
int irq;

irqreturn_t button0_isr(int irq, void *data)
{
	printk("irq irq irq.... %x\n", data);
	return IRQ_HANDLED;	
	//IRQ_NONE;
}

irqreturn_t button0_isr1(int irq, void *data)
{
	printk("irq1 irq1 irq1...%x\n", data);
	return IRQ_HANDLED;	
	//IRQ_NONE;
}

static __init int test_init(void)
{
	int ret;

	irq = gpio_to_irq(EXYNOS4_GPX3(2));	
	//proc/interrupts
	ret = request_irq(irq, button0_isr, IRQF_TRIGGER_FALLING | IRQF_SAMPLE_RANDOM | IRQF_DISABLED | IRQF_SHARED, "my_irq", (void *)123);
	if (ret) {
		return ret;
	}
	ret = request_irq(irq, button0_isr1, IRQF_TRIGGER_FALLING | IRQF_SAMPLE_RANDOM | IRQF_DISABLED | IRQF_SHARED, "my_irq1", (void *)456);
	if (ret) {
		free_irq(irq, NULL);
		return ret;
	}

	return 0;
}

static __exit void test_exit(void)
{
	free_irq(irq, (void *)456);
	free_irq(irq, (void *)123);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");








