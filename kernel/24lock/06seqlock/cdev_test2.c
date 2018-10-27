#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/gpio.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <mach/gpio.h>
#include <linux/semaphore.h>
#include <linux/mutex.h>
#include <linux/seqlock.h>

struct mydev_st {
	char buf[256];
	dev_t no;
	struct cdev dev;
	
	atomic_t count;

	spinlock_t lock;
	
	struct semaphore sem;

	struct completion com;

	struct mutex mutex;	
	
	seqlock_t slock;

	int irq;
};
// /dev/test/mydev
int my_open(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	memset(m->buf, 0, 256);
	//m->count.couner++;
	atomic_add(1, &m->count);
	fp->private_data = m;

	//printk("%s\n", __FUNCTION__);
	return 0;
}

int my_close(struct inode *no, struct file *fp)
{
	struct mydev_st *m;

	m = container_of(no->i_cdev, struct mydev_st, dev);
	atomic_sub(1, &m->count);

	//printk("%s\n", __FUNCTION__);
	return 0;
}

ssize_t my_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct mydev_st *m;
	int ret;
	int start;

	m = fp->private_data;

	count = min((int)count, 256);	
	
	//当读的过程中有写着进入,则重新读
	do {
		start = read_seqbegin(&m->slock);
		ret = copy_to_user(buffer, m->buf, count);
		if (ret) {
			ret = -EFAULT;	
			goto copy_error;
		}
	} while (read_seqretry(&m->slock, start));

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
	
	write_seqlock(&m->slock);
	ret = copy_from_user(m->buf, buffer, count);
	if (ret) {
		ret = -EFAULT;
		write_sequnlock(&m->slock);
		goto copy_error;
	}

	write_sequnlock(&m->slock);
	return count;
copy_error:
	return ret;
}

long my_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	printk("%s %u %ld\n", __FUNCTION__, cmd, arg);

	return 0;
}

irqreturn_t irq_handler(int irq, void *data)
{
	struct mydev_st *m;

	m = data;

	//spin_lock(&m->lock);

	memcpy(m->buf, "nihao", 5);
	
	//spin_unlock(&m->lock);

	return IRQ_HANDLED;	
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

	mydev->count.counter = 0;
	spin_lock_init(&mydev->lock);
	sema_init(&mydev->sem, 1);
	init_completion(&mydev->com);
	mutex_init(&mydev->mutex);
	seqlock_init(&mydev->slock);

	ret = alloc_chrdev_region(&mydev->no, 1, 1, "mydev");
	if (ret < 0) {
		goto alloc_no_error;
	}

	cdev_init(&mydev->dev, &my_ops);
	ret = cdev_add(&mydev->dev, mydev->no, 1);
	if (ret < 0) {
		goto cdev_add_error;
	}

	mydev->irq = gpio_to_irq(EXYNOS4_GPX3(2));
	ret = request_irq(mydev->irq, irq_handler, IRQF_TRIGGER_FALLING, "haha", mydev);
	/* if errer */

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
	free_irq(mydev->irq, mydev);
	cdev_del(&mydev->dev);
	unregister_chrdev_region(mydev->no, 1);
	kfree(mydev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










