#include <stdio.h>

int main(void)
{
	int a, b, c, d;

	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r5, #4\n"
		// sp-=4 *sp=r0	
		//"str r0, [sp, #-4]!\n"
		//"str r1, [sp, #-4]!\n"
		//"str r2, [sp, #-4]!\n"

		//入栈 压栈
		//寄存器大的先入栈
		//"stmfd sp!, {r0,r2,r1}\n"

		//"stmfd sp!, {r0-r2, r5}\n"
		"push {r0-r2, r5}\n"
		"mov r0, #4\n"
		"mov r2, #4\n"
		"mov r1, #4\n"
		//出栈 弹栈	
		//先出来的给小寄存器
		//"ldmfd sp!, {r0-r2, r5}\n"
		"pop {r0-r2, r5}\n"

		"mov %0, r0\n"
		"mov %1, r1\n"
		"mov %2, r2\n"
		"mov %3, r5\n"
		:"=&r"(a), "=&r"(b), "=&r"(c), "=&r"(d)
		:
		:"r0", "r1", "r2", "r5"
	);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);

	return 0;
}
