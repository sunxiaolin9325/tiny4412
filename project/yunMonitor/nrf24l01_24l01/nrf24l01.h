#ifndef __NRF24L01_H__
#define __NRF24L01_H__

#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/spinlock.h>

//与nfr通信协议
//char txaddr[5] = {0x34, 0x43, 0x10, 0x10, 0x01};
//char rxaddr[5] = {0x10, 0x20, 0x30, 0x40, 0x50};
//#define TX_CHANNEL      41
//#define RX_CHANNEL      40

//char txaddr[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
//char rxaddr[5] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee};
//#define TX_CHANNEL      51
//#define RX_CHANNEL      50

//char txaddr[5] = {0x12, 0x22, 0x33, 0x44, 0x55};
//char rxaddr[5] = {0xab, 0xbb, 0xcc, 0xdd, 0xee};
//#define TX_CHANNEL      61
//#define RX_CHANNEL      60

struct data_pro_st {
	//是否控制
	int control;
	//开关状态
	int value1;
	//开关序号
	int value2;
	char msg[8];
};

//与用户态交互协议
struct nrf24l01_pro_st {
	char txaddr[5];
	char rxaddr[5];
	char tx_channel;
	char rx_channel;
	struct data_pro_st data;
};

struct nrf24l01_info_st {
	//物理设备个数
	int num;
	char *name;
};

struct nrf24l01_st {
	//锁,打开计数
	int count;
	spinlock_t lock;
	struct miscdevice misc;
	struct file_operations nrf24l01_ops;
};

#endif



