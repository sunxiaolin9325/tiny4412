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
	printk("irq irq irq....\n");
	return IRQ_HANDLED;	
	//IRQ_NONE;
}

void nihao(void)
{
	unsigned long flag;
	mdelay(2);
	//有一段代码不能被中断打断
	//local_irq_disable();
	//先保存中断状态，然后在禁止中断
	local_irq_save(flag);
	mdelay(2000);
	//恢复中断状态
	local_irq_restore(flag);
	//local_irq_enable();
}

static __init int test_init(void)
{
	int ret;
	unsigned long flag;

	irq = gpio_to_irq(EXYNOS4_GPX3(2));	
	//proc/interrupts
	ret = request_irq(irq, button0_isr, IRQF_TRIGGER_FALLING | IRQF_SAMPLE_RANDOM | IRQF_DISABLED, "my_irq", NULL);
	if (ret) {
		return ret;
	}

	//local_irq_disable();
	local_irq_save(flag);
	nihao();
	//假设在这里有一段不能被中断打断的代码
	mdelay(5000);	
	local_irq_restore(flag);
	//local_irq_enable();
	
	return 0;
}

static __exit void test_exit(void)
{
	free_irq(irq, NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");








