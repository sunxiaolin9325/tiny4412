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

// RGB888 32bits=4bytes
// 	[xx][R][B][G]
// RGB565 16bits=2bytes
//   	[][]  B 0-4
//   	      G 5-10
//   	      R 11-15
//

int main(void)
{
	int *p = (void *)0x62345678;
	int c;

	*p = 100;
	
	printf("mmu start\n");
	//物理和虚拟要相等？想让uboot活着
	create_table((void *)0x70000000);
	my_mmap(0x12345678, 0x62345678);
	//0x123xxxxx---->0x623xxxxx
	mmu_enable();	
	
	printf("mmu alive %d\n", *(int *)0x62345678);
	printf("mmu alive %d\n", *(int *)0x12345678);

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

	return 0;
}


