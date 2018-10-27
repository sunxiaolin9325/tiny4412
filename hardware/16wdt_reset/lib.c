#include <common.h>
#include <lib.h>

void *memcpy(void *dest, const void *src, int count)
{
        char *tmp = dest;
        const char *s = src;

        while (count--)
                *tmp++ = *s++;
        return dest;
}

void delay(int ms)
{
	volatile int i, j;

	for (i = 0; i < ms; i++) 
		for (j = 0; j < 10000; j++)
			; 
}
