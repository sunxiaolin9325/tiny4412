#ifndef __MMU_H__
#define __MMU_H__

extern void mmu_enable(void);
extern void mmu_disable(void);
extern void create_table(unsigned int *ttb);
extern void my_mmap(unsigned int va, unsigned int pa);

#endif
