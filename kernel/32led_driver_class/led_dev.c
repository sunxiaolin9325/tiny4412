#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/platform_device.h>

#include "led.h"

void led_release(struct device *dev)
{

}

struct led_info_st {
	int num;
	char *name;
};

struct led_info_st lis = {
	.num = 4,
	.name = "rgb",
};

struct resource led_res[] = {
	[0] = {
		.start = 1,
		.end = 2,
		.name = "nihao",
		.flags = IORESOURCE_IRQ,
	},
	[1] = {
		.start = EXYNOS4_PA_LED,
		.end = EXYNOS4_PA_LED + EXYNOS4_SZ_LED - 1,
		.name = "led_reg",
		.flags = IORESOURCE_MEM,
	},
};

struct platform_device dev = {
	.name = "myled",
	.id = -1,
	.dev = {
		.platform_data = &lis,
		.release = led_release,
	},	
	.resource = led_res,
	.num_resources = ARRAY_SIZE(led_res),
};

static __init int led_test_init(void)
{
	return platform_device_register(&dev);
}

static __exit void led_test_exit(void)
{
	platform_device_unregister(&dev);
}

module_init(led_test_init);
module_exit(led_test_exit);

MODULE_LICENSE("GPL");


