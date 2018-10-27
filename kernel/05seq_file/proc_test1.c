#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/seq_file.h>

struct head_st {
	//表示所有节点数据量的总和
	int count;
	int times;
	struct list_head h;
}head;

struct item_st {
	//表示该节点中的数据量
	int len;
	//指向该节点包含的数据
	char *content;
	int no;
	
	struct list_head i;
};

void *find_item(loff_t pos)
{
	struct list_head *tmp;
	struct item_st *item;

	list_for_each(tmp, &head.h) {
		item = container_of(tmp, struct item_st, i);
		if (item->no == pos) {
			return item;
		}
	}	

	return NULL;
}

// write(fd, buf, len)
// fd---->fp
// buf--->buffer
// len--->count
ssize_t my_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	struct item_st *item;
	int ret;

	//这个方法不错
	item = kzalloc(sizeof(*item) + count, GFP_KERNEL);
	if (!item) {
		ret = -ENOMEM;
		goto alloc_item_error;
	}
	
	item->content = (void *)(item + 1);
	item->len = count;
	item->no = head.times;
	head.times++;

	ret = copy_from_user(item->content, buffer, count);
	if (ret) {
		ret = -EFAULT;
		goto copy_data_error;
	}

	item->content[count - 1] = 0;

	//head.count在这个程序中不起作用
	head.count += item->len;	

	list_add_tail(&item->i, &head.h);
	
	return count;		
copy_data_error:
	kfree(item);
alloc_item_error:
	return ret;
}

// *pos = 0;
void *my_start(struct seq_file *m, loff_t *pos)
{
	return find_item(*pos);
}

void my_stop(struct seq_file *m, void *v)
{
}

void *my_next(struct seq_file *m, void *v, loff_t *pos)
{
	(*pos)++;

	return find_item(*pos);
}

int my_show(struct seq_file *m, void *v)
{
	struct item_st *item = v;

	//return seq_write(m, item->content, item->len);
	return seq_printf(m, "%s", item->content);
}

//这个结构体中的方法是提供给seq_read调用的
// start--->show--->next--->show--->next--->show.....----->stop
struct seq_operations seq_ops = {
	//开始读，返回第一个数据的地址
	.start = my_start,
	//把要返回给用户的数据放到buf中
	.show = my_show,
	//返回下一个数据的地址
	.next = my_next,
	//结束
	.stop =  my_stop,
};

// /proc/uplooking/123
int my_open(struct inode *no, struct file *fp)
{
	struct seq_file *sf;
	int ret;

	//自己分配seq_file	
	sf = kzalloc(sizeof(*sf), GFP_KERNEL);
	if (!sf) {
		ret = -ENOMEM;
		goto alloc_file_error;	
	}

	sf->buf = kzalloc(SZ_8K, GFP_KERNEL);
	if (!sf->buf) {
		ret = -ENOMEM;
		goto alloc_buf_error;
	}
	
	sf->size = SZ_8K;	

	fp->private_data = sf;

	//打开seq_file seq_read
	ret = seq_open(fp, &seq_ops);
	if (ret) {
		goto open_error;
	}
	
	return 0;
open_error:
	kfree(sf->buf);	
alloc_buf_error:
	kfree(sf);
alloc_file_error:
	return ret;
}

// open ----> my_open ---->seq_open
// close----> seq_close
// read-----> seq_read
// write----> my_write
struct file_operations my_ops = {
	//自己实现 
	.open = my_open,
	.release = seq_release,
	.read = seq_read,
	//自己实现
	.write = my_write,
};

struct proc_dir_entry *my_dir;
struct proc_dir_entry *my_file;

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

	//NULL = file->private_data
	//在my_open中修改
	my_file = proc_create_data("123", 0, my_dir, &my_ops, NULL);
	if (!my_file) {
		ret = -ENOMEM;
		goto create_file_error;
	}

	INIT_LIST_HEAD(&head.h);	//忘了初始化,内核崩溃

	return 0;
create_file_error:
	remove_proc_entry("uplooking", NULL);
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
