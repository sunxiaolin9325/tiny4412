#include <irq.h>
#include <common.h>

typedef void (*irq_action)(void);

irq_action ias[1024];

//状态:	inactive-->没有产生中断
//	pending--->等待处理
//	active --->正在处理
//	inactive-->处理结束

//当cpu产生中断异常跳转到该函数
void do_irq(void)
{
	int no;
	//1.判断中断号（中断源）
	no = ICCICR_CPU0;
	//2.去执行相应的中断处理函数
	ias[no & 0x3ff]();

	ICCEOIR_CPU0 = no;		
}

void request_irq(int no, void (*handler)(void))
{
	//1.使能cpu接口
	ICCICR_CPU0 = 1;	
	//2.使能中断分配器
	ICDDCR = 1;
	//3.设置门槛
	ICCPMR_CPU0 = 0xff;
	//4.使能设备中断
	//no
	// 0: 32-33--63
	// 1: 64-65--95
	// 2: 96-98--xx
	ICDISER1_CPU0[no / 32 - 1] |= 1 << (no  % 32);
	//5.设置设备中断优先级

	//0: 32 -- 35
	//1: 36 -37- 39
	//2: 40 -42- 43
	ICDIPR8_CPU0[(no - 32) / 4] &= ~(0xff << ((no % 4) * 8));
	//6.设置目标cpu
	ICDIPTR8_CPU0[(no - 32) / 4] |= 1 << ((no % 4) * 8);
	//7.设置中断处理函数
	ias[no] = handler;
	//8.开启中断(I=0)
	//>v6
	__asm__ __volatile__(
		"cpsie i\n"
	);
//	__asm__ __volatile__(
//		"mrs r0, cpsr\n"
//		"bic r0, r0, #(1 << 7)\n"
//		"msr cpsr, r0\n"
//		:::"r0"
//	);
}







