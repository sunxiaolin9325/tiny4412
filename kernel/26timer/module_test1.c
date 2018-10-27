#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/interrupt.h>

struct timer_list timer;

void timer_handler(unsigned long data)
{
	printk("data = %lu\n", data);

	if (in_interrupt()) {
		printk("interrupt\n");
	} else {
		printk("process\n");
	}
	//timer.expires = jiffies + 2 * HZ;
	//add_timer(&timer);
	
	mod_timer(&timer, jiffies + 2 * HZ);
}

//当模块安装的时候执行
static __init int test_init(void)
{
	//1
	//init_timer(&timer);
	//timer.function = timer_handler;
	//timer.data = 123;
	//timer.expires = jiffies + 2 * HZ;
	//add_timer(&timer);

	//2
	//setup_timer(&timer, timer_handler, 456);
	//timer.expires = jiffies + 2 * HZ;
	//add_timer(&timer);

	//3
	setup_timer(&timer, timer_handler, 789);
	mod_timer(&timer, jiffies + 2 * HZ);			

	return 0;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	//1.smp
	//安全但可能会睡眠
	del_timer_sync(&timer);
	//2.
	//del_timer(&timer)
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










