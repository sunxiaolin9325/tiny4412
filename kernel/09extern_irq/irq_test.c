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

#include <linux/interrupt.h>	//request_irq
#include <linux/gpio.h>	//gpio_to_irq
#include <mach/gpio.h>	//提供GPIO号

// GPX3 2 3 4 5
//EXYNOS4_GPX3(2)
int irq;

irqreturn_t button0_isr(int irq, void *data)
{
	printk("irq irq irq....\n");
	return IRQ_HANDLED;	
	//IRQ_NONE;
}

static __init int test_init(void)
{
	int ret;

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








