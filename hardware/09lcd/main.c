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

// RGB888 32bits=4bytes
// 	[xx][R][B][G]
// RGB565 16bits=2bytes
//   	[][]  B 0-4
//   	      G 5-10
//   	      R 11-15
//

int main(void)
{
	int x, y;

	lcd_init();
	
	for (x = 0; x < 800; x++) {
		for (y = 0; y < 480; y++) {
#ifdef BPP565
			draw_point(0, x, y, 0xff, 0xff, 0xff);
			draw_point(1, x, y, 0xff, 0xff, 0xff);
#else
			draw_point(0, x, y, 0xff, 0xff, 0xff);
			draw_point(1, x, y, 0xff, 0xff, 0xff);
#endif
		}
	}

	for (x = 100; x < 700; x++) {
		for (y = 100; y < 380; y++) {
#ifdef BPP565
			draw_point(0, x, y, 0x1f, 0, 0);
			draw_point(1, x, y, 0, 0x3f, 0);
#else
			draw_point(0, x, y, 0xff, 0, 0);
			draw_point(1, x, y, 0, 0xff, 0);
#endif
		}
	} 

	return 0;
}


