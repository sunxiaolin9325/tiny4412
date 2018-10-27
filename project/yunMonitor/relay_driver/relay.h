#ifndef __RELAY_H__
#define __RELAY_H__

#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/spinlock.h>

#define RELAY_BASE	0x11000000
#define	GPX3CON		0x0C60
#define GPX3DAT		0x0C64

#define BUZZER_BASE	0x11400000
#define GPD0CON		0x00A0
#define GPD0DAT		0x00A4

#define NUM	6

struct relay_pro_st {	
	int no;
	int work;
};

struct relay_st {
	int count;
	spinlock_t lock;

	int relaycon, relaydat;
	void *__iomem v_relay;

	int buzzercon, buzzerdat;
	void *__iomem v_buzzer;

	struct miscdevice misc;
	struct file_operations fops;
};


#endif
