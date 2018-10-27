#include <stdio.h>

int main(void)
{
	int lsl, lsr, asr, ror;
	int tmp;

	__asm__ __volatile__(
		"mov r0, #20\n"
		"mov %0, r0, lsl #1\n"//%0=r0<<1  40
		"mov %1, r0, lsr #1\n"//%1=r0>>>1 10
		"mov r0, #-20\n"
		// 00000...10100
		// 10000...10100
		// 111111...0110
		// 100000...1010
		"mov %2, r0, lsr #1\n"
		"mov %3, r0, asr #1\n"
		"mov r0, #0xff\n" // 0x000000ff
		// 110101010....111
		// 11110101010....1
		"mov %4, r0, ror #4\n"
		:"=&r"(lsl), "=&r"(lsr), "=&r"(tmp), "=&r"(asr), "=&r"(ror)
		:
		:"r0"
	);

	printf("lsl = %d\n", lsl);//40
	printf("lsr = %d\n", lsr);//10
	printf("asr = %d\n", asr);//-10
	printf("tmp = %d\n", tmp);//+
	printf("ror = %#x\n", ror);//0xf000000f

	return 0;
}
