#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <asm/uaccess.h>

#include <linux/proc_fs.h>


// fd = open("/proc/uplooking/123.txt", O_RDONLY);
// read(fd, buf, sizeof(buf));-->syscall->swi
//
// 内核函数 -----> read_my_file

struct my_dev_st {
	char buf[1024];
	int len;
	struct proc_dir_entry *my_dir;
	struct proc_dir_entry *my_file;
};

int read_my_file(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	struct my_dev_st *d;

	d = data;

	if (off > d->len - 1) {
		*eof = 1;
		return 0;
	}

	count = min(count, d->len - (int)off);

	sprintf(page, d->buf + off, count);

	*start = (void *)count;

	return count;
}

//fd = open("/proc/uplooking/123", O_RDWR);
// write(fd, buf, len);
// fd--->file
// buf-->buffer
// len-->count
// my_file->data ---> data
int write_my_file(struct file *file, const char __user *buffer, unsigned long count, void *data)
{
	struct my_dev_st *d;
	int ret;

	d = data;	

	count = min((int)count, 1024);

	ret = copy_from_user(d->buf, buffer, count);
	if (ret) {
		return -EFAULT;	
	}

	d->len = count;
	
	return count;		
}


struct my_dev_st *my_dev;

static __init int test_init(void)
{
	int ret;

	my_dev = kzalloc(sizeof(*my_dev), GFP_KERNEL);	
	if (!my_dev) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	my_dev->my_dir = proc_mkdir("uplooking", NULL);
	if (!my_dev->my_dir) {
		ret = -ENOMEM;
		goto mkdir_uplooking_error;
	}

	my_dev->my_file = create_proc_entry("123", 0, my_dev->my_dir);
	if (!my_dev->my_file) {
		ret = -ENOMEM;
		goto create_123_error;
	}

	my_dev->my_file->read_proc = read_my_file;
	my_dev->my_file->write_proc = write_my_file;
	my_dev->my_file->data = my_dev;
	
	return 0;
create_123_error:
	remove_proc_entry("uplooking", NULL);
mkdir_uplooking_error:
	kfree(my_dev);	
alloc_dev_error:
	return ret;
}
//在init函数越后做的操作它的反操作在exit函数越先做
static __exit void test_exit(void)
{
	remove_proc_entry("123", my_dev->my_dir);
	remove_proc_entry("uplooking", NULL);
	kfree(my_dev);	
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
