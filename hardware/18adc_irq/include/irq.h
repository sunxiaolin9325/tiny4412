#ifndef __IRQ_H__
#define __IRQ_H__

//用来初始化中断控制器
extern void request_irq(int no, void (*handler)(void));
extern void do_irq(void);

#define ICCICR_CPU0   (*(volatile unsigned int *)(0x10480000 + 0x0000)) 
#define ICCPMR_CPU0   (*(volatile unsigned int *)(0x10480000 + 0x0004))
#define ICCIAR_CPU0    (*(volatile unsigned int *)(0x10480000 + 0x000C))
#define ICCEOIR_CPU0  (*(volatile unsigned int *)(0x10480000 + 0x0010))
#define ICDDCR 	      (*(volatile unsigned int *)(0x10490000 + 0x0000))

#define ICDISER1_CPU0 ((volatile unsigned int *)(0x10490000 + 0x104))
#define ICDIPR8_CPU0  ((volatile unsigned int *)(0x10490000 + 0x420))
#define ICDIPTR8_CPU0 ((volatile unsigned int *)(0x10490000 + 0x820))


#endif
