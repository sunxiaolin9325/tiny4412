#ifndef LZY_MMU_H
#define LZY_MMU_H

extern void mmu_enable(void);
extern void mmu_disable(void);
extern void my_mmap(unsigned int *ttb, unsigned int va, unsigned int pa);
extern void ttb_init(unsigned int *ttb);

#endif






