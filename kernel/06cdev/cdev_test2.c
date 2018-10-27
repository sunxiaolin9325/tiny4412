#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

struct mydev_st {
	char buf[256];
	dev_t no;
	struct cdev dev;
	int count;
};
// /dev/test/mydev
int my_open(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	memset(m->buf, 0, 256);
	//加锁
	m->count++;
	//解锁
	fp->private_data = m;

	//printk("%s\n", __FUNCTION__);
	return 0;
}

int my_close(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	//加锁
	m->count--;
	//解锁

	//printk("%s\n", __FUNCTION__);
	return 0;
}

ssize_t my_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct mydev_st *m;
	int ret;

	m = fp->private_data;

	count = min((int)count, 256);	
	
	ret = copy_to_user(buffer, m->buf, count);
	if (ret) {
		ret = -EFAULT;	
		goto copy_error;
	}

	//printk("%s\n", __FUNCTION__);
	return count;
copy_error:
	return ret;
}

ssize_t my_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	//printk("%s\n", __FUNCTION__);
	
	int ret;
	
	struct mydev_st *m;

	m = fp->private_data;

	count = min((int)count, 256);
	
	ret = copy_from_user(m->buf, buffer, count);
	if (ret) {
		ret = -EFAULT;
		goto copy_error;
	}
	
	return count;
copy_error:
	return ret;
}

long my_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	printk("%s %u %ld\n", __FUNCTION__, cmd, arg);

	return 0;
}

struct file_operations my_ops = {
	.open = my_open,
	.release = my_close,
	.write = my_write,
	.read = my_read,
	.unlocked_ioctl = my_ioctl,
};

struct mydev_st *mydev;

//当模块安装的时候执行
static __init int test_init(void)
{
	int ret;
	
	mydev = kzalloc(sizeof(*mydev), GFP_KERNEL);
	if (!mydev) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	ret = alloc_chrdev_region(&mydev->no, 1, 1, "mydev");
	if (ret < 0) {
		goto alloc_no_error;
	}

	cdev_init(&mydev->dev, &my_ops);
	ret = cdev_add(&mydev->dev, mydev->no, 1);
	if (ret < 0) {
		goto cdev_add_error;
	}

	printk("major=%d minor=%d\n", MAJOR(mydev->no), MINOR(mydev->no));
	
	return 0;
cdev_add_error:
	unregister_chrdev_region(mydev->no, 1);
alloc_no_error:
	kfree(mydev);
alloc_dev_error:
	return ret;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	cdev_del(&mydev->dev);
	unregister_chrdev_region(mydev->no, 1);
	kfree(mydev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










