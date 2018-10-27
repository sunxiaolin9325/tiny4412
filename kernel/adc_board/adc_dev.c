#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
//#include "exynos4_adc.h"
#define EXYNOS4_PA_ADC  0x126C0000
#define EXYNOS4_SZ_ADC  SZ_4K

#define ADCCON          0x0000
#define ADCDLY          0x0008
#define ADCDAT          0x000C 
#define CLRINTADC       0x0018 
#define ADCMUX          0x001C

#define EXYNOS4_PA_IESR 0x10440000 
#define EXYNOS4_SZ_IESR SZ_4K
//使能中断
#define IESR2           0x0020
//用于清除ADC集线器中的中断
#define IESC2           0x0024


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


struct platform_device my_adc_dev = {
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
	return platform_device_register(&my_adc_dev);
}

static __exit void adc_dev_exit(void)
{
	platform_device_unregister(&my_adc_dev);
}

module_init(adc_dev_init);
module_exit(adc_dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LIN");
