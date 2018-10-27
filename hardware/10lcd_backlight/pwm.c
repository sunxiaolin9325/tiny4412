#include <pwm.h>
#include <common.h>
#include <irq.h>

#define GPD0CON (*(volatile unsigned int *)(0x11400000 + 0x00A0))

void timer0_init(int cycle, int cmp)
{
	GPD0CON &= ~0xf;
	GPD0CON |= 2;
	//100M / 100 / 4 = 250000 HZ
	TCFG0 &= ~0xff;
	TCFG0 |= 99;
	
	TCFG1 &= ~0xf;
	TCFG1 |= 2; 

	TCNTB0 = cycle - 1;
	TCMPB0 = cmp - 1;

	TCON &= ~0xf;
	TCON |= (1 << 3) | (1 << 1) | 1;
	TCON &= ~(1 << 1);
}

void timer1_init(int cycle)
{
	//100M / 16  = 6250000 HZ
	TCFG0 &= ~0xff;
	TCFG0 |= 15;
	
	TCFG1 &= ~(0xf << 4);
///	TCFG1 |= (2 << 4); 

	TCNTB1 = 0x28a;
	TCMPB0 = 0x1e8480;

	TCON &= ~(0xf << 8);
	TCON |= (1 << 11) | (1 << 9) | (1 << 8);
	TCON &= ~(1 << 9);

	TINT_CSTAT |= 1 << 1;
#define ICDIPR17_CPU0 (*(volatile unsigned int *)(0x10490000 + 0x0444))
#define ICDIPTR17_CPU0 (*(volatile unsigned int *)(0x10490000 + 0x0844))
	ICCICR_CPU0 = 1;
	ICCPMR_CPU0 = 255;
	ICDDCR = 1;	

	ICDISER2_CPU0 |= (1 << (70-64));
	ICDIPR17_CPU0 &= ~(0xff << 16);
	ICDIPTR17_CPU0 |= (1 << 16);

	__asm__ __volatile__("cpsie i\n");	
}

void stop_timer1(void)
{
	TCON &= ~(0xf << 8);
}

