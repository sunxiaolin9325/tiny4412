#ifndef __ADC_H__
#define __ADC_H__

extern void adc_init(void);
extern void adc_start(void);
extern void wait_for_adc(void);
extern int get_adc(void);

#define ADC_BASE	0x126C0000

#define ADCCON 		(*(volatile unsigned int *)(ADC_BASE + 0x0000)) 
#define ADCDLY 		(*(volatile unsigned int *)(ADC_BASE + 0x0008)) 
#define ADCDAT 		(*(volatile unsigned int *)(ADC_BASE + 0x000C)) 
#define CLRINTADC 	(*(volatile unsigned int *)(ADC_BASE + 0x0018)) 
#define ADCMUX 		(*(volatile unsigned int *)(ADC_BASE + 0x001C)) 

#endif
