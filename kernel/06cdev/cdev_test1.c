#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
// linux_src/include/linux/cdev.h
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
//每一个cdev至少要有一个设备号

//主设备号+次设备号=设备号
//同一类设备的主设备号是相同的


dev_t dev_no;

//当模块安装的时候执行
static __init int test_init(void)
{
	int ret;

	//dev_no = MKDEV(222, 2);
	//注册设备号
	//ret = register_chrdev_region(dev_no, 1, "my_dev");	
	ret = alloc_chrdev_region(&dev_no, 1, 1, "my_dev");
	if (ret < 0) {
		goto register_error;
	}

	return 0;
register_error:
	return ret;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	unregister_chrdev_region(dev_no, 1);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










