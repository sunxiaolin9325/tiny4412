#ifndef LZY_UART_H
#define LZY_UART_H

extern void uart_init(void);
extern void uart_send(char c);
extern char uart_recv(void);
extern char ugetchar(void);
extern void uputchar(char c);
extern char *ugets(char *s);
extern void uputs(char *s);
extern int uprintf(const char *fmt, ...);

#define UART0_BASE	0x13800000

#define ULCON0 		(*(volatile unsigned int *)(UART0_BASE + 0x0000)) 
#define UCON0 		(*(volatile unsigned int *)(UART0_BASE + 0x0004)) 
#define UFCON0 		(*(volatile unsigned int *)(UART0_BASE + 0x0008)) 
#define UMCON0 		(*(volatile unsigned int *)(UART0_BASE + 0x000C)) 
#define UTRSTAT0 	(*(volatile unsigned int *)(UART0_BASE + 0x0010)) 
#define UERSTAT0 	(*(volatile unsigned int *)(UART0_BASE + 0x0014)) 
#define UFSTAT0 	(*(volatile unsigned int *)(UART0_BASE + 0x0018)) 
#define UMSTAT0 	(*(volatile unsigned int *)(UART0_BASE + 0x001C)) 
#define UTXH0 		(*(volatile unsigned int *)(UART0_BASE + 0x0020)) 
#define URXH0 		(*(volatile unsigned int *)(UART0_BASE + 0x0024)) 
#define UBRDIV0 	(*(volatile unsigned int *)(UART0_BASE + 0x0028)) 
#define UFRACVAL0 	(*(volatile unsigned int *)(UART0_BASE + 0x002C)) 
#define UINTP0 		(*(volatile unsigned int *)(UART0_BASE + 0x0030)) 
#define UINTSP0 	(*(volatile unsigned int *)(UART0_BASE + 0x0034)) 
#define UINTM0 		(*(volatile unsigned int *)(UART0_BASE + 0x0038)) 

#endif
