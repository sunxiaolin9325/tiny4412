#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <led.h>
#include <chip_id.h>
#include <clock.h>
#include <button.h>
#include <buzzer.h>
#include <uart.h>

int main(void)
{
	char c = 'A';
	char d;
	char buf[20];

	uart_init(0);

	d = uart_recv(0);
	uart_send(0, d);

	ugets(buf, 20);
	uputs(buf);

	uprintf("nihao %s %d %c %x\n", "hello", 100, 't', 0x300);
	
	while (1) {
		if (c > 'Z') {
			break;
		}
		uart_send(0, c++);
		udelay(1000000);
	}

	return 0;
}


