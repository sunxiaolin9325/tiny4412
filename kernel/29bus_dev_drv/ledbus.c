#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/device.h>
#include "bdd.h"

//当总线上注册新设备或者新驱动的时候调用
int led_match(struct device *dev, struct device_driver *drv)
{
	struct led_device *ldev;
	struct led_driver *ldrv;	

	ldev = container_of(dev, struct led_device, dev);
	ldrv = container_of(drv, struct led_driver, drv);

	return (ldev->id == ldrv->id);
}

struct led_bus ledbus = {
	.id = 0,
	.bus = {
		.name = "ledbus",
		.match = led_match,	
	},
};

EXPORT_SYMBOL(ledbus);

static __init int test_init(void)
{
	return bus_register(&ledbus.bus);
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	bus_unregister(&ledbus.bus);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










