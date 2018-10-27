#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

int my_print(int no)
{
	int i;

	for (i = 0; i < no; i++) {
		printk("no = %d\n", no);
	}

	return 100;
}
