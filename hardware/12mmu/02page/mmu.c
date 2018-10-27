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

void create_table(unsigned int *ttb1, unsigned int *ttb2)
{
	unsigned int va, pa;
	unsigned int va1;
	// va --> 0 --- 1M - 1
	// va --> 1M ---2M - 1
	for (va = 0; va < 0x80000000; va += 0x100000) {
		//创建一个一级页表条目
		ttb1[va >> 20] = (unsigned int)ttb2 & 0xfffffc00 | 1;
		//创建一个二级页表
		for (va1 = va; va1 < va + 0x100000; va1 += 0x1000) {
			//创建一个二级页表的条目
			pa = va1;
			ttb2[(va1 >> 12) & 0xff] =  (pa & 0xfffff000) | 2;
		}
		ttb2 += 0x100;
	}	

	//设置域0
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
		:"r"(ttb1)
		:
	);
}
//把va所在的虚拟段映射到pa所在物理段
void my_mmap(unsigned int va, unsigned int pa)
{
	//c2 	
	unsigned int *ttb1, *ttb2;	
	unsigned int item1;

	__asm__ __volatile__(
		"mrc p15, 0, %0, c2, c0, 0"
		:"=&r"(ttb1)
		:
		:
	);

	//找到一级页表中的条目
	item1 = ttb1[va >> 20];	
	//通过一级页表条目找到二级页表地址
	ttb2 = (void *)(item1 & 0xfffffc00);
	//修改二级页表的条目
	ttb2[(va >> 12) & 0xff] &= 0xfff;
	ttb2[(va >> 12) & 0xff] |= pa & 0xfffff000;
}







