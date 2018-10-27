#include <buzzer.h>
#include <common.h>

void buzzer_init(void)
{
	GPD0CON &= ~0xf;
	GPD0CON |= 1;

	GPD0DAT &= ~1;
}

void buzzer_on(void)
{
	GPD0DAT |= 1;
}

void buzzer_off(void)
{
	GPD0DAT &= ~1;
}

