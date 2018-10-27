#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/proc_fs.h>

struct proc_dir_entry *my_dir;
struct proc_dir_entry *my_file;

// fd = open("/proc/uplooking/123.txt", O_RDONLY);
// read(fd, buf, sizeof(buf));-->syscall->swi
//
// 内核函数 -----> read_my_file
// page 由内核分配的4K

char buf[10] = {'1', '2', '3', '4', '5', '6', '7', 'a', 'b', 'c'};

//1.
//read(fd, buf, 5); off=0
//read(fd, buf, 3); off=5

//read(fd, buf, 100);off=0

int read_my_file(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	if (off > 9) {
		*eof = 1;
		return 0;
	}

	count = min(count, 10 - (int)off);
//33333333333
	*start = page + off;
	sprintf(*start, buf + off, count);

	return count;
//2222222222222
/*
	sprintf(page, buf + off, count);

	*start = (void *)count;

	return count;
*/
//111111111111
/*
	sprintf(page + off, buf + off, count);
	
	return count + off;
*/
}

static __init int test_init(void)
{
	int ret;
	//  /mnt/uplooking
	//  /proc/uplooking
	my_dir = proc_mkdir("uplooking", NULL);
	if (!my_dir) {
		return -ENOMEM;
	}	

	//创建一个只读型的文件
	my_file = create_proc_read_entry("123.txt", 0, my_dir, read_my_file, (void *)0x1234);
	if (!my_file) {
		ret = -ENOMEM;
		goto create_file_error;
	}

	return 0;
create_file_error:
	remove_proc_entry("uplooking", NULL);
	return ret;
}
//在init函数越后做的操作它的反操作在exit函数越先做
static __exit void test_exit(void)
{
	remove_proc_entry("123.txt", my_dir);
	remove_proc_entry("uplooking", NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
