#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>

struct platform_data_st {
	int id;
	char *info;
};

struct platform_data_st pds = {
	.id = 0,
	.info = "platform data",
};

struct resource my_res[] = {
	[0] = {
		.start = 0x11000000,
		.end = 0x11000000 + 0x1000,
		.name = "led_regs",
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = IRQ_ADC,
		.end = IRQ_ADC + 10,
		.name = "haha",
		.flags = IORESOURCE_IRQ,
	}
};

void  my_release(struct device *dev)
{
	printk("dev release\n");
}

struct platform_device dev = {
	.name = "123",
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










