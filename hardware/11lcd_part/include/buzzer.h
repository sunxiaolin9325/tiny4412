#ifndef __BUZZER_H__
#define __BUZZER_H__

#define GPD0CON (*(volatile unsigned int *)(0x11400000 + 0x00A0)) 
#define GPD0DAT (*(volatile unsigned int *)(0x11400000 + 0x00A4))

extern void buzzer_init(void);
extern void buzzer_on(void);
extern void buzzer_off(void);

#endif
