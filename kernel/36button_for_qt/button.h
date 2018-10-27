#ifndef __BUTTON_H__
#define __BUTTON_H__


#define GPX3DAT	0x0C64

struct platform_data_st {
        int num;
        char *info;
};

struct button_st {
	void *__iomem v;
	int irq;
	int code;

	struct input_dev *dev;
};

#endif
