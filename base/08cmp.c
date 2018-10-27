#include <stdio.h>

int main(void)
{
	int c;

	__asm__ __volatile__(
		"mov r0, #4\n"
		"mov r1, #5\n"
		//加不加s都会影响cpsr
		"cmp r0, r1\n"//r0-r1
		"movgt %0, #1\n"
		"movlt %0, #2\n"
		"moveq %0, #3\n"
		:"=&r"(c)
		:
		:"r0", "r1"
	);

	printf("c = %d\n", c);

	return 0;
}



