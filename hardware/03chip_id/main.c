#include <common.h>
#include <hardware.h>
#include <lib.h>
#include <chip_id.h>

int main(void)
{
	int count = 5;

	while (count--) {
		hardware_init();
		hardware_ops();
		print_chip_id();
		udelay(1000000);
	}

	return 0;
}


