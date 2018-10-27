#ifndef __EXYNOS4_H__
#define __EXYNOS4_H__

#include <linux/spinlock.h>
#include <linux/clk.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/wait.h>

#define EXYNOS4_PA_IESR	0x10440000
#define EXYNOS4_SZ_IESR	SZ_4K
#define IESR2		0x0020
//用于清楚ADC集线器中的中断
#define IESC2           0x0024

#define EXYNOS4_PA_ADC	0x126c0000
#define EXYNOS4_SZ_ADC	SZ_4K
#define ADCCON 	  	0x0000
#define ADCDLY 	  	0x0008
#define ADCDAT 	  	0x000C
#define CLRINTADC 	0x0018
#define ADCMUX		0x001c

struct adc_value_st {
	int value;
};

struct adc_st {
	int value;
	
	spinlock_t lock;
	int count;
	#define HAVE_DATA	0
	#define NO_DATA		1
	int flag;	

	dev_t no;
	struct cdev dev;
	struct file_operations adc_ops;

	void *__iomem v;
	void *__iomem v_iesr;

	u32 adccon, adcdat; 
	u32 adcdly, clrintadc;

	struct clk *clk; 
	struct clk *clkphy; 
	struct clk *fsys_clk;

	int irq;

	wait_queue_head_t rq;
};

#endif
