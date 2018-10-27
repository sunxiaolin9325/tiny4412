#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 6;
	int c = 7;

	printf("before a = %d\n", a);
	printf("before b = %d\n", b);
	printf("before c = %d\n", c);

	//要求从大到小排序
	__asm__ __volatile__(
		"cmp %[a], %[b]\n"	
		"movlt r0, %[a]\n"
		"movlt %[a], %[b]\n"
		"movlt %[b], r0\n"

		"cmp %[a], %[c]\n"	
		"movlt r0, %[a]\n"
		"movlt %[a], %[c]\n"
		"movlt %[c], r0\n"

		"cmp %[b], %[c]\n"	
		"movlt r0, %[b]\n"
		"movlt %[b], %[c]\n"
		"movlt %[c], r0\n"

		:[a]"+r"(a), [b]"+r"(b), [c]"+r"(c)
		:
		:"r0"
	);

	printf("after a = %d\n", a);
	printf("after b = %d\n", b);
	printf("after c = %d\n", c);
	
	return 0;	
}



