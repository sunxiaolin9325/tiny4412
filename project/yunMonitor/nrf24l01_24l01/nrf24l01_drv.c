#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>

#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/delay.h>

#include "nrf24l01.h"
#include "nrf.h"

int nrf24l01_open(struct inode *no, struct file *fp)
{
	struct nrf24l01_st *p;
	u8 status;

	//使nrf.c文件中的v为虚拟地址
	if (get_v() < 0) {
		return -ENOMEM;
	}

	//硬件初始化
	SPI_NRF_Init();

	p = container_of(fp->f_op, struct nrf24l01_st, nrf24l01_ops);
	fp->private_data = p;

	status = NRF_Check();
	if (status == SUCCESS){
		printk("nrf24l01 connect ok!\n");
	} else {
		printk( "nrf24l01 connect error!\n");
		return -ENODEV;
	}

	spin_lock(&p->lock);
	if (p->count) {
		spin_unlock(&p->lock);
		return -EBUSY;
	}

	p->count++;
	spin_unlock(&p->lock);

	return 0;
}

int nrf24l01_close(struct inode *no, struct file *fp)
{
	struct nrf24l01_st *p;

	p = fp->private_data;
	spin_lock(&p->lock);
	if (!p->count) {
		spin_unlock(&p->lock);
		return -ENODEV;	
	}

	p->count--;
	spin_unlock(&p->lock);

	//使v为物理地址
	put_v();

	return 0;
}

ssize_t nrf24l01_read(struct file *fp, char __user *buffer, size_t count, loff_t *off)
{
	struct nrf24l01_st *p;
	struct nrf24l01_pro_st pro;
	u8 status;
	int ret;

	if (count != sizeof(pro)) {
		return -EMSGSIZE;
	}

	p = fp->private_data;

	ret = copy_from_user(&pro, buffer, sizeof(pro));
	if (ret) {
		return -EFAULT;
	}

	while (1) {
		//设置为接收模式
		//NRF_RX_Mode(RX_CHANNEL, rxaddr, sizeof(pro));
		NRF_RX_Mode(pro.rx_channel, pro.rxaddr, sizeof(pro.data));
		//接收数据,协议结构体
		status = NRF_Rx_Dat((void *)&pro.data);
		if (status == RX_DR) {
			printk("recv ok\n");
			break;
		} else if (status == TIMEOUT) {
			printk("recv timeout\n");
			return -ETIME;
		}
		else {
			printk("recv error\n");
			return -EPERM;
		}
	}

	ret = copy_to_user(buffer, &pro, sizeof(pro));
	if (ret) {
		return -EFAULT;
	}

	return count;
}

ssize_t nrf24l01_write(struct file *fp, const char __user *buffer, size_t count, loff_t *off)
{
	struct nrf24l01_st *p;
	struct nrf24l01_pro_st pro;
	u8 status;
	int ret;
	int times = 0;

	if (count != sizeof(pro)) {
		return -EMSGSIZE;
	}

	p = fp->private_data;

	ret = copy_from_user(&pro, buffer, sizeof(pro));
	if (ret) {
		return -EFAULT;
	}

	while (1) {
		//NRF_TX_Mode(TX_CHANNEL, txaddr);
		NRF_TX_Mode(pro.tx_channel, pro.txaddr);
		status = NRF_Tx_Dat((void *)&pro.data, sizeof(pro.data));
		if (status == TX_DS) {
			printk("send ok\n");
			break;
		} else if (status == MAX_RT || status == TIMEOUT) {
			if (times++ < 5) {
				continue;
			}
			printk("send timeout\n");
			return -ETIME;
		} else {
			printk("send error\n");
			return -EPERM;
		}
	}

	return count;
}

int test(void)
{
	u8 status;
	struct nrf24l01_pro_st pro;
	int count = 10;

	//u8 txaddr[5] = {0x34,0x43,0x10,0x10,0x01};
	//u8 rxaddr[5] = {0x10,0x20,0x30,0x40,0x50};
	//#define TX_CHANNEL	41
	//#define RX_CHANNEL	40
	
	if (get_v() < 0) {
		return -1;
	}

	SPI_NRF_Init();
	
	status = NRF_Check();
	if(status == SUCCESS){
		printk("nrf24l01 connect ok!\n");
	}else{
		printk( "nrf24l01 connect error!\n");
		while(1);
	}
	
	while(count--){
		pro.data.control = 0;
		//设置为发送模式,指定通道和地址
		//yun
		//NRF_TX_Mode(TX_CHANNEL, txaddr);
		//发送数据,通信协议结构体
		status = NRF_Tx_Dat((void *)&pro, sizeof(pro));
		switch(status){
			case TIMEOUT:
			case MAX_RT:
				printk("timeout\n");
				break;
			case TX_DS:
				printk("send ok\n");
				break;
			case ERROR:
				printk("send error\n");
				break;
			default:
				break;
		}
		
		//设置为接收模式
		NRF_RX_Mode(pro.rx_channel, pro.rxaddr, sizeof(pro.data));
		//接收数据,协议结构体
		status = NRF_Rx_Dat((void *)&pro.data);
		switch(status){
			case RX_DR:
				printk("recv ok\n");
				printk("%s\n", pro.data.msg);
				break;
			case ERROR:
				printk("recv error\n");
				break;
			default:
				break;
		}

		ssleep(1);	
	}

	return 0;
}

//设备模型
int nrf24l01_probe(struct platform_device *pdev)
{
	struct nrf24l01_st *nrf24l01;
	int ret;

	//1.获得资源	

	//2.分配设备结构体
	nrf24l01 = kzalloc(sizeof(*nrf24l01), GFP_KERNEL);
	if (!nrf24l01) {
		ret = -ENOMEM;
		goto alloc_dev_error;
	}

	//3.地址映射

	//4.misc设备注册,一个设备文件,支持NUM个物理设备
	nrf24l01->nrf24l01_ops.open = nrf24l01_open;
	nrf24l01->nrf24l01_ops.release = nrf24l01_close;
	nrf24l01->nrf24l01_ops.read = nrf24l01_read;
	nrf24l01->nrf24l01_ops.write = nrf24l01_write;
	///dev/nrf24l01
	nrf24l01->misc.name = pdev->name;
	nrf24l01->misc.minor = MISC_DYNAMIC_MINOR;
	nrf24l01->misc.fops = &nrf24l01->nrf24l01_ops; 

	ret = misc_register(&nrf24l01->misc);
	if (ret) {
		goto misc_error;
	}

	//5.申请GPIO

	spin_lock_init(&nrf24l01->lock);

	//6.保存设备结构体指针
	platform_set_drvdata(pdev, nrf24l01);

	//驱动模型框架搭好以后,可以利用修改后裸板代码来测试
	//test();
	return 0;

misc_error:
	kfree(nrf24l01);
alloc_dev_error:
	return ret;
}

int nrf24l01_remove(struct platform_device *pdev)
{
	struct nrf24l01_st *nrf24l01;

	nrf24l01 = platform_get_drvdata(pdev);

	misc_deregister(&nrf24l01->misc);
	kfree(nrf24l01);
	return 0;
}

void nrf24l01_shutdown(struct platform_device *pdev)
{

}

int nrf24l01_suspend(struct platform_device *pdev, pm_message_t state)
{
	return 0;
}

int nrf24l01_resume(struct platform_device *pdev)
{
	return 0;
}

struct platform_device_id nrf24l01_id_table[] = {
	{"dht11", 123},
	{"nrf24l01", 123}, 
	{"dht33", 123},
	{},
};

struct platform_driver drv = {
	.probe = nrf24l01_probe,
	.remove = nrf24l01_remove,
	.suspend = nrf24l01_suspend,
	.shutdown = nrf24l01_shutdown,
	.resume = nrf24l01_resume,
	.driver = {
		.name = "nrf24l01",
	},
	.id_table = nrf24l01_id_table,
};

static __init int nrf24l01_drv_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void nrf24l01_drv_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(nrf24l01_drv_init);
module_exit(nrf24l01_drv_exit);

MODULE_LICENSE("GPL");










