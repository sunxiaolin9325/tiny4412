#ifndef __COMMON_H__
#define __COMMON_H__

#define NULL (void *)0
//#define printf ((int (*)(const char *, ...))0x43e11a2c)
#define printf(...) (((int (*)(const char *, ...))0x43e11a2c)(__VA_ARGS__))
#define udelay(us) (((void (*)(int))0x43e26480)(us))

#endif






