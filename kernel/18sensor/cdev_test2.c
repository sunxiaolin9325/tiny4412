#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/wait.h>

struct mydev_st {
	char buf[256];
	dev_t no;
	struct cdev dev;
	int count;

	int irq;

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
		//	wait_event(m->rq, m->flag == HAVE_DATA);	
			ret = wait_event_interruptible(m->rq, m->flag == HAVE_DATA);	
			if (ret < 0) {
				return -EINTR;
			}
		}
	}

	count = min((int)count, 10);	
	
	ret = copy_to_user(buffer, m->buf, count);
	if (ret) {
		ret = -EFAULT;	
		goto copy_error;
	}

	m->flag = NO_DATA;

	return count;
copy_error:
	return ret;
}

struct file_operations my_ops = {
	.open = my_open,
	.release = my_close,
	.read = my_read,
};

irqreturn_t read_sensor(int irq, void *data)
{
	//如果读传感器的操作有可能睡眠的话，这里需要使用中断下半部分（工作队列）
	
	struct mydev_st *m;
	static int a = 0;

	m = data;
	
	//把传感器的数据读到设备的缓存中
	sprintf(m->buf, "%010d", a++);	

	m->flag = HAVE_DATA;

	wake_up(&m->rq);
	
	return IRQ_HANDLED;
}

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
	
	mydev->irq = gpio_to_irq(EXYNOS4_GPX3(2));
	
	ret = request_irq(mydev->irq, read_sensor, IRQF_TRIGGER_FALLING, "sensor", mydev);
	if (ret) {
		goto request_irq_error;
	}

	printk("major=%d minor=%d\n", MAJOR(mydev->no), MINOR(mydev->no));
	
	return 0;
request_irq_error:
	cdev_del(&mydev->dev);
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










