#include <mmu.h>
#include <common.h>

void mmu_enable(void)
{
	__asm__ __volatile__(
		"mrc p15, 0, r0, c1, c0, 0\n"
		"orr r0, r0, #1\n"
		"mcr p15, 0, r0, c1, c0, 0\n"
		:::"r0"
	);
}

void mmu_disable(void)
{
	__asm__ __volatile__(
		"mrc p15, 0, r0, c1, c0, 0\n"
		"bic r0, r0, #1\n"
		"mcr p15, 0, r0, c1, c0, 0\n"
		:::"r0"
	);
}

//这个函数调用一次创建一个一级页表的条目
//va和pa要按照1M对齐
//0x12340000------>0x50040000
//0x12300000----->0x50000000
void my_mmap(unsigned int *ttb, unsigned int va, unsigned int pa)
{
	ttb[va >> 20] = (pa & 0xfff00000) | 2;
}

//让虚拟地址和物理地址相等，目的是让uboot活着
void ttb_init(unsigned int *ttb)
{
	unsigned int va, pa;

	for(va = 0; va < 0x80000000; va += 0x100000){
		pa = va;
		my_mmap(ttb, va, pa);
	}

	__asm__ __volatile__(
		//%0---->c2
		//p15 代表要操作的协处理器
		//0  c0  0这三个参数
		"mcr p15, 0, %0, c2, c0, 0\n"
		"mrc p15, 0, r0, c3, c0, 0\n"
		"orr r0, r0, #3\n"
		"mcr p15, 0, r0, c3, c0, 0\n"
		:
		:"r"(ttb)
		:"r0"
	);
}






