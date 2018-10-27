#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

static __init int test_init(void)
{
	return 0;
}

static __exit void test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");

int my_print(int no)
{
	int i;

	for (i = 0; i < no; i++) {
		printk("no = %d\n", no);
	}

	return 100;
}
EXPORT_SYMBOL(my_print);



