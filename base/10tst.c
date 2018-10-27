#include <stdio.h>

int main(void)
{
	int c;

	__asm__ __volatile__(
			// 1111 0000
		"mov r0, #0xf0\n"
		//r0&(1<<4)
		//判断第4位是否为0
		//实际操作 与操作 0xf0 & (1 << 4) != 0  Z=0
		"tst r0, #(1 << 4)\n"
		//0xf0 & (1 << 4) != 0  Z=0
		//如果等于0
		"moveq %0, #0\n"  // Z==1
		//如果不等于0
		"movne %0, #1\n"
		:"=&r"(c)
		:
		:"r0"
	);

	printf("c = %d\n", c);

	return 0;
}
