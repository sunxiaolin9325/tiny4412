#ifndef __ADC_H__
#define __ADC_H__

#include <linux/miscdevice.h>
#include <linux/fs.h>

#define EXYNOS4_PA_ADC	0x126C0000
#define EXYNOS4_SZ_ADC	SZ_4K

#define ADCCON 		0x0000
#define ADCDLY 		0x0008
#define ADCDAT 		0x000C 
#define CLRINTADC 	0x0018 
#define ADCMUX 		0x001C

#define EXYNOS4_PA_IESR	0x10440000 
#define EXYNOS4_SZ_IESR	SZ_4K
//使能中断
#define IESR2 		0x0020
//用于清除ADC集线器中的中断
#define IESC2 		0x0024

#define HAVE_DATA	0
#define NO_DATA		1

struct adc_pro_st {
	int value;
};

struct adc_st {
	int value;
	int count;
	int flag;
	spinlock_t lock;

	void __iomem *v;
	void __iomem *v_iesr;
	u32 adccon, adcdly, adcdat;
	u32 adcclrint, adcmux;
	u32 iesr2;

	struct clk* clk_adc;
	struct clk* clk_adcphy;
	struct clk* clk_fsys_adc;

	//struct cdev dev;
	//dev_t no;
	struct miscdevice misc;
	struct file_operations adc_ops;

	int irq;
	wait_queue_head_t rq;
};

#endif





