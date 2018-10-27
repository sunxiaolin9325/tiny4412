#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/hrtimer.h>

struct hrtimer timer;

//enum hrtimer_restart function(struct hrtimer *t)
//{
//	printk("timer timer\n");
//
//	return HRTIMER_NORESTART;
//}

enum hrtimer_restart function(struct hrtimer *t)
{
	ktime_t tt = ktime_set(3, 3000000);

	printk("timer timer\n");

	hrtimer_forward_now(t, tt);	

	return HRTIMER_RESTART;
}

static __init int test_init(void)
{
	ktime_t t;
	//                   单调递增	  相对relative
	hrtimer_init(&timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);	
	t = ktime_set(2, 2000000);
	timer.function = function;
	hrtimer_start(&timer, t, HRTIMER_MODE_REL);

	return 0;
}

static __exit void test_exit(void)
{
	hrtimer_cancel(&timer);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










