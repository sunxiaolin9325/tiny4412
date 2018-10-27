#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
#include <mach/gpio.h>	//EXYNOS4_GPX1(_nr)
#include "dht22.h"

void dht22_release(struct device *dev)
{

}

struct dht22_info_st info = {
	.num = 6,
	.name = "dht22",
};

//三星IO库资源
struct resource dht22_res[] = {
	[0] = {
		.start = EXYNOS4_GPB(4),
		.end = EXYNOS4_GPB(4) + 4 - 1, 
		.name = "GPIO5~GPIO8",
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = EXYNOS4_GPX1(0),
		.end = EXYNOS4_GPX1(0),
		.name = "GPIO9",
		.flags = IORESOURCE_MEM,
	},
	[2] = {
		.start = EXYNOS4_GPX1(7),
		.end = EXYNOS4_GPX1(7),
		.name = "GPIO10",
		.flags = IORESOURCE_MEM,
	},
};

struct platform_device dht22_dev = {
	//用于匹配驱动的设备名
	.name = "dht22",
	.id = -1,
	.dev = {
		.platform_data = &info,
		.release = dht22_release,
	},	
	.resource = dht22_res,
	.num_resources = ARRAY_SIZE(dht22_res),
};

MODULE_LICENSE("GPL");


