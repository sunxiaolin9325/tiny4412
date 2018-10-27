#include <common.h>
#include <driver.h>
#include <clock.h> 
#include <uart.h> 
#include <lcd.h> 
#include <lib.h>
#include <mmu.h>
#include <wdt.h>
#include <adc.h>
#include <backlight.h>
#include <rtc.h>
#include <pwm.h>

extern unsigned int start;//*start
extern unsigned int end;//*end

int main(void)
{
	ttb_init((void *)0x60000000);//0-0x80000000
	//0xfff----------->0x700
	//0xffff0004------>0x700f0004
	my_mmap((void *)0x60000000, 0xfff00000, 0x70000000);
	mmu_enable();
	//把start.s的代码cp到0xffff0000 
	memcpy((void *)0xffff0000, (void *)start, end - start);
		
	set_backlight_start(127);
	
	return 0;
}



