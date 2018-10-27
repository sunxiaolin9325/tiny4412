#include <stdio.h>

int main(void)
{
	int c;

	//读cpsr
	__asm__ __volatile__(
		//影响一下cpsr的标志位
		"mov r0, #0\n"
		"adds r0, r0, #0\n"
		//C=0 N=0 Z=1 V=0 Q=0
		//%0=cpsr
		"mrs %0, cpsr\n"
		:"=&r"(c)
		:
		:
	);

	//cpsr = 0x40000010
	//	 0100 0000....0000 00010000
	//M[4:0] 10000 user
	//NZCVQ EAIFT 
	//01000 00000
	printf("cpsr = %#x\n", c);

	//修改cpsr中的位
	__asm__ __volatile__(
		"mrs r0, cpsr\n"
		"orr r0, r0, #(1 << 7)\n"
		//cpsr=r0
		"msr cpsr, r0\n"
		:::"r0"
	);	
	//修改完后再读一次，查看修改的情况
	//用户模式下修改不了cpsr,不能写
	__asm__ __volatile__(
		"mov r0, #0\n"
		"adds r0, r0, #0\n"
		"mrs %0, cpsr\n"
		:"=&r"(c)
		:
		:
	);

	printf("cpsr = %#x\n", c);

	return 0;
}


