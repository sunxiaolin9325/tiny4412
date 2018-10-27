#include "adc.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/io.h>

volatile unsigned char *v;

void adc_init(void)
{
	v = ioremap(ADC_BASE, SZ_4K);
	if (!v) {
		printk("ioremap adc error\n");
		return;
	}
		// 12           
	ADCCON = (1 << 16) | (1 << 14) | (24 << 6);
	ADCDLY = 0xffff;
}

void adc_start(void)
{
	ADCCON |= 1;
}

void wait_for_adc(void)
{
	while (!(ADCCON & (1 << 15)));
}

int get_adc(void)
{
	return ADCDAT & 0xfff;	
}




