#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

#include <linux/platform_device.h>
#include <linux/slab.h>
#include <asm/io.h>

#include <linux/interrupt.h>

#include <linux/input.h>
#include "button.h"

void exynos4_button_init(struct button_st *b, int num, struct resource *irq_res)
{
	int i;

	for (i = 0; i < num; i++) {
		b[i].dev = b[0].dev;
		b[i].irq = irq_res->start + i;
		b[i].v = b[0].v;
	}

	b[0].code = KEY_ESC;
	b[1].code = KEY_ENTER;
	b[2].code = KEY_UP;
	b[3].code = KEY_DOWN;
}

int is_down(struct button_st *b)
{
	u32 data;
	int nr;
	// 2,3,4,5
	data = (ioread32(b->v + GPX3DAT) >> 2) & 0xf;
	nr = b->irq - IRQ_EINT(26);
	
	return !(data & (1 << nr));
}

irqreturn_t button_isr(int irq, void *data)
{
	struct button_st *b;

	b = data;

	if (is_down(b)) {
		//报告按键事件	 设备	键码	value
		input_report_key(b->dev, b->code, 1);	
	} else {
		input_report_key(b->dev, b->code, 0);	
	}

	//同步事件
	input_sync(b->dev);

	return IRQ_HANDLED;
}

int my_probe(struct platform_device *pdev) 
{
	struct button_st *button;
	struct resource *io_res, *irq_res;
	struct platform_data_st *pdata;
	int ret;
	int i;

	//1
	io_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!io_res || !irq_res) {
		return -EBUSY;
	}

	//2
	pdata = pdev->dev.platform_data;
	printk("==%d BUTTON==\n", pdata->num);
	//分配四个设备结构体,其中的struct input_dev和v只有一个,所以还是一个设备,中断线和键码有四个
	button = kzalloc(sizeof(*button) * pdata->num, GFP_KERNEL);
	if (!button) {
		ret = -ENOMEM;
		goto alloc_button_error;
	}

	//4
	button->dev = input_allocate_device();
	if (!button->dev) {
		ret = -ENOMEM;
		goto alloc_input_error;
	}

			//my-button
	button->dev->name = pdev->name;
        button->dev->phys = "/sys/xxx";
        button->dev->uniq = "20170109";
	button->dev->id.bustype = BUS_HOST;
        button->dev->id.vendor = 1;
        button->dev->id.product = 2;
        button->dev->id.version = 1;

	//键盘事件  
	//同步事件  
	set_bit(EV_KEY, button->dev->evbit);
	set_bit(EV_SYN, button->dev->evbit);

	set_bit(KEY_ESC, button->dev->keybit);
	set_bit(KEY_UP, button->dev->keybit);
	set_bit(KEY_DOWN, button->dev->keybit);
	set_bit(KEY_ENTER, button->dev->keybit);		
	ret = input_register_device(button->dev);
	if (ret) {

		goto register_input_error;
	}

	//3
	button->v = ioremap(io_res->start, io_res->end - io_res->start + 1);
	if (!button->v) {
		ret = -ENOMEM;
		goto ioremap_error;
	}

	//初始化四个设备结构体,同一个设备
	exynos4_button_init(button, pdata->num, irq_res);

	//5
	for (i = 0; i < pdata->num; i++) {
		ret = request_irq(button[i].irq, button_isr, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, pdev->name, &button[i]);	
		if (ret < 0) {
			goto request_irq_error;
		}
	}

	//6
	platform_set_drvdata(pdev, button);
	
	return 0;
request_irq_error:
	while (i--)
	free_irq(button[i].irq, &button[i]);
	iounmap(button->v);
ioremap_error:
	input_unregister_device(button->dev);
register_input_error:
	input_free_device(button->dev);	
alloc_input_error:
	kfree(button);
alloc_button_error:
	return ret;
}

int my_remove(struct platform_device *pdev)
{
	struct button_st *button;
	struct platform_data_st *pdata;
	int i;

	pdata = pdev->dev.platform_data;
	button = platform_get_drvdata(pdev);
	
	for (i = 0; i < pdata->num; i++)
		free_irq(button[i].irq, &button[i]);	
	
	iounmap(button->v);
	input_unregister_device(button->dev);
	input_free_device(button->dev);	
	kfree(button);

	return 0;
}

void my_shutdown(struct platform_device *pdev)
{

	printk("[%s] %s\n", pdev->name, __FUNCTION__);
}

int my_suspend(struct platform_device *pdev, pm_message_t state)
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

int my_resume(struct platform_device *pdev)
{
	printk("[%s] %s\n", pdev->name, __FUNCTION__);
	return 0;
}

struct platform_device_id id_table[] = {
	{"my-button", 123},
	{"123", 123},
	{"456", 456},
	{"789", 789},
	{},
};

struct platform_driver drv = {
	.probe = my_probe,
	.remove = my_remove,
	.suspend = my_suspend,
	.resume = my_resume,
	.shutdown = my_shutdown,	
	.driver = {
		.name = "123",	
	},
	.id_table = id_table,
};

static __init int test_init(void)
{
	return platform_driver_register(&drv);
}

static __exit void test_exit(void)
{
	platform_driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










