#ifndef LZY_ADC_H
#define LZY_ADC_H

#define ADC_BASE 0x126C0000
#define ADCCON 		(*(volatile unsigned int *)(ADC_BASE + 0x0000)) 
#define ADCDLY 		(*(volatile unsigned int *)(ADC_BASE + 0x0008)) 
#define ADCDAT 		(*(volatile unsigned int *)(ADC_BASE + 0x000C))    
#define CLRINTADC 	(*(volatile unsigned int *)(ADC_BASE + 0x0018)) 
#define ADCMUX 		(*(volatile unsigned int *)(ADC_BASE + 0x001C))

extern void adc_init(void);
extern void adc_start(void);
extern void adc_end(void);
extern int adc_get(void);
extern void adc_irq_init(void);
extern void do_adc(void);

#endif

