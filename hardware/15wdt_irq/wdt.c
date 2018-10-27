#include <wdt.h>
#include <common.h>
#include <irq.h>

void wdt_init(int ms)
{	//100M / 100 / 64 = 15625HZ;
	WTCON = (99 << 8) | (2 << 3);	
	//65535 / 16 = 4096
	WTCNT = 16 * ms;
	WTDAT = 16 * ms;
}

void wdt_enable(void)
{
	WTCON |= 1 << 5;
}

void wdt_disable(void)
{
	WTCON &= ~(1 << 5);
}

void do_wdt(void)
{
	printf("wdt wdt wdt ...\n");

	//清除中断请求信号
	WTCLRINT = 1;	
}

void wdt_irq_init(int ms)
{
	wdt_init(ms);
	WTCON &= ~0x7;	
	WTCON |= 1 << 2;
	//设置中断控制器  使能了中断
	request_irq(75, do_wdt);
	wdt_enable();
}





