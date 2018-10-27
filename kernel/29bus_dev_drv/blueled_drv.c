#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/device.h>
#include "bdd.h"

extern struct led_bus ledbus;

//当某个设备和当前驱动匹配成功后调用
int led_probe(struct device *dev)
{
	struct led_device *ldev;

	ldev = container_of(dev, struct led_device, dev);

	switch (ldev->id) {
		case RED:
			printk("red match me\n");
			break;
		case GREEN:
			printk("green match me\n");
			break;
		case BLUE:
			printk("blue match me\n");
			break;
		default:
			break;
	}

	return 0;
}

//和当前驱动匹配成功的设备注销或者当前驱动注销的时候调用
int led_remove(struct device *dev)
{
	struct led_device *ldev;

	ldev = container_of(dev, struct led_device, dev);

	switch (ldev->id) {
		case RED:
			printk("red leave me\n");
			break;
		case GREEN:
			printk("green leave me\n");
			break;
		case BLUE:
			printk("blue leave me\n");
			break;
		default:
			break;
	}

	return 0;
}

struct led_driver red = {
	.id = BLUE,
	.drv = {
		.name = "bluedrv",
		.bus = &ledbus.bus,
		.probe = led_probe,
		.remove = led_remove,	
	}
};

static __init int test_init(void)
{
	return driver_register(&red.drv);
}

static __exit void test_exit(void)
{
	driver_unregister(&red.drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










