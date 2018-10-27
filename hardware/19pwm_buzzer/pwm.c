#include <pwm.h>
#include <common.h>
#include <irq.h>

void do_timer0(void)
{
	printf("timer0\n");
	TINT_CSTAT |= 1 << 5;
}

void timer0_init(int cmp, int cycle)
{
	//把GPIO配置位pwm功能
	#define GPD0CON (*(volatile unsigned int *)(0x11400000 + 0x00A0))
	GPD0CON &= ~0xf;
	GPD0CON |= 2;
	
	//100M / 100
	TCFG0 &= ~0xff;
	TCFG0 |= 99;

	//1M / 4 = 250000HZ
	TCFG1 &= ~0xf;
	TCFG1 |= 2;	

	TCNTB0 = cycle - 1;
	//TCNT0
	TCMPB0 = cmp - 1;
	//TCMP0

	//自动装载,打开手动更新
	TCON &= ~0x1f;	
	TCON |= (1 << 3) | (1 << 1);
	//输出信号不翻转
	TCON |= (1 << 2);
	//TCON |= (1 << 3);	//这样不行

	TINT_CSTAT |= 1;

	request_irq(69, do_timer0);

	//定时器开始启动
	TCON |= 1;


	//应该这样用
	TCNTB0 = cycle * 3 - 1;
	//TCNT0
	TCMPB0 = cmp - 1;
	//TCMP0

	//关闭手动更新,在定时器启动后才关闭
	TCON &= ~(1 << 1);
}






