#include <stdio.h>


//APCS  arm过程调用标准,不用语言之间的相互调用
//  1.编译器
//  2.自己写的程序
//
//  内容：
//	1.参数传递  r0,r1,r2,r3  从第五个参数开始按照顺序入栈（越靠后的参数越先入栈）
//	2.满递减  fd
//	3.返回值 r0  r1r0

int main(void)
{
	int flag;
/*
	__asm__ __volatile__(
		"mov %0, #1\n"
		"b end\n"
		"mov %0, #2\n"
		"end:\n"
		:"=&r"(flag)
		:
		:
	);

	printf("flag = %d\n", flag);
*/
	__asm__ __volatile__(
		"mov r0, #6\n"
		"mov r1, #5\n"
		"push {r0,r1}\n"
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r3, #4\n"
		//hello(1,2,3,4,5,6);
		"bl hello\n"//在跳转之前会把下一条指令的地址保存到lr(R14)
		"mov %0, r0\n"
		//"pop {r0, r1}"
		"add sp, sp, #8\n"
		:"=&r"(flag)
		:
		:"r0"
	);

	printf("flag = %d\n", flag);

	return 0;
}

int hello(int a, int b, int c, int d, int e, int f)
{
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("e = %d\n", e);
	printf("f = %d\n", f);

	return a + b + c + d + e + f;
}

//模拟一个函数
//__asm__(
//	"hello:\n"	
//	"add r0, r0, r1\n"
//	//返回
//	//"mov pc, lr\n"
//	"bx lr\n"
//);


