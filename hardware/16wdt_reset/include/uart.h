#ifndef __UART_H__
#define __UART_H__

extern void uart_init(int no);
extern void uart_send(int no, char c);
extern char uart_recv(int no);

extern void uputchar(char c);
extern char ugetchar(void);
extern void _uputs(char *s);
extern void uputs(char *s);
extern void ugets(char *buf, int len);
extern int uprintf(const char *fmt, ...);

#define GPA0CON (*(volatile unsigned int *)(0x11400000 + 0x0000))

#define UART_BASE	0x13800000

#define ULCON(n)	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0000)) 
#define UCON(n)		(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0004)) 
#define UFCON(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0008)) 
#define UMCON(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x000C)) 
#define UTRSTAT(n)	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0010)) 
#define UERSTAT(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0014)) 
#define UFSTAT(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0018)) 
#define UMSTAT(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x001C)) 
#define UTXH(n)		(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0020)) 
#define URXH(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0024)) 
#define UBRDIV(n)	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x0028)) 
#define UFRACVAL(n) 	(*(volatile unsigned int *)(UART_BASE + (n) * 0x10000 + 0x002C)) 

#endif





