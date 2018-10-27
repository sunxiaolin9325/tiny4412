#define _GNU_SOURCE      
#include <unistd.h>
#include <sys/syscall.h>  
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

//内核中为每一个系统调用都编号
//<linux_src>/arch/arm/include/asm/unistd.h
//2 fork
//3 read
//4 write

int main(void)
{
	char *s = "hello syscall\n";
	int ret;
	
	write(1, s, strlen(s));
	syscall(4, 1, s, strlen(s));
	//对于arm平台系统调用号有一个0x900000的偏移
	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, %1\n"
		"mov r2, #14\n"
		"swi 0x900004\n"//进入内核
		//返回值在r0
		"mov %0, r0\n"
		:"=&r"(ret)
		:"r"(s)
		:"r0", "r1", "r2"
	);

	printf("ret = %d\n", ret);

	return 0;
}





