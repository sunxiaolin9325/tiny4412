#ifndef __WDT_H__
#define __WDT_H__

extern void wdt_init(int ms);
extern void wdt_enable(void);
extern void wdt_disable(void);

extern void wdt_irq_init(int ms);

#define WDT_BASE 0x10060000
#define WTCON 		(*(volatile unsigned int *)(WDT_BASE + 0x0000)) 
#define WTDAT 		(*(volatile unsigned int *)(WDT_BASE + 0x0004)) 
#define WTCNT 		(*(volatile unsigned int *)(WDT_BASE + 0x0008)) 
#define WTCLRINT 	(*(volatile unsigned int *)(WDT_BASE + 0x000C)) 


#endif
