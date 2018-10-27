#include <clock.h>
#include <common.h>

void clock_for_lcd(void)
{
	//目的是配置SCLK_FIMD0的时钟为100M
	#define CLK_SRC_LCD0 (*(volatile unsigned int *)(0x10030000 + 0xC234))
	printf("CLK_SRC_LCD0 = %#x\n", CLK_SRC_LCD0);	
	//CLK_SRC_LCD0 = 0x1111
	//MOUTFIMD0 = 800M
	CLK_SRC_LCD0 &= ~0xf;
	CLK_SRC_LCD0 |= 6;
	//SCLK_FIMD0 = MOUTFIMD0 / 8
	#define CLK_DIV_LCD (*(volatile unsigned int *)(0x10030000 + 0xC534))
	CLK_DIV_LCD &= ~0xf;
	CLK_DIV_LCD |= 7;
	#define CLK_SRC_MASK_LCD (*(volatile unsigned int *)(0x10030000 + 0xC334))
	CLK_SRC_MASK_LCD |= 1;

	#define CLK_GATE_IP_LCD (*(volatile unsigned int *)(0x10030000 + 0xC934))
	CLK_GATE_IP_LCD |= 1;

	//让DisplayController的时钟为SCLK_FMID0
	#define LCDBLK_CFG (*(volatile unsigned int *)(0x10010000 + 0x0210))
	LCDBLK_CFG |= 1 << 1;
	
	//等待SCLK_FIMD0稳定
	#define CLK_DIV_STAT_LCD (*(volatile unsigned int *)(0x10030000 + 0xC634))
	while (CLK_DIV_STAT_LCD & 1);	
}

void clock_for_uart0(void)
{
	#define CLK_DIV_PERIL0 (*(volatile unsigned int *)(0x10030000 + 0xC550))
	printf("CLK_DIV_PERIL0 = %#x\n", CLK_DIV_PERIL0);
	//CLK_DIV_PERIL0 = 0x77777
	#define CLK_SRC_PERIL0 (*(volatile unsigned int *)(0x10030000 + 0xC250))
	printf("CLK_SRC_PERIL0 = %#x\n", CLK_SRC_PERIL0);
	//CLK_SRC_PERIL0 = 0x66666
	#define CLK_SRC_TOP1 (*(volatile unsigned int *)(0x10030000 + 0xC214))
	printf("CLK_SRC_TOP1 = %#x\n", CLK_SRC_TOP1);
	//CLK_SRC_TOP1 = 0x1111000	
	#define CLK_SRC_DMC (*(volatile unsigned int *)(0x10040000 + 0x0200))
	printf("CLK_SRC_DMC = %#x\n", CLK_SRC_DMC);
	//CLK_SRC_DMC = 0x11000	
	#define MPLL_CON0 (*(volatile unsigned int *)(0x10040000 + 0x0108))
	printf("MPLL_CON0 = %#x\n", MPLL_CON0);
	//MPLL_CON0 = 0xa0640300
	//MDIV = 0x64 = 100
	//PDIV = 0x3 = 3
	//SDIV = 0
	
	//800M    = 100  x 24M / (3 x 2 ^ 0)
	//FOUT = MDIV x FIN / (PDIV x 2^SDIV)
}




