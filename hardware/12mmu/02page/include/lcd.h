#ifndef __LCD_H__
#define __LCD_H__

extern void lcd_init(void);
extern void draw_point(int fb, int x, int y, int r, int g, int b);

#define GPF0CON (*(volatile unsigned int *)(0x11400000 + 0x0180)) 
#define GPF1CON (*(volatile unsigned int *)(0x11400000 + 0x01A0))
#define GPF2CON (*(volatile unsigned int *)(0x11400000 + 0x01C0))
#define GPF3CON (*(volatile unsigned int *)(0x11400000 + 0x01E0))

#define LCD_BASE 0x11C00000

#define VIDCON0 	(*(volatile unsigned int *)(LCD_BASE + 0x0000)) 
#define VIDCON1 	(*(volatile unsigned int *)(LCD_BASE + 0x0004)) 
#define VIDCON2 	(*(volatile unsigned int *)(LCD_BASE + 0x0008)) 
#define VIDCON3 	(*(volatile unsigned int *)(LCD_BASE + 0x000C)) 
#define VIDTCON0 	(*(volatile unsigned int *)(LCD_BASE + 0x0010)) 
#define VIDTCON1 	(*(volatile unsigned int *)(LCD_BASE + 0x0014)) 
#define VIDTCON2 	(*(volatile unsigned int *)(LCD_BASE + 0x0018)) 
#define VIDTCON3 	(*(volatile unsigned int *)(LCD_BASE + 0x001C)) 
#define WINCON0 	(*(volatile unsigned int *)(LCD_BASE + 0x0020)) 
#define WINCON1 	(*(volatile unsigned int *)(LCD_BASE + 0x0024)) 
#define WINCON2 	(*(volatile unsigned int *)(LCD_BASE + 0x0028)) 
#define WINCON3 	(*(volatile unsigned int *)(LCD_BASE + 0x002C)) 
#define WINCON4 	(*(volatile unsigned int *)(LCD_BASE + 0x0030)) 
#define SHADOWCON 	(*(volatile unsigned int *)(LCD_BASE + 0x0034)) 
#define WINCHMAP2 	(*(volatile unsigned int *)(LCD_BASE + 0x003C)) 
#define VIDOSD0A 	(*(volatile unsigned int *)(LCD_BASE + 0x0040)) 
#define VIDOSD0B 	(*(volatile unsigned int *)(LCD_BASE + 0x0044)) 
#define VIDOSD0C 	(*(volatile unsigned int *)(LCD_BASE + 0x0048)) 
#define VIDOSD1A 	(*(volatile unsigned int *)(LCD_BASE + 0x0050)) 
#define VIDOSD1B 	(*(volatile unsigned int *)(LCD_BASE + 0x0054)) 
#define VIDOSD1C 	(*(volatile unsigned int *)(LCD_BASE + 0x0058)) 
#define VIDOSD1D 	(*(volatile unsigned int *)(LCD_BASE + 0x005C)) 
#define VIDOSD2A 	(*(volatile unsigned int *)(LCD_BASE + 0x0060)) 
#define VIDOSD2B 	(*(volatile unsigned int *)(LCD_BASE + 0x0064)) 
#define VIDOSD2C 	(*(volatile unsigned int *)(LCD_BASE + 0x0068)) 
#define VIDOSD2D 	(*(volatile unsigned int *)(LCD_BASE + 0x006C)) 
#define VIDOSD3A 	(*(volatile unsigned int *)(LCD_BASE + 0x0070)) 
#define VIDOSD3B 	(*(volatile unsigned int *)(LCD_BASE + 0x0074)) 
#define VIDOSD3C 	(*(volatile unsigned int *)(LCD_BASE + 0x0078)) 
#define VIDOSD4A 	(*(volatile unsigned int *)(LCD_BASE + 0x0080)) 
#define VIDOSD4B 	(*(volatile unsigned int *)(LCD_BASE + 0x0084)) 
#define VIDOSD4C 	(*(volatile unsigned int *)(LCD_BASE + 0x0088)) 
#define VIDW00ADD0B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00A0)) 
#define VIDW00ADD0B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00A4)) 
#define VIDW00ADD0B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20A0)) 
#define VIDW01ADD0B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00A8)) 
#define VIDW01ADD0B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00AC)) 
#define VIDW01ADD0B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20A8)) 
#define VIDW02ADD0B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00B0)) 
#define VIDW02ADD0B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00B4)) 
#define VIDW02ADD0B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20B0)) 
#define VIDW03ADD0B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00B8)) 
#define VIDW03ADD0B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00BC)) 
#define VIDW03ADD0B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20B8)) 
#define VIDW04ADD0B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00C0)) 
#define VIDW04ADD0B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00C4)) 
#define VIDW04ADD0B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20C0)) 
#define VIDW00ADD1B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00D0)) 
#define VIDW00ADD1B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00D4)) 
#define VIDW00ADD1B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20D0)) 
#define VIDW01ADD1B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00D8)) 
#define VIDW01ADD1B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00DC)) 
#define VIDW01ADD1B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20D8)) 
#define VIDW02ADD1B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00E0)) 
#define VIDW02ADD1B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00E4)) 
#define VIDW02ADD1B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20E0)) 
#define VIDW03ADD1B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00E8)) 
#define VIDW03ADD1B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00EC)) 
#define VIDW03ADD1B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20E8)) 
#define VIDW04ADD1B0 	(*(volatile unsigned int *)(LCD_BASE + 0x00F0)) 
#define VIDW04ADD1B1 	(*(volatile unsigned int *)(LCD_BASE + 0x00F4)) 
#define VIDW04ADD1B2 	(*(volatile unsigned int *)(LCD_BASE + 0x20F0)) 
#define VIDW00ADD2 	(*(volatile unsigned int *)(LCD_BASE + 0x0100)) 
#define VIDW01ADD2 	(*(volatile unsigned int *)(LCD_BASE + 0x0104)) 
#define VIDW02ADD2 	(*(volatile unsigned int *)(LCD_BASE + 0x0108)) 
#define VIDW03ADD2 	(*(volatile unsigned int *)(LCD_BASE + 0x010C)) 
#define VIDW04ADD2 	(*(volatile unsigned int *)(LCD_BASE + 0x0110)) 
#define VIDINTCON0 	(*(volatile unsigned int *)(LCD_BASE + 0x0130)) 
#define VIDINTCON1 	(*(volatile unsigned int *)(LCD_BASE + 0x0134)) 
#define W1KEYCON0 	(*(volatile unsigned int *)(LCD_BASE + 0x0140)) 




#endif