//注意：这个文件要编译到内核中
//cp led_dev.c /var/ftp/opt/linux-3.5/arch/arm/mach-exynos/exynos4_led_dev.c

#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

#define EXYNOS4_PA_LED	0x11000000
#define EXYNOS4_SZ_LED	SZ_4K

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

struct platform_device exynos4_myled_dev = {
	.name = "exynos4-led",
	.id = -1,
	.dev = {
		.platform_data = &lis,
		.release = led_release,
	},	
	.resource = led_res,
	.num_resources = ARRAY_SIZE(led_res),
};

MODULE_LICENSE("GPL");


