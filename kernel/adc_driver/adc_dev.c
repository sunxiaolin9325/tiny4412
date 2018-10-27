#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
#include "exynos4_adc.h"

struct resource adc_res[] = {
	[0] = {
		.start = EXYNOS4_PA_ADC,
		.end = EXYNOS4_PA_ADC + EXYNOS4_SZ_ADC - 1,
		.name = "adc",
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = EXYNOS4_PA_IESR,
		.end = EXYNOS4_PA_IESR + EXYNOS4_SZ_IESR - 1,
		.name = "iesr",
		.flags = IORESOURCE_MEM,
	},
};

void adc_release(struct device *dev)
{
	printk("adc_dev_release\n");
}


struct platform_device dev = {
	.name = "myadc",
	.id = -1,
	.dev = {
		.release = adc_release,	
	},
	.num_resources = ARRAY_SIZE(adc_res),
	.resource = adc_res,
};

static __init int adc_dev_init(void)
{
	return platform_device_register(&dev);
}

static __exit void adc_dev_exit(void)
{
	platform_device_unregister(&dev);
}

module_init(adc_dev_init);
module_exit(adc_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LIN");
