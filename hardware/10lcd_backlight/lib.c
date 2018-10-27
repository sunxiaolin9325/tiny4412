#include <common.h>
#include <lib.h>
//arm-linux-gcc lib.c -o lib.o -O2
void delay(int n)
{
	volatile int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < 1000; j++)
			;
}

int strcmp(const char *cs, const char *ct)
{
        unsigned char c1, c2;

        while (1) {
                c1 = *cs++;
                c2 = *ct++;
                if (c1 != c2)
                        return c1 < c2 ? -1 : 1;
                if (!c1)
                        break;
        }
        return 0;
}

void *memcpy(void *dest, const void *src, int count)
{
        char *tmp = dest;
        const char *s = src;

        while (count--)
                *tmp++ = *s++;
        return dest;
}

