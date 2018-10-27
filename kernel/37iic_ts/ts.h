#ifndef __TS_H__
#define __TS_H__

// i2c_transfer 睡眠
//
struct ts_info_st {
        int irq;
        int xres;
        int yres;
        int pressure;
};

struct ts_st {
	int x;
	int y;
	int irq;
	int xres;
	int yres;
	int pressure;
	
	struct work_struct work;
	struct i2c_client *client;	
	struct input_dev *dev;		
};

#endif


