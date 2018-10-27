#include <stdio.h>

int main(void)
{
	//int i = 0, j = 0;
	//
	////gcc 6  1 + 1 + 2 + 2
	//j = i++ + ++i + ++i + i++;
	//printf("i = %d\n j = %d\n", i, j);

/*
	int a = 0;

	__asm__ __volatile__(
		//"add %0, %0, #1\n"
		//:"+r"(a)
		//r0=*%0
		"ldr r0, %0\n"//%0=&a m
		"add r0, #1\n"	
		// *%0=r0
		"str r0, %0\n"
		:
		:"m"(a) // &a
		:"r0", "memory"
	);			

	printf("a = %d\n", a);
*/
	int arr[5] = {1,2,3,4,5};
	
	__asm__ __volatile__(
		"mov r0, %0\n"
		//r1 = *r0
		"ldr r1, [r0]\n"
		"add r1, r1, #1\n"
		// *r0=r1
		"str r1, [r0]\n"

		"add r0, r0, #4\n"
		"ldr r1, [r0]\n"
		"add r1, r1, #1\n"
		"str r1, [r0]\n"

		//r0----->arr[1]
		//r1=*(r0+4)
		"ldr r1, [r0, #4]\n"	
		"add r1, r1, #1\n"
		"str r1, [r0, #4]\n"

		// r0+=8 r1=*r0
		"ldr r1, [r0, #8]!\n"	
		"add r1, r1, #1\n"
		//*r0=r1  r0+=4
		"str r1, [r0], #4\n"
		
		"ldr r1, [r0]\n"
		"add r1, r1, #1\n"
		"str r1, [r0]\n"
		:
		:"r"(arr)
		:"r0", "r1", "memory"
	);

	int i;
 	for (i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	
	return 0;
}















