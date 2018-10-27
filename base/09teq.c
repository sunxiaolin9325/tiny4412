#include <stdio.h>

int main(void)
{
	int c;
	
	__asm__ __volatile__(
		"mov r0, #5\n"
		"mov r1, #6\n"
		//注意：teq是一个指令 不是t+eq
		//判断两个数是否相等
		"teq r0, r1\n"
		"moveq %0, #1\n"
		"movne %0, #2\n"
		:"=&r"(c)
		:
		:"r0", "r1"
	);

	printf("c = %d\n", c);

	return 0;
}
