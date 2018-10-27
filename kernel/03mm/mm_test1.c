#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>

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
	//大
	//GFP_KERNEL在分配内存的时候允许睡眠
	//GFP_ATOMIC在分配内存的时候不允许睡眠
	//page = alloc_pages(GFP_KERNEL, 1);
	page = alloc_page(GFP_KERNEL);
	//默认是normal区,已经映射好的,不用反操作
	v = page_address(page);	
	//v p
	//0xc0000000----0x40000000+0x80000000
	memcpy(v, "123456", 6);	
	//__free_pages(page, 1);	
	__free_page(page);	
				
	
	//v = (void *)__get_free_pages(GFP_KERNEL, 1);	
	v = (void *)__get_free_page(GFP_KERNEL);	
	memcpy(v, "123456", 6);	
	//free_pages((unsigned long)v, 1);	
	free_page((unsigned long)v);	

	return 0;
}


static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
