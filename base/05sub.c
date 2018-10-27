#include <stdio.h>

int main(void)
{
	int sub;
	int sub1;
/*
	asm volatile (
		"mov r0, #5\n"
		"mov r1, #4\n"
		//r0=r0-r1 r0-=r1
		//sub r0, r1
		//"sub r0, r0, r1\n"
		"sub %0, r0, r1\n"
		:"=&r"(sub)
		:
		:"r0", "r1"
	);

	printf("sub = %d\n", sub);
*/
	//0x33333333 00000004
	//0x11111111 00000005
	//0x22222221 ffffffff
	
	asm volatile (
		"mov r0, #4\n"
		"mov r1, #5\n"
		//NZCVQ
		//C 减法 如果有借位 Clear C
		//       反之 Set C
		"subs %0, r0, r1\n"
		"ldr r0, =0x33333333\n"
		"ldr r1, =0x11111111\n"
		//%1=r0-r1-!C
		"sbc %1, r0, r1\n"
		:"=&r"(sub), "=&r"(sub1)
		:
		:"r0", "r1"
	);	

	printf("sub = %#x%08x\n", sub1, sub);

	return 0;
}




