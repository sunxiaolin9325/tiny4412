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

struct nrf_st {
	int no;
	int light;
	char msg[16];
};

//user process
//-----struct nrf_st--------
//nrf24l01 无线模块
// -----nrf_st---nr_st---nr_st

void ctor(void *data)
{

}

static __init int test_init(void)
{
	struct kmem_cache *kmem;
	struct nrf_st *nrf;

	//ctor 在分配缓存中的每一个对象的时候都会调用，并且会把分配的对象的指针传给这个函数
	kmem = kmem_cache_create("my_cache", sizeof(struct nrf_st), 0, SLAB_HWCACHE_ALIGN, ctor);

	//获得缓存中的对象
	nrf = kmem_cache_alloc(kmem, GFP_KERNEL);
	//释放对象
	kmem_cache_free(kmem, nrf);	
	
	kmem_cache_destroy(kmem);

	return 0;

}


static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
