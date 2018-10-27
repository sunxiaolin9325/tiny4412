#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/delay.h>

//当模块安装的时候执行
static __init int test_init(void)
{
	printk("test_init\n");
	//模拟一段需要执行事件很长的代码
	
	while (1);
	//关闭内核抢占
	//preempt_disable();
	//mdelay(5000);
	//打开内核抢占
	//preempt_enable();

	return 0;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	printk("test_exit\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










