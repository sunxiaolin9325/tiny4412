#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <led.h>
#include <chip_id.h>
#include <clock.h>
#include <button.h>
#include <buzzer.h>
#include <uart.h>
#include <lcd.h>
#include <mmu.h>

void do_unde(void)
{
	int c;

	__asm__ __volatile__(
		"mrs %0, cpsr\n"
		:"=&r"(c)
		:
		:
	);

	printf("do_unde cpsr = %#x\n", c);
}

// RGB888 32bits=4bytes
// 	[xx][R][B][G]
// RGB565 16bits=2bytes
//   	[][]  B 0-4
//   	      G 5-10
//   	      R 11-15
//


extern void set_handler(void);

int main(void)
{
	int c;
	
	create_table((void *)0x70000000);
	my_mmap(0xffff0000, 0x72000000);
	//0xfffxxxxx---->0x720xxxxx
	//0xffffxxxx---->0x720fxxxx
	//0xffff0000---->0x720f0000
	//0xffff0004---->0x720f0004
	mmu_enable();	

	//访问虚拟地址
	memcpy((void *)0xffff0000, (void *)0x50000000, 40);	
	
	//判断当前处理器的模式
	__asm__ __volatile__(
		"mrs %0, cpsr\n"
		:"=&r"(c)
		:
		:
	);

	printf("cpsr = %#x\n", c);
	//cpsr = 0x600001d3
	//	0110 .... 0001 1101 0011
	

	//创建了一条未定义指令
	__asm__ __volatile__(
		".word 0x77777777\n"
	);	

	printf("i am back\n");

	set_handler();

	__asm__ __volatile__(
		//[xxxx|1111|no]
		"swi 0\n"
		"swi 1\n"
		"svc 2\n"//---->lr_svc pc=0xffff0008
		"svc 3\n"
	);	

	return 0;
}


