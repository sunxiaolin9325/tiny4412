#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <led.h>
#include <chip_id.h>
#include <wdt.h>
#include <clock.h>
#include <button.h>
#include <buzzer.h>
#include <uart.h>
#include <lcd.h>
#include <mmu.h>

int main(void)
{
	create_table((void *)0x70000000);
	my_mmap(0xffff0000, 0x72000000);
	//0xfffxxxxx---->0x720xxxxx
	//0xffffxxxx---->0x720fxxxx
	//0xffff0000---->0x720f0000
	//0xffff0004---->0x720f0004
	mmu_enable();	

	//访问虚拟地址
	memcpy((void *)0xffff0000, (void *)0x50000000, 40);	

	wdt_reset_init(3000);
	
	return 0;
}


