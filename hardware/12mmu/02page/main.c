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

	*p = 100;
	
	printf("mmu start\n");
	//物理和虚拟要相等？想让uboot活着
	create_table((void *)0x70000000, (void *)0x72000000);
	my_mmap(0x12345678, 0x62345678);
	//0x12345xxx---->0x62345xxx
	mmu_enable();	
	
	printf("mmu alive %d\n", *(int *)0x62345678);
	printf("mmu alive %d\n", *(int *)0x12345678);

	return 0;
}


