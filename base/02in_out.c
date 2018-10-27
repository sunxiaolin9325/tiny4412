#include <stdio.h>

int main(void)
{
	int a, b, c;

	asm volatile (
		//[] 标号 用标号来匹配变量
		"mov %[a], #1\n"		
		"mov %[b], #2\n"		
		:[a]"=&r"(a), "=&r"(c), [b]"=&r"(b)
		:
		:
	);
	
	printf("a = %d b = %d\n", a, b);

	return 0;
}
