#include <adc.h>
#include <common.h>

//adc转换结束后会产生中断，该还数是中断处理函数
void do_adc(void)
{
	printf("irq : %d\n", get_adc());

	//清除中断请求信号
	CLRINTADC = 1;
}


void adc_init(void)
{
	ADCCON = (1 << 16) | (1 << 14) | (24 << 6);
	ADCDLY = 0xffff;
	ADCMUX = 0;
	//10章 
	#define IESR2 (*(volatile unsigned int *)(0x10440000 + 0x0020))
	IESR2 |= 1 << 19;

	request_irq(42, do_adc);
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




