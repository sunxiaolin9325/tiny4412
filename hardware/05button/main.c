#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <led.h>
#include <chip_id.h>
#include <button.h>

int main(void)
{
	int flag;

	button_init();
	led_init();

	while (1) {
		flag = button_state();
		if (flag == 4) {
			led_off(0);
			led_off(1);
			led_off(2);
			led_off(3);
		} else {
			led_on(flag);
		}
	}

	return 0;
}


