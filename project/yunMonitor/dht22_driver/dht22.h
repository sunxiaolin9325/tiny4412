#ifndef __DHT22_H__
#define __DHT22_H__

#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/spinlock.h>

#define TIMEOUT	50

struct dht22_info_st {
	//物理设备个数
	int num;
	char *name;
};

//读指定设备的数据
struct dht22_pro_st {	
	int no;		//可以支持多线程
	int temp;
	int humi;
};

struct dht22_st {
	//锁,打开计数
	int count;
	spinlock_t lock;
	struct miscdevice misc;
	struct file_operations dht22_ops;
	//数组的长度(设备(gpio)个数)
	int num;
	//可变长数组
	unsigned gpio[0];
};

#endif
