#include <common.h>
#include <lcd.h>
#include <clock.h>


void gpio_for_lcd(void)
{
	GPF0CON = 0x22222222;
	GPF1CON = 0x22222222;
	GPF2CON = 0x22222222;
	GPF3CON &= ~0xffff; 
	GPF3CON |= 0x2222; 
}

void time_for_lcd(void)
{
	//33.3M enable
	VIDCON0 = (2 << 6) | 3;
	//VCLK HS VS VDEN
	VIDCON1 = (1 << 7) | (1 << 6) | (1 << 5);
	VIDTCON0 = (12 << 16) | (21 << 8) | 9;	
	VIDTCON1 = (25 << 16) | (209 << 8) | 19;
	VIDTCON2 = (479 << 11) | 799;
}

//   0x60000000
void lcd_win0_init(void)
{
#ifdef BPP565
	WINCON0 = (1 << 16) | (5 << 2) | 1;
	VIDOSD0C = 480 * 800 * 2 >> 2;
	VIDW00ADD2 = (199 * 2 << 13) | 601 * 2;
#else
	WINCON0 = (1 << 15) | (11 << 2) | 1;
	VIDOSD0C = 480 * 800;
	VIDW00ADD2 = (199 * 4 << 13) | 601 * 4;
#endif
	SHADOWCON &= ~(1 << 10);
	SHADOWCON &= ~(1 << 5);
	SHADOWCON |= 1;

	WINCHMAP2 &= ~(7 << 16);
	WINCHMAP2 |= 1 << 16;

	WINCHMAP2 &= ~(7 << 0);
	WINCHMAP2 |= 1 << 0;

	VIDOSD0A = 0;
	VIDOSD0B = (600 << 11) | 360;

	//page wide = 601
	//offset = 199

	//win0   buffer0
	VIDW00ADD0B0 = 0x60000000;
	VIDW00ADD1B0 = 0x60000000 + VIDOSD0C * 4;
}
//0x70000000
void lcd_win1_init(void)
{
#ifdef BPP565
	WINCON1 = (1 << 16) | (5 << 2) | 1;
	VIDOSD1D = 480 * 800 * 2 >> 2;
	VIDW01ADD2 = (400 * 2 << 13) | 400 * 2;
#else
	WINCON1 = (1 << 15) | (11 << 2) | 1;
	VIDOSD1D = 480 * 800;
	VIDW01ADD2 = (400 * 4 << 13) | 400 * 4;
#endif
	SHADOWCON &= ~(1 << 11);
	SHADOWCON &= ~(1 << 6);
	SHADOWCON |= 1 << 1;

	WINCHMAP2 &= ~(7 << 19);
	WINCHMAP2 |= 2 << 19;

	WINCHMAP2 &= ~(7 << 3);
	WINCHMAP2 |= 2 << 3;

	VIDOSD1A = (400 << 11) | 240;
	VIDOSD1B = (799 << 11) | 479;
	
	//page wide = 400
	//offset = 400
	
	VIDOSD1C = 0x777 << 12;

	//win1  buffer0
	VIDW01ADD0B0 = 0x70000000;
	VIDW01ADD1B0 = 0x70000000 + VIDOSD1D * 4;
}

void lcd_init(void)
{
	gpio_for_lcd();
	clock_for_lcd();
	time_for_lcd();
	lcd_win0_init();
	lcd_win1_init();
}

void draw_point(int fb, int x, int y, int r, int g, int b)
{
#ifdef BPP565
	unsigned short *v;
	if (fb == 0) {
		v = (void *)0x60000000;
	} else {
		v = (void *)0x70000000;
	}
	//  5[11-15] 6[5-10]  5[0-4]
	*(v + y * 800 + x) = (r << 11) | (g << 5) | (b);
#else
	unsigned int *v;
	if (fb == 0) {
		v = (void *)0x60000000;
	} else {
		v = (void *)0x70000000;
	}
	*(v + y * 800 + x) = (r << 16) | (g << 8) | (b);
#endif
}










