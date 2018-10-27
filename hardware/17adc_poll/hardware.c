#include <common.h>
#include <hardware.h>

//#define printf ((int (*)(const char *, ...))0x43e11a2c)
//#define printf(...) (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))

void hardware_init(void)
{
	printf("%s %s\n", __FILE__, __FUNCTION__);
}

void hardware_ops(void)
{
	printf("%s %s\n", __FILE__, __FUNCTION__);
}


