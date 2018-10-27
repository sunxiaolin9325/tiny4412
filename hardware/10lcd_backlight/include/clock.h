#ifndef LZY_CLOCK_H
#define LZY_CLOCK_H

extern void clock_for_uart(void);
extern void clock_for_lcd(void);//800M

#define CLK_DIV_LCD (*(volatile unsigned int *)(0x10030000 + 0xC534))
#define CLK_SRC_LCD0 (*(volatile unsigned int *)(0x10030000 + 0xC234))
#define CLK_SRC_MASK_LCD (*(volatile unsigned int *)(0x10030000 + 0xC334))
#define CLK_GATE_IP_LCD (*(volatile unsigned int *)(0x10030000 + 0xC934))
#define CLK_DIV_PERIL0 (*(volatile unsigned int *)(0x10030000 + 0xC550))
#define CLK_SRC_PERIL0 (*(volatile unsigned int *)(0x10030000 + 0xC250))
#define CLK_SRC_TOP1 (*(volatile unsigned int *)(0x10030000 + 0xC214))
#define CLK_SRC_DMC (*(volatile unsigned int *)(0x10040000 + 0x0200))
#define MPLL_CON0 (*(volatile unsigned int *)(0x10040000 + 0x0108))


#endif
