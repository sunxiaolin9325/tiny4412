#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/highmem.h>


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
	struct page *page;
	char *v;

	page = alloc_page(GFP_KERNEL | __GFP_HIGH);
	//永久映射
	v = kmap(page);
	memcpy(v, "123456", 6);
	kunmap(page);	
	__free_page(page);	

	page = alloc_page(GFP_KERNEL | __GFP_HIGH);
	//临时映射,环形操作,可能会被覆盖
	v = kmap_atomic(page);
	memcpy(v, "234", 3);	
	__kunmap_atomic(v);
	__free_page(page);	
				
	return 0;
}


static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
