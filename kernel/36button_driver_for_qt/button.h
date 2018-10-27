#ifndef __BUTTON_H__
#define __BUTTON_H__

struct platform_data_st {
        int num;
        char *info;
};

#define GPX3DAT	0x0C64

#define EXYNOS4_PA_BUTTON 0x11000000
#define EXYNOS4_SZ_BUTTON SZ_4K

#define EXYNOS4_NUM_BUTTON 4

struct button_st {
	void *__iomem v;
	int irq;
	int code;

	struct input_dev *dev;
};

#endif
