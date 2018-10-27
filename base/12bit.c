#include <stdio.h>

int main(void)
{
	/* LED 3  ==1  ==0
 *	LED |= 1 << 3
 *		mov r0, #8
 *		orr LED, LED, r0
 *	LED &= ~(1 << 3); 
 *		mvn r0, #8
 *		and LED, LED, r0
 *
 * 		    LED =LED & ~(8)
 *		bic LED, LED, #8
 *
 */
	int and, orr, eor, bic;

	//mvn r0, #0xff  r0=~0x000000ff=0xffffff00

	__asm__ __volatile__(
		"mov r0, #5\n"// 0000..0101
		"mov r1, #6\n"// 0000..0110
		//and r0, r0, r1
		//and r0, r1
		//%0=r0&r1
		"and %0, r0, r1\n"//4
		"orr %1, r0, r1\n"//7
		"eor %2, r0, r1\n"//3
		"mov r0, #0xff\n" // 0xfb  1111 1011
		"bic %3, r0, #(1 << 2)\n"
		:"=&r"(and), "=&r"(orr), "=&r"(eor), "=&r"(bic)
		:
		:"r0", "r1"
	);

	printf("and = %d\n", and);
	printf("orr = %d\n", orr);
	printf("eor = %d\n", eor);
	printf("bic = %#x\n", bic);

	return 0;
}




