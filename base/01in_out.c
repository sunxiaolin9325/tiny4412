#include <stdio.h>

int main(void)
{
	int a = 100;
	int b = 30;
	
	int c = 50;

	int in_out = 200;
	int out;
	int in = 52;

	/*
 	* out = in_out
 	* in_out = in
 	*/

	asm volatile (
		//用0 1 2 ...来匹配变量
		"mov %0, %1\n"
		"mov %1, %2\n"
		//= 输出 +输入输出 & 单独占用一个寄存器 r 寄存器
		//为变量分配一个寄存器
		:"=&r"(out), "+r"(in_out)
		:"r"(in)
		:
	);

	printf("hello world out = %d in_out = %d\n", out, in_out);

	//假设C r0=1
	__asm__ __volatile__(
		"mov %0, #20\n"	
		"mov r0, #123\n"	
		"mov %1, r0\n"

		//"mov r1, %2\n"
		//"mov %0, r1\n"
		"mov %0, %2\n"
		:"=&r"(a), "=&r"(b)//声明输出变量和输入输出变量
		:"r"(c)//声明输入变量
		:"r0"//保护寄存器
	);

	printf("hello asm %d %d\n", a, b);
	//C语言 r0=1
	/*
	asm volatile (
		""
		:
		:
		:
	);
	*/
	return 0;
}



