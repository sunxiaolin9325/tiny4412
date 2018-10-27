#include <uart.h>
#include <common.h>
#include <stdarg.h>  //宏定义

void uart_init(int no)
{
	//1.配置时钟 100M
	//2.配置相应的gpio为uart功能
	switch (no) {
		case 0:
			GPA0CON &= ~0xff;
			GPA0CON |= 0x22;
			break;
		case 1:
		case 2:
		case 3:
		default:
			break;
	}
	//3.8N1
	ULCON(no) = 3;
	UCON(no) = (1 << 2) | (1 << 0);
	//4.关闭流控 AFC
	UMCON(no) = 0;
	//5.关闭FIFO
	UFCON(no) = 0;	
	//6.115200
	//(SCLK_UART/(bps * 16)) - 1
	//100000000/115200/16-1=53.25
	UBRDIV(no) = 53;
	UFRACVAL(no) = 4;
}

void uart_send(int no, char c)
{
	//1.把数据填写到发送寄存器
	UTXH(no) = c;
	//2.等待数据发送完成
	while (!(UTRSTAT(no) & (1 << 1)));
}

char uart_recv(int no)
{
	//1.等待接收数据完成
	while (!(UTRSTAT(no) & (1 << 0)));
	//2.返回接收到数据
	return URXH(no);
}

void uputchar(char c)
{
	uart_send(0, c);
}

char ugetchar(void)
{
	return uart_recv(0);
}

void _uputs(char *s)
{
	while (*s) {
		uputchar(*s);	
		if (*s == '\n') {
			uputchar('\r');
		}
		s++;
	}
}

void uputs(char *s)
{
	_uputs(s);
	uputchar('\r');	
	uputchar('\n');	
}

void ugets(char *buf, int len)
{
	char c;
	int count = 0;

	while ((c = ugetchar()) != '\r') {
		if (count == (len - 1)) {
			break;
		}
		*buf = c;
		count++;
		uputchar(c);
		buf++;	
	}	
	*buf = 0;
	uputchar('\r');	
	uputchar('\n');	
}

void itoa(int n, char *buf)
{
	int i;

	if (n < 10) {
		buf[0] = n + '0';
		buf[1] = 0;
		return;
	}
	itoa(n / 10, buf);
	for (i = 0; buf[i]; i++);
	buf[i] = n % 10 + '0';
	buf[i + 1] = 0;
}

void xtoa(int n, char *buf)
{
	int i;
	
	if (n < 16) {
		if (n < 10) 
			buf[0] = n + '0';
		else
			buf[0] = n - 10 + 'a';
		buf[1] = 0;
		return;
	}
	xtoa(n / 16, buf);
	for (i = 0; buf[i]; i++);
	if (n % 16 > 10) {
		buf[i] = n % 16 - 10 + 'a';
	} else {
		buf[i] = n % 16 + '0';
	}
	buf[i + 1] = 0;
}

int uprintf(const char *fmt, ...)
{
	va_list ap;
	int n;
	char *s;
	char buf[32];

	va_start(ap, fmt);

	while (*fmt) {
		if (*fmt == '%') {
			fmt++;
			switch (*fmt) {
				case 'c':
					n = va_arg(ap, int);	
					uputchar(n);
					break;
				case 's':
					s = va_arg(ap, char *);
					_uputs(s);
					break;
				case 'd':
					n = va_arg(ap, int);
					if (n < 0) {
						uputchar('-');
						n = -n;
					}
					itoa(n, buf);
					_uputs(buf);
					break;
				case 'x':
					n = va_arg(ap, int);
					xtoa(n, buf);
					_uputs(buf);
					break;
				default:
					break;
			}
		} else {
			uputchar(*fmt);
			if (*fmt == '\n') {
				uputchar('\r');	
			}
		}
		fmt++;
	}	
	
	va_end(ap);
	
	return 0;
}





