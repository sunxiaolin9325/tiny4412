#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/device.h>

#include "bdd.h"

extern struct led_bus ledbus;

//当设备注销的时候调用
void led_release(struct device *dev)
{
	printk("blue led unregister\n");
}

struct led_device blue = {
	.id = BLUE,
	.dev = {
		.init_name = "bluedev",
		.bus = &ledbus.bus,
		.release = led_release,
	},
};

static __init int test_init(void)
{
	return device_register(&blue.dev);
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	device_unregister(&blue.dev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










