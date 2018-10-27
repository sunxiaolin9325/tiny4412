#include <adc.h>
#include <common.h>

void adc_init(void)
{
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




