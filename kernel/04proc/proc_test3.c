#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <asm/uaccess.h>
#include <linux/list.h>

#include <linux/proc_fs.h>


// fd = open("/proc/uplooking/123.txt", O_RDONLY);
// read(fd, buf, sizeof(buf));-->syscall->swi
//
// 内核函数 -----> read_my_file

struct head_st {
	//表示所有节点数据量的总和
	int count;
	struct list_head h;
}head;

struct item_st {
	//表示该节点中的数据量
	int len;
	//指向该节点包含的数据
	char *content;
	
	struct list_head i;
};


int read_my_file(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	struct list_head *tmp;
	struct item_st *item;
	int all = 0;

	if (off > head.count - 1) {
		*eof = 1;
		return 0;
	}
	
	list_for_each(tmp, &head.h) {
		item = list_entry(tmp, struct item_st, i);	
		if (item->len + all > off) {
			count = min(count, item->len - ((int)off - all));
			memcpy(page, item->content + (off - all), count);
			break;

		}	
		all += item->len;
	}
	
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
	struct item_st *item;
	int ret;

	//good operation
	item = kzalloc(sizeof(*item) + count, GFP_KERNEL);	
	if (!item) {
		ret = -ENOMEM;
		goto alloc_item_error;
	}
	
	item->content = (void *)(item + 1);
	item->len = count;

	ret = copy_from_user(item->content, buffer, count);
	if (ret) {
		ret = -EFAULT;
		goto copy_data_error;
	}

	head.count += item->len;	

	list_add_tail(&item->i, &head.h);
	
	return count;		
copy_data_error:
	kfree(item);
alloc_item_error:
	return ret;
}

struct proc_dir_entry *my_dir, *my_file;

static __init int test_init(void)
{
	int ret;

	my_dir = proc_mkdir("uplooking", NULL);
	if (!my_dir) {
		ret = -ENOMEM;
		goto mkdir_uplooking_error;
	}

	my_file = create_proc_entry("123", 0, my_dir);
	if (!my_file) {
		ret = -ENOMEM;
		goto create_123_error;
	}

	my_file->read_proc = read_my_file;
	my_file->write_proc = write_my_file;

	//linux_src/include/linux/list.h
	INIT_LIST_HEAD(&head.h);
	
	return 0;
create_123_error:
	remove_proc_entry("uplooking", NULL);
mkdir_uplooking_error:
	return ret;
}
//在init函数越后做的操作它的反操作在exit函数越先做
static __exit void test_exit(void)
{
	remove_proc_entry("123", my_dir);
	remove_proc_entry("uplooking", NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
