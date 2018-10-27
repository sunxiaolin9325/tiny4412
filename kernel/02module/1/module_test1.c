#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

//当模块安装的时候执行
static __init int test_init(void)
{
	printk("test_init\n");
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










