#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

//中断上下文 不允许睡眠
//进程上下文

/*
page
page
page
page
page
*/

static __init int test_init(void)
{
	char *v;

	//task_struct 
	printk("process:%s\n", current->comm);
	
	//物理和虚拟都连续
	//v = kmalloc(100, GFP_KERNEL);
	v = kzalloc(100, GFP_KERNEL);
	memcpy(v, "123", 3);
	kfree(v);

	//只能保证在虚拟上连续
	//这个函数有可能睡眠
	//v = vmalloc(100);
	v = vzalloc(100);
	memcpy(v, "123", 3);
	vfree(v);
				
	return 0;
}


static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
