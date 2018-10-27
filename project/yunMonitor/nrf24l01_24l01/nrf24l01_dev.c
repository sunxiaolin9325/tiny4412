#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
#include "nrf24l01.h"

void nrf24l01_release(struct device *dev)
{

}

struct nrf24l01_info_st info = {
	.num = 1,
	.name = "nrf24l01",
};

struct resource nrf24l01_res[] = {
	[0] = {
	},
};

struct platform_device nrf24l01_dev = {
	//用于匹配驱动的设备名
	.name = "nrf24l01",
	.id = -1,
	.dev = {
		.platform_data = &info,
		.release = nrf24l01_release,
	},	
	.resource = nrf24l01_res,
	.num_resources = ARRAY_SIZE(nrf24l01_res),
};

static __init int nrf24l01_dev_init(void)
{
	return platform_device_register(&nrf24l01_dev);
}

static __exit void nrf24l01_dev_exit(void)
{
	platform_device_unregister(&nrf24l01_dev);
}

module_init(nrf24l01_dev_init);
module_exit(nrf24l01_dev_exit);

MODULE_LICENSE("GPL");


