
arch/arm/kernel/calls.S
	/* 378 yun */   CALL(sys_yun_add)
arch/arm/include/asm/unistd.h
	#define __NR_yun_add        (__NR_SYSCALL_BASE+378)
随便在一个文件中实现这个系统调用，确保能被编译到就行
arch/arm/kernel/sys_arm.c
	asmlinkage int sys_yun_add(int a, int b)
	{
		return a + b;
	}

