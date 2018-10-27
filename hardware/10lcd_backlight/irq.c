#include <irq.h>
#include <common.h>
#include <wdt.h>
#include <adc.h>
#include <rtc.h>
#include <pwm.h>

void do_irq(void)
{
	//这个寄存只能读一次  通知  pending---->active
	unsigned icciar_cpu0 = ICCIAR_CPU0;
	//printf("fasheng\n");
	//处理
	switch(icciar_cpu0 & 0x3ff){
		case 75:
			//do_wdt();
			break;
		case 76:
//			do_alarm();
			break;
		case 77:
//			do_tic();
			break;
		case 42:
			//do_adc();
			break;
		case 70: 
			do_timer1();
			break;
		default:
			break;
	}

	//通知  active---->inactive
	ICCEOIR_CPU0 = icciar_cpu0;		
}

void sgi_init(void)
{
	ICCICR_CPU0 = 1;
	ICCPMR_CPU0 = 255;
	ICDDCR = 1;	
	ICDISER0_CPU0 |= 1;
	ICDIPR_CPU &= ~0xff;		
	ICDIPTR_CPU |= 1;	

	//__asm__ __volatile__(
	//	"mrs r0, cpsr\n"
	//	"bic r0, r0, #(1 << 7)\n"
	//	"msr cpsr, r0\n"
	//	:::"r0"
	//);
	__asm__ __volatile__("cpsie i\n");
}

void gen_sgi(void)
{
	#define ICDSGIR (*(volatile unsigned int *)(0x10490000 + 0x0F00))
	ICDSGIR = (1 << 16) | 0;
}

