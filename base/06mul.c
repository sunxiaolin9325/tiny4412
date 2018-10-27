#include <stdio.h>

int main(void)
{
	int mul;
/*
	asm volatile (
		"mov r0, #3\n"
		"mov r1, #4\n"
		//mul的三个操作数必须都是寄存器
		//%0=r0*r1
		"mul %0, r0, r1\n"
		:"=&r"(mul)
		:
		:"r0", "r1"
	);

	printf("mul = %d\n", mul);
*/
	asm volatile (
		"mov r0, #4\n"
		"mov "
		"r1, "
		"#3\n"
		"mov r2, #5\n"
		// %0=r2+r0*r1 乘加运算
		//"mla %0, r0, r1, r2\n"
		// %0=r2-r0*r1 乘减运算
		//mls arm cotex a9 支持
		//arm11架构的编译器不支持
		"mls %0, r0, r1, r2\n"
		:"=&r"(mul)
		:
		:"r0", "r1", "r2"
	);	

	printf("mul = %d\n", mul);

	return 0;
}



