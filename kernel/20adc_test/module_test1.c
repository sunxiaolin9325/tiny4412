#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include "adc.h"
#include <linux/clk.h>
#include <linux/delay.h>

//当模块安装的时候执行
static __init int test_init(void)
{
	//时钟
	//三星的驱动把ADC的时钟关了,所以要打开.
	//裸板的ADC时钟默认是开的

	struct clk *clk;
	clk = clk_get(NULL, "adc");
	clk_enable(clk);
	clk = clk_get(NULL, "adcphy");
	clk_enable(clk);
	clk = clk_get(NULL, "fsys_adc");
	clk_enable(clk);

	adc_init();	

	while (1) {
		adc_start();
		wait_for_adc();
		printk("adc:%d\n", get_adc());
		ssleep(1);
	}	

	return 0;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	printk("test_exit\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










