#include <stdio.h>

//一条汇编语句编译后就占32位，数字/机器码
//立即数：被编译到指令中的数据
//       条件  指令的编码   位移      立即数
//mov [--4位--|----16位---|--4位--|---8位-----]
//			14*2	0x000000ff
//1.本身小于等于255的数字
//2.经过循环右移偶数位之后小于等于255
//3.特殊情况
//	0xffffffff
//编译成汇编语言后 mvn ~0 已按位取反来存放

int  main(void)
{
	int sum = 0;
	int sum1 = 0;
/*
	asm volatile (
		"mov r0, #3\n"
		"mov r1, #2\n"
		//r0=r0+r1 r0+=r1
		//add r0, r1
		//"add r0, r0, r1\n"
		"add %0, r0, r1\n"
		:"=&r"(sum)
		:
		:"r0", "r1"
	);

	printf("sum = %d\n", sum);
*/
	// 0x12345678 fffffff8
	// 0x11111111 00000009
	// 0x2345678a 00000001
	asm volatile (
		//伪指令 cpu不认识 但是编译器认识，编译器会把伪指令替换位2到3条cpu能够认识的指令 执行起来效率就没有mov高
		//r0=0xfffffff8
		"ldr r0, =0xfffffff8\n"
		"mov r1, #9\n"
		//指令+s表示要影响cpsr标志位
		"adds %0, r0, r1\n" //cpsr_C
		
		"ldr r0, =0x12345678\n"
		"ldr r1, =0x11111111\n"
		//%1=r0+r1+C	加进位
		"adc %1, r0, r1\n"
		:"=&r"(sum), "=&r"(sum1)
		:
		:"r0", "r1"
	);

	printf("sum = %#x%08x", sum1, sum);

	return 0;
}




