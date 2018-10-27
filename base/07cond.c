#include <stdio.h>

int main(void)
{
	int c;
	int a = 5, b = 6;
	
/*
	if (a > b) {// a - b
		c = 1; // mov c, 1   N=0 Z=0
	} else if (a == b) {
		c = 2; // mov c, 2   Z=1
	} else {
		c = 3; // mov c, 3   N=1
	}
*/
	//大多数的arm指令都支持条件执行
	//thumb指令只有跳转指令才支持条件执行
	// gt lt eq ne le ge
	__asm__ __volatile__ (
		"subs r0, %1, %2\n"
		//条件执行
		"movgt %0, #1\n"
		"moveq %0, #2\n"
		"movlt %0, #3\n"
		:"=&r"(c)
		:"r"(a), "r"(b)
		:"r0"
	);

	printf("c = %d\n", c);

	return 0;
}




