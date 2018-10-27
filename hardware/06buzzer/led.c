#include <common.h>
#include <led.h>

void led_init(void)
{
	//GPM4 [0,1,2,3] 初始化为输出功能
	//并且都输出高电平
	//         [0001][0010][0010] [0010]
	GPM4CON &= ~0xffff;
	GPM4CON |= 0x1111;
	// [xxxxxxxx]
	GPM4DAT |= 0xf;
}

void led_on(int no)
{
	if (no > 3 || no < 0) {
		return;
	}
	//  [xxxx]
	GPM4DAT &= ~(1 << no);
}

void led_off(int no)
{
	if (no > 3 || no < 0) {
		return;
	}
	//  [xxxx]
	GPM4DAT |= (1 << no);
}
