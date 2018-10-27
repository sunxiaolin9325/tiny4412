#ifndef __BDD_H__
#define __BDD_H__

#define RED	0
#define GREEN	1
#define BLUE	2

struct led_bus {
	int id;
	struct bus_type bus;
};

struct led_device {
	int id;
	struct device dev;
};

struct led_driver {
	int id;
	struct device_driver drv;
};

#endif



