#ifndef __LED_H__
#define __LED_H__

#include <linux/cdev.h>
#include <linux/fs.h>

//GPM4 0,1,2,3

#define EXYNOS4_PA_LED	0x11000000
#define EXYNOS4_SZ_LED	SZ_4K

#define LEDCON	0x2e0
#define LEDDAT	0x2e4

struct led_pro_st {	
	int led_no;
	int light;
	//位图
	int status;
};

struct led_st {
	int status;
	int count;

	int ledcon, leddat;
	void *__iomem v;

	struct class *led_class;
	struct device *led_device;

	dev_t no;
	struct cdev dev;
	
	void (*on)(struct led_st *l, int no);
	void (*off)(struct led_st *l, int no);
};

#endif
