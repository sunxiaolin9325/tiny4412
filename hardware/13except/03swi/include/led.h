#ifndef __LED_H__
#define __LED_H__

#define GPM4CON (*(volatile unsigned int *)(0x11000000 + 0x02E0)) 
#define GPM4DAT (*(volatile unsigned int *)(0x11000000 + 0x02E4))

extern void led_init(void);
// no [0,3]
extern void led_on(int no);
extern void led_off(int no);

#endif
