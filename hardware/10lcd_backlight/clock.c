#include <clock.h>
#include <common.h>

void clock_for_lcd(void)
{
	CLK_DIV_LCD &= ~0xf;

	CLK_SRC_LCD0 &= ~0xf;
	CLK_SRC_LCD0 |= 6;

	CLK_SRC_MASK_LCD |= 1;
	CLK_GATE_IP_LCD |= 1;

	#define LCDBLK_CFG (*(volatile unsigned int *)(0x10010000 + 0x0210))
	LCDBLK_CFG |= 1 << 1;

#ifdef DEBUG
	printf("CLK_SRC_LCD0 = %x\n", CLK_SRC_LCD0);
	printf("CLK_DIV_LCD = %x\n", CLK_DIV_LCD);
#endif
}

void clock_for_uart(void)
{
	printf("CLK_DIV_PERIL0 = %x\n", CLK_DIV_PERIL0);
	//CLK_DIV_PERIL0 = 0x77777
	printf("CLK_SRC_PERIL0 = %x\n", CLK_SRC_PERIL0);
	//CLK_SRC_PERIL0 = 66666
	printf("CLK_SRC_TOP1 = %x\n", CLK_SRC_TOP1);
	//CLK_SRC_TOP1 = 1111000
	printf("CLK_SRC_DMC = %x\n", CLK_SRC_DMC);
	//CLK_SRC_DMC = 11000
	printf("MPLL_CON0 = %x\n", MPLL_CON0);
	//MPLL_CON0 = a0640300
	//16-25:0x64=100
	//8-13:3
	//0-2:0
}




