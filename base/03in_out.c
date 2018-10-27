#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f;

	asm volatile (
		"mov r0, %3\n"
		"mov r1, %4\n"
		"mov r2, %5\n"

		"mov %0, r0\n"
		"mov %1, r1\n"
		"mov %2, r2\n"
		//一个变量要独占一个寄存器，不然容易出错
		:"=&r"(a), "=&r"(b), "=&r"(c)
		:"r"(d), "r"(e), "r"(f)
		:"r0", "r2", "r1"
	);

	return 0;
}
