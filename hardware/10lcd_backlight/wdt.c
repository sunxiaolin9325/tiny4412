#include <wdt.h>
#include <common.h>
#include <irq.h>

void wdt_init(int ms)
{
	//t=0.128ms
	WTCON = (99 << 8) | (3 << 3);
	//65535 / 8 = 8192
	WTDAT = 8 * ms;
	WTCNT = 8 * ms;
}

void wdt_enable(void)
{
	WTCON |= 1 << 5;
}

void wdt_disable(void)
{
	WTCON &= ~(1 << 5);
}

void wdt_select_reset(int select)
{
	WTCON &= ~7;
	if(select){
		//打开电源		
		AUTOMATIC_WDT_RESET_DISABLE = 0;
		MASK_WDT_RESET_REQUEST = 0;
		WTCON |= 1;
	}else{
		WTCON |= 1 << 2;
	}
}

void wdt_reset_init(int ms)
{
	wdt_init(ms);
	wdt_select_reset(1);
	wdt_enable();
}

void do_wdt(void)
{
	printf("hello wdt wdt \n");
	WTCLRINT = 1;
}

void wdt_irq_init(int ms)
{
	wdt_init(ms);
	wdt_select_reset(0);

	//gic
	//1.查看wdt的中断ID
	//2.使能cpu接口
	ICCICR_CPU0 = 1;
	//3.设置cpu接口的门槛
	ICCPMR_CPU0 = 255;
	//4.使能中断分配器
	ICDDCR = 1;	
	//5.使能75号中断源
	ICDISER2_CPU0 |= 1 << (75 - 64);
	//6.设置75号中断源的优先级
	CDIPR18_CPU0 &= ~(0xff << 24);
	//7.设置75号中断源的目标cpu
	ICDIPTR18_CPU0 |= 1 << 24;

	__asm__ __volatile__("cpsie i\n");
	
	wdt_enable();
}


