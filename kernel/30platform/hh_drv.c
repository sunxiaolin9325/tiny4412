#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>

int my_probe(struct platform_device *pdev) 
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

int my_remove(struct platform_device *pdev)
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

void my_shutdown(struct platform_device *pdev)
{

	printk("[%s] %s\n", pdev->name, __FUNCTION__);
}

int my_suspend(struct platform_device *pdev, pm_message_t state)
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

int my_resume(struct platform_device *pdev)
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

struct platform_device_id id_table[] = {
	{"123", 123},
	{"456", 456},
	{"789", 789},
	{},
};

struct platform_driver drv = {
	.probe = my_probe,
	.remove = my_remove,
	.suspend = my_suspend,
	.resume = my_resume,
	.shutdown = my_shutdown,	
	.driver = {
		.name = "123",	
	},
	.id_table = id_table,
};

static __init int test_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void test_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










