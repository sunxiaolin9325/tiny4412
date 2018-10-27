#include <common.h>
#include <hardware.h>
#include <lib.h>

int main(void)
{
	int count = 5;

	while (count--) {
		hardware_init();
		hardware_ops();
		udelay(1000000);
	}

	return 0;
}


