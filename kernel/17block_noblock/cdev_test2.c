#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/spinlock.h>

struct mydev_st {
	char buf[256];
	dev_t no;
	struct cdev dev;
	int count;

#define HAVE_DATA	0
#define NO_DATA		1
	int flag;	

	spinlock_t lock;

	wait_queue_head_t rq, wq;
};
// /dev/test/mydev
int my_open(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	memset(m->buf, 0, 256);
	fp->private_data = m;

	spin_lock(&m->lock);
	//if (m->count) {
	//	spin_unlock(&m->lock);
	//	return -EBUSY;
	//}
	//m->count = 1;
	m->count++;
	spin_unlock(&m->lock);

	return 0;
}

int my_close(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	spin_lock(&m->lock);
	//if (!m->count) {
	//	spin_unlock(&m->lock);
	//	return -ENODEV;
	//}
	//m->count = 0;
	m->count--;
	spin_unlock(&m->lock);

	return 0;
}

// open("/dev/test/mydev", O_RDWR | O_NONBLOCK);
// open("/dev/test/mydev", O_RDWR);
ssize_t my_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct mydev_st *m;
	int ret;

	m = fp->private_data;

	while (m->flag == NO_DATA) {
		if (fp->f_flags & O_NONBLOCK) {
			//非阻塞访问
			return -EAGAIN;
		} else {
			//阻塞访问
			//进程睡眠
			wait_event(m->rq, m->flag == HAVE_DATA);	
		}
	}

	//1,内核栈过大,不安全 2,比较参数不合适
	count = min((int)count, 256);	
	
	ret = copy_to_user(buffer, m->buf, count);
	if (ret) {
		ret = -EFAULT;	
		goto copy_error;
	}

	m->flag = NO_DATA;

	//唤醒写者
	wake_up(&m->wq);		

	return count;
copy_error:
	return ret;
}

ssize_t my_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	int ret;
	struct mydev_st *m;

	m = fp->private_data;
	
	while (m->flag == HAVE_DATA) {
		if (fp->f_flags & O_NONBLOCK) {
			//非阻塞访问
			return -EAGAIN;
		} else {
			//阻塞访问
			//进程睡眠
			wait_event(m->wq, m->flag == NO_DATA);	
		}
	}

	count = min((int)count, 256);
	
	ret = copy_from_user(m->buf, buffer, count);
	if (ret) {
		ret = -EFAULT;
		goto copy_error;
	}

	m->flag = HAVE_DATA;
	
	//唤醒读者
	wake_up(&m->rq);
	
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

	mydev->flag = NO_DATA;

	ret = alloc_chrdev_region(&mydev->no, 1, 1, "mydev");
	if (ret < 0) {
		goto alloc_no_error;
	}

	cdev_init(&mydev->dev, &my_ops);
	ret = cdev_add(&mydev->dev, mydev->no, 1);
	if (ret < 0) {
		goto cdev_add_error;
	}
	
	spin_lock_init(&mydev->lock);

	init_waitqueue_head(&mydev->rq);
	init_waitqueue_head(&mydev->wq);

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










