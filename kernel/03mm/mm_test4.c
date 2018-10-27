#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/dma-mapping.h>

//中断上下文 不允许睡眠
//进程上下文

/*
page
page
page
page
page
*/

static __init int test_init(void)
{
	char *v;
	dma_addr_t paddr;

	//申请dma所要访问的内存
	//一般声卡驱动  framebufeer等需要dma硬件支持的驱动都需要
	v = dma_alloc_coherent(NULL, 480 * 800 * 4, &paddr, GFP_KERNEL); 

	dma_free_coherent(NULL, 480 * 800 * 4, v, paddr);

	return 0;
}


static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
