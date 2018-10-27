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
#include <linux/workqueue.h>

struct tasklet_struct ts, ts1;
struct work_struct work;
struct delayed_work dwork;

struct workqueue_struct *wq;

// GPX3 2 3 4 5
//EXYNOS4_GPX3(2)
int irq;

void work_handler(struct work_struct *work)
{
	if (in_interrupt()) {
		printk("%s in interrupt content %d\n", __FUNCTION__, 123);	
	} else {
		printk("%s in process content %d\n", __FUNCTION__, 123);	
	}
}

void dwork_handler(struct work_struct *work)
{
	if (in_interrupt()) {
		printk("%s in interrupt content %d\n", __FUNCTION__, 123);	
	} else {
		printk("%s in process content %d\n", __FUNCTION__, 123);	
	}
}

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

	//schedule_work(&work);
	//schedule_delayed_work(&dwork, HZ * 3);	
	//把任务添加到自己创建的队列
	queue_work(wq, &work);
	//queue_delayed_work始终在queue_work之后执行?
	queue_delayed_work(wq, &dwork, HZ * 2);

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
	INIT_WORK(&work, work_handler);
	INIT_DELAYED_WORK(&dwork, dwork_handler);

	//创建队列
	wq = create_workqueue("myqueue");
	
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
	//以睡眠的方式等待所有任务完成
	flush_workqueue(wq);
	//销毁队列
	destroy_workqueue(wq);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");








