#ifndef __CHIP_ID_H__
#define __CHIP_ID_H__

#define ID_BASE 0x10000000
#define PRO_ID          (*(volatile unsigned int *)(ID_BASE + 0x0000))
#define PACKAGE_ID      (*(volatile unsigned int *)(ID_BASE + 0x0004)) 

extern void print_chip_id(void);

#endif
