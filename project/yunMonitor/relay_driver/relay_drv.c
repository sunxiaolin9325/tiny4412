#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/slab.h>
#include <asm/uaccess.h>

#include <asm/io.h>	//ioremap

#include "relay.h"

/******************硬件相关******************/
void exynos4_relay_init(struct relay_st *r)
{
	//初始化4个继电器 输出模式,高电平
	r->relaycon = readl(r->v_relay + GPX3CON);
	r->relaycon &= ~0xffff << 8;
	r->relaycon |= 0x1111 << 8;
	writel(r->relaycon, r->v_relay + GPX3CON);

	r->relaydat = readl(r->v_relay + GPX3DAT);
	r->relaydat |= 0xf << 2;
	writel(r->relaydat, r->v_relay + GPX3DAT);

	//初始化2个蜂鸣器 输出模式,低电平
	r->buzzercon = readl(r->v_buzzer + GPD0CON);
	r->buzzercon &= ~0xff;
	r->buzzercon |= 0x11;
	writel(r->buzzercon, r->v_buzzer + GPD0CON);

	r->buzzerdat = readl(r->v_buzzer + GPD0DAT);
	r->buzzerdat &= ~(0x3);
	writel(r->buzzerdat, r->v_buzzer + GPD0DAT);
}

void exynos4_relay_exit(struct relay_st *r)
{
	//恢复高电平
	r->relaydat = readl(r->v_relay + GPX3DAT);
	r->relaydat |= 0xf << 2;
	writel(r->relaydat, r->v_relay + GPX3DAT);

	//恢复低电平
	r->buzzerdat = readl(r->v_buzzer + GPD0DAT);
	r->buzzerdat &= ~(0x3);
	writel(r->buzzerdat, r->v_buzzer + GPD0DAT);
}

void exynos4_relay_on(struct relay_st *r, int no)
{
	if (no >= 0 && no < 4) {
		//指定继电器工作
		r->relaydat = readl(r->v_relay + GPX3DAT);
		r->relaydat &= ~(1 << (2 + no));
		writel(r->relaydat, r->v_relay + GPX3DAT);
	} else if (no >= 4 && no < NUM) {
		//指定蜂鸣器工作
		r->buzzerdat = readl(r->v_buzzer + GPD0DAT);
		r->buzzerdat |= (1 << (no - 4));
		writel(r->buzzerdat, r->v_buzzer + GPD0DAT);
	}
}

void exynos4_relay_off(struct relay_st *r, int no)
{
	if (no >= 0 && no < 4) {
		r->relaydat = readl(r->v_relay + GPX3DAT);
		r->relaydat |= (1 << (2 + no));
		writel(r->relaydat, r->v_relay + GPX3DAT);
	} else if (no >= 4 && no < 6) {
		r->buzzerdat = readl(r->v_buzzer + GPD0DAT);
		r->buzzerdat &= ~(1 << (no - 4));
		writel(r->buzzerdat, r->v_buzzer + GPD0DAT);
	}
}

/*******************硬件无关******************/
struct relay_st *relay;

int relay_open(struct inode *no, struct file *fp)
{
	spin_lock(&relay->lock);
	if (relay->count) {
		spin_unlock(&relay->lock);
		return -EBUSY;
	}
	relay->count = 1;
	spin_unlock(&relay->lock);
	return 0;
}

int relay_close(struct inode *no, struct file *fp)
{
	spin_lock(&relay->lock);
	if (!relay->count) {
		spin_unlock(&relay->lock);
		return -ENODEV;	
	}
	relay->count = 0;
	spin_unlock(&relay->lock);

	return 0;
}

ssize_t relay_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	int ret;
	struct relay_pro_st pro;

	if (count != sizeof(pro)) {
		return -EINVAL;
	}

	ret = copy_from_user(&pro, buffer, sizeof(pro));
	if (ret) {
		return -EFAULT;
	}

	//根据用户态指定继电器/蜂鸣器/工作/不工作
	if (pro.work == 1) {
		exynos4_relay_on(relay, pro.no);
	} else if(pro.work == 0) {
		exynos4_relay_off(relay, pro.no);
	}

	return count;
}

//复位专用
long relay_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	int i;

	for (i=0; i<NUM; i++) {
		exynos4_relay_off(relay, i);
	}
	
	return 0;
}

//当模块安装的时候执行
static __init int relay_init(void)
{
	int ret;
	
	//分配设配结构体
	relay = kzalloc(sizeof(*relay), GFP_KERNEL);
	if (!relay) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	//物理地址映射到虚拟地址
	relay->v_relay = ioremap(RELAY_BASE, SZ_4K);
	if (!relay->v_relay) {
		ret = -ENOMEM;
		goto ioremap_relay_error;
	}

	relay->v_buzzer = ioremap(BUZZER_BASE, SZ_4K);
	if (!relay->v_buzzer) {
		ret = -ENOMEM;
		goto ioremap_buzzer_error;
	}

	//注册misc设备
	relay->fops.open = relay_open,
	relay->fops.release = relay_close,
	relay->fops.write = relay_write,
	relay->fops.unlocked_ioctl = relay_ioctl;

	relay->misc.name = "relay";
	relay->misc.minor = MISC_DYNAMIC_MINOR;
	relay->misc.fops = &relay->fops;
	ret = misc_register(&relay->misc);
	if (ret) {
		goto misc_error;
	}

	spin_lock_init(&relay->lock);

	//硬件初始化
	exynos4_relay_init(relay);
	
	return 0;

misc_error:
	iounmap(relay->v_buzzer);
ioremap_buzzer_error:
	iounmap(relay->v_relay);
ioremap_relay_error:
	kfree(relay);
alloc_dev_error:
	return ret;
}

//当模块卸载的时候执行
static __exit void relay_exit(void)
{
	exynos4_relay_exit(relay);
	misc_deregister(&relay->misc);
	iounmap(relay->v_relay);
	iounmap(relay->v_buzzer);
	kfree(relay);
}

module_init(relay_init);
module_exit(relay_exit);

MODULE_LICENSE("GPL");










