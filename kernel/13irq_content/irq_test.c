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

// GPX3 2 3 4 5
//EXYNOS4_GPX3(2)
int irq;

irqreturn_t button0_isr(int irq, void *data)
{
	char *v;

	printk("irq irq irq....\n");

	//中断不能睡眠,一睡内核就崩溃
	//ssleep(2);
	//v = kzalloc(0x1000000, GFP_KERNEL);
	//if (!v) {
	//	printk("zzzzzzzzzzzz\n");
	//}

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

	ssleep(2);

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








