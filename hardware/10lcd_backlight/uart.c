#include <uart.h>
#include <common.h>
#include <stdarg.h>

//等待发送完成
void wait_send_end(void)
{
	while(!(UTRSTAT0 & 2));
}

//等待收到数据
void wait_recv_end(void)
{
	while(!(UTRSTAT0 & 1));
}

void uart_init(void) {
	#define GPA0CON (*(volatile unsigned int *)(0x11400000))
	GPA0CON &= ~0xff;
	GPA0CON |= 0x22;

	//8N1  115200
	ULCON0 = 3;
	//配置poll
	UCON0 = (1 << 2) | 1;
	//关掉fifo
	UFCON0 = 0;
	//关掉流控
	UMCON0 = 0;

	//bps
	UBRDIV0 = 53;
	UFRACVAL0 = 4;
}

void uart_send(char c)
{
	UTXH0 = c;
	wait_send_end();
}

char uart_recv(void)
{
	wait_recv_end();
	return URXH0;
}
//----------------------------------------->
char ugetchar(void)
{
	return uart_recv();
}

void uputchar(char c)
{
	uart_send(c);
}

void _uputs(char *s)
{
	while(*s != '\0'){
		uputchar(*s);
		if(*s == '\n')
			uputchar('\r');
		s++;
	}
}

void uputs(char *s)
{
	_uputs(s);
	uputchar('\r');
	uputchar('\n');
}

char *ugets(char *s)
{
	char c;
	char *save = s;

	while((c = ugetchar()) != '\r'){
		*s = c;
		uputchar(c);
		s++;
	}

	*s = 0;

	uputchar('\r');
	uputchar('\n');

	return save;
}
// 1    buf['1'][0]

//123   buf['1']['2']['3'][0]

//123  buf[][][][][]
//12   buf[]['2'][][][]
//1    buf['1'][0][][][]
void itoa(unsigned int n, char *buf)
{
	int i;

	if(n < 10){
		buf[0] = n + '0';
		buf[1] = 0;
		return;
	}
	itoa(n / 10, buf);	
	for(i = 0; buf[i] != '\0'; i++);
	buf[i] = n % 10 + '0';		
	buf[i + 1] = 0;
}

void xtoa(unsigned int n, char *buf)
{
	int i;

	if(n < 16){
		if(n < 10)
			buf[0] = n + '0';
		else 
			buf[0] = n - 10 + 'a';	
		buf[1] = 0;
		return;
	}
	xtoa(n / 16, buf);
	for(i = 0; buf[i] != 0; i++);
	if(n % 16 < 10)
		buf[i] = n % 10 + '0';
	else
		buf[i] = n % 16 - 10 + 'a';
	buf[i + 1] = 0;
}

// %d %c %s %, x
//uprintf("hello %x %d %c %s\n", 100, 100, 'a', "world\n");
int uprintf(const char *fmt, ...)
{
	va_list ap;
	char *s;
	char c;
	int n;
	char buf[32];
	
	va_start(ap, fmt);	

	while(*fmt != 0){
		if(*fmt == '%'){
			fmt++;
			switch(*fmt){
				case 'c':
					c = va_arg(ap, int);	
					uputchar(c);
					break;
				case 's':
					s = va_arg(ap, char *);
					_uputs(s);
					break;
				case 'd':
					n = va_arg(ap, int);
					if(n < 0){
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
		}else{
			uputchar(*fmt);
			if(*fmt == '\n')
				uputchar('\r');
		}
		fmt++;
	}	

	va_end(ap);

	return 0;
}








