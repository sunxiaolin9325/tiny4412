#include <common.h>
#include <lib.h>

void delay(int ms)
{
	volatile int i, j;

	for (i = 0; i < ms; i++) 
		for (j = 0; j < 10000; j++)
			; 
}
