#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <led.h>
#include <chip_id.h>

int main(void)
{
	int count = 101;

	led_init();

	while (count--) {
		led_on(count % 4);
		udelay(1000000);
		led_off(count % 4);
		udelay(1000000);
	}

	return 0;
}


