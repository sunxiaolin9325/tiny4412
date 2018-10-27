#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/hrtimer.h>

struct hrtimer timer;

enum hrtimer_restart function(struct hrtimer *t)
{
	printk("time end\n");
	return HRTIMER_NORESTART;
}

static __init int test_init(void)
{
	ktime_t t = ktime_set(1483617398 + 24 * 60 * 60, 0);
	//			实时时钟	绝对	
	hrtimer_init(&timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);	
	timer.function = function;
	hrtimer_start(&timer, t, HRTIMER_MODE_ABS);

	return 0;
}

static __exit void test_exit(void)
{
	hrtimer_cancel(&timer);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










