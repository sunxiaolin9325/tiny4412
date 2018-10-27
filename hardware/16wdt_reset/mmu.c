#include <common.h>
#include <mmu.h>

// cp15 arm=cp15 mmu cache tcm ....

void mmu_enable(void)
{
	__asm__ __volatile__(
		//r4=c1
		"mrc p15, 0, r4, c1, c0, 0\n"
		"orr r4, r4, #1\n"
		//c1=r4
		"mcr p15, 0, r4, c1, c0, 0\n"
		:::"r4"
	);		
}

void mmu_disable(void)
{
	__asm__ __volatile__(
		//r4=c1
		"mrc p15, 0, r4, c1, c0, 0\n"
		//r4 = r4 & ~(1)
		"bic r4, r4, #1\n"
		//c1=r4
		"mcr p15, 0, r4, c1, c0, 0\n"
		:::"r4"
	);		
}

void create_table(unsigned int *ttb)
{
	unsigned int va, pa;
	// va --> 0 --- 1M - 1
	// va --> 1M ---2M - 1
	for (va = 0; va < 0x80000000; va += 0x100000) {
		pa = va;
		ttb[va >> 20] = (pa & 0xfff00000) | 2;
	}	

	//设置域
	__asm__ __volatile__(
		"mrc p15, 0, r4, c3, c0, 0\n"
		"orr r4, r4, #3\n"
		"mcr p15, 0, r4, c3, c0, 0\n"	
		:::"r4"
	);
	//把ttb填写到c2	
	__asm__ __volatile__(
		//c2=%0=ttb
		"mcr p15, 0, %0, c2, c0, 0\n"
		:
		:"r"(ttb)
		:
	);
}
//把va所在的虚拟段映射到pa所在物理段
void my_mmap(unsigned int va, unsigned int pa)
{
	//c2 	
	unsigned int *ttb;	

	__asm__ __volatile__(
		"mrc p15, 0, %0, c2, c0, 0"
		:"=&r"(ttb)
		:
		:
	);

	ttb[va >> 20] = (pa & 0xfff00000) | 2;
}







