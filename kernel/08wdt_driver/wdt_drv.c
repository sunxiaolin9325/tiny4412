#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/clk.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/spinlock.h>

struct wdt_st {
	int wtcon, wtcnt;
	void *__iomem v;	
	struct clk *clk;

	dev_t no;
	struct cdev dev;
	struct file_operations wdt_ops;

	spinlock_t lock;
	
	int count;
};

struct wdt_feed_st {
	int time;
};

#define EXYNOS4_PA_WDT  0x10060000
#define WTCON		0x00
#define WTCNT		0x08

//===和硬件相关===============

void exynos4_wdt_init(struct wdt_st *w)
{
	// 100M / (99 + 1) / 64 = 15625HZ
	w->wtcon = (99 << 8) | (2 << 3) | 1;
	w->wtcnt = 15625 * 3; // < 65535
	
	iowrite32(w->wtcon, w->v + WTCON);
	iowrite32(w->wtcnt, w->v + WTCNT);
}

void exynos4_wdt_exit(struct wdt_st *w)
{

}

void exynos4_wdt_enable(struct wdt_st *w)
{
	w->wtcon = ioread32(w->v + WTCON);
	w->wtcon |= 1 << 5;
	iowrite32(w->wtcon, w->v + WTCON);
}

void exynos4_wdt_disable(struct wdt_st *w)
{
	w->wtcon = ioread32(w->v + WTCON);
	w->wtcon &= ~(1 << 5);
	iowrite32(w->wtcon, w->v + WTCON);
}

void exynos4_feed_wdt(struct wdt_st *w, int ms)
{
	iowrite32(ms, w->v + WTCNT);
}

//===和硬件无关============

//关于硬件时钟的打开和关闭
//arch/arm/mach-exynos/clock-exynos4.c
//#include <linux/clk.h>
//
//clk = clk_get(NULL, "watchdog");
//clk_enable(clk);
//
//clk_disable(clk);
//clk_put(clk);

int wdt_open(struct inode *no, struct file *fp)
{
	struct wdt_st *w;

	w = container_of(no->i_cdev, struct wdt_st, dev);	
	fp->private_data = w;

	spin_lock(&w->lock);
	if (w->count) {
		spin_unlock(&w->lock);
		return -EBUSY;	
	}

	w->count = 1;

	spin_unlock(&w->lock);	

	return 0;
}

int wdt_close(struct inode *no, struct file *fp)
{
	struct wdt_st *w;

	w = fp->private_data;

	spin_lock(&w->lock);
	if (w->count == 0) {
		spin_unlock(&w->lock);
		return -ENODEV;
	}	

	w->count = 0;

	spin_unlock(&w->lock);

	return 0;
}

ssize_t wdt_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	struct wdt_st *w;
	struct wdt_feed_st wfs;
	int ret;

	if (count != sizeof(wfs)) {
		return -EINVAL;
	}

	w = fp->private_data;
	
	ret = copy_from_user(&wfs, buffer, sizeof(wfs));	
	if (ret) {
;		ret = -EFAULT;
		goto copy_error;
	}

	exynos4_feed_wdt(w, wfs.time);
		
	return count;
copy_error:
	return ret;
}
//cmd : 0 disable
//cmd : 1 enable
long wdt_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	struct wdt_st *w;

	w = fp->private_data;

	switch (cmd) {
		case 0:
			exynos4_wdt_disable(w);
			break;
		case 1:
			exynos4_wdt_enable(w);
			break;
		default:
			break;
	}

	return 0;
}

struct wdt_st *wdt;

static __init int test_init(void)
{
	int ret;

	wdt = kzalloc(sizeof(*wdt), GFP_KERNEL);
	if (!wdt) {
		ret = -ENOMEM;
		goto alloc_wdt_error;
	}

	// proc/devices
	ret = alloc_chrdev_region(&wdt->no, 1, 1, "mywdt");
	if (ret) {
		goto alloc_no_error;
	}

	wdt->wdt_ops.open = wdt_open;
	wdt->wdt_ops.release = wdt_close;
	wdt->wdt_ops.write = wdt_write;
	wdt->wdt_ops.unlocked_ioctl = wdt_ioctl;

	cdev_init(&wdt->dev, &wdt->wdt_ops);

	ret = cdev_add(&wdt->dev, wdt->no, 1);
	if (ret) {
		goto cdev_add_error;
	}

	wdt->v = ioremap(EXYNOS4_PA_WDT, SZ_4K);
	if (!wdt->v) {
		ret = -ENOMEM;
		goto ioremap_error;
	}

	spin_lock_init(&wdt->lock);

	wdt->clk = clk_get(NULL, "watchdog");
	clk_enable(wdt->clk);

	exynos4_wdt_init(wdt);

	return 0;
ioremap_error:
	cdev_del(&wdt->dev);
cdev_add_error:
	unregister_chrdev_region(wdt->no, 1);
alloc_no_error:
	kfree(wdt);
alloc_wdt_error:
	return ret;
}

static __exit void test_exit(void)
{
	exynos4_wdt_exit(wdt);
	clk_disable(wdt->clk);	
	clk_put(wdt->clk);
	iounmap(wdt->v);
	cdev_del(&wdt->dev);
	unregister_chrdev_region(wdt->no, 1);
	kfree(wdt);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");








