#ifndef LZY_IRQ_H
#define LZY_IRQ_H

#define CDIPR18_CPU0 (*(volatile unsigned int *)0x10490448)
#define ICDIPTR18_CPU0 (*(volatile unsigned int *)0x10490848)
#define ICDISER2_CPU0 (*(volatile unsigned int *)0x10490108)

#define ICCICR_CPU0     (*(volatile unsigned int *)(0x10480000 + 0x0000)) 
#define ICCPMR_CPU0     (*(volatile unsigned int *)(0x10480000 + 0x0004))
#define ICCIAR_CPU0     (*(volatile unsigned int *)(0x10480000 + 0x000C))
#define ICDDCR          (*(volatile unsigned int *)(0x10490000 + 0x0000))
#define ICDIPR_CPU      (*(volatile unsigned int *)(0x10490000 + 0x0400))
#define ICCEOIR_CPU0    (*(volatile unsigned int *)(0x10480000 + 0x0010))
#define ICDIPTR_CPU     (*(volatile unsigned int *)(0x10490000 + 0x0800))
#define ICDISER0_CPU0 (*(volatile unsigned int *)(0x10490000 + 0x100))
//#define ICDISER2_CPU0 (*(volatile unsigned int *)( 0x10490000 + 0x0108))
#define ICDIPR19_CPU0 (* (volatile unsigned int *)( 0x10490000 + 0x044c))
#define ICDIPTR19_CPU0 (*(volatile unsigned int *)(  0x10490000 + 0x084C))

#endif
