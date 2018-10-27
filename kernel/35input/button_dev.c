#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/gpio.h>
#include <mach/gpio.h>

#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>
//#include <plat/irqs.h>	//不行

#include <linux/input.h>

//#include "button.h"

#define EXYNOS4_PA_BUTTON 0x11000000
#define EXYNOS4_SZ_BUTTON SZ_4K

#define GPX3DAT	0x0C64
#define EXYNOS4_NUM_BUTTON 4

struct platform_data_st {
        int num;
        char *info;
};


struct platform_data_st pds = {
	.num = EXYNOS4_NUM_BUTTON,
	.info = "From Button Dev",
};

struct resource my_res[] = {
	[0] = {
		.start = EXYNOS4_PA_BUTTON,
		.end = EXYNOS4_PA_BUTTON + EXYNOS4_SZ_BUTTON - 1,
		.name = "io",
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		//把硬件的中断号转为内核中的中断线,仅限于外部中断
		.start = IRQ_EINT(26),
		.end = IRQ_EINT(29),
		.name = "irq",
		.flags = IORESOURCE_IRQ,
	}
};

void  my_release(struct device *dev)
{
	printk("dev release\n");
}

struct platform_device dev = {
	.name = "my-button",
	.id = -1,
	.dev = {
		.platform_data = &pds,
		.release = my_release,
	},	
	.resource = my_res,		
	.num_resources = ARRAY_SIZE(my_res),
};

//当模块安装的时候执行
static __init int test_init(void)
{
	return platform_device_register(&dev);
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	platform_device_unregister(&dev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










