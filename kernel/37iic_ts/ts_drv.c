#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/i2c.h>

#include "ts.h"

void work_handler(struct work_struct *work)
{
	struct ts_st *ts;
	struct i2c_msg msg[1];
	unsigned long flags;
	char buf[31];
	int point;

	ts = container_of(work, struct ts_st, work);
	msg[0].addr = ts->client->addr;
	msg[0].flags = I2C_M_RD;
	msg[0].len = 31;
	msg[0].buf = buf;

	local_irq_save(flags);	
	i2c_transfer(ts->client->adapter, msg, ARRAY_SIZE(msg));
	local_irq_restore(flags);

	point = buf[2] & 0xf;	
	ts->x = ((buf[3] & 0xf) << 8) | buf[4];
	ts->y = ((buf[5] & 0xf) << 8) | buf[6];

	if (point == 1) {
		//x y p b 
		input_report_abs(ts->dev, ABS_X, ts->x);
		input_report_abs(ts->dev, ABS_Y, ts->y);
		input_report_abs(ts->dev, ABS_PRESSURE, ts->pressure);
		input_report_key(ts->dev, BTN_TOUCH, 1);

	} else if (point == 0) {
		//p b 
		input_report_abs(ts->dev, ABS_PRESSURE, 0);
		input_report_key(ts->dev, BTN_TOUCH, 0);
	}

	input_sync(ts->dev);
}

irqreturn_t ts_handler(int irq, void *data)
{
	struct ts_st *ts;

	ts = data;	
	schedule_work(&ts->work);
	return IRQ_HANDLED;
}

int ts_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct ts_st *ts;
	struct ts_info_st *pdata;
	int ret;

//由内核进行了一系列操作
	pdata = client->dev.platform_data;
	
	ts = kzalloc(sizeof(*ts), GFP_KERNEL);
	if (!ts) {
		return -ENOMEM;
	}	

	ts->client = client;
	ts->irq = pdata->irq;
	ts->xres = pdata->xres;
	ts->yres = pdata->yres;
	ts->pressure = pdata->pressure;
	
	INIT_WORK(&ts->work, work_handler);	
	ts->dev = input_allocate_device();
	if (!ts->dev) {
		ret = -ENOMEM;
		goto alloc_input_error;
	}

	ts->dev->name = client->name;
        ts->dev->phys = "xxxx";
        ts->dev->uniq = "20170110";
        ts->dev->id.bustype = BUS_I2C;
        ts->dev->id.vendor = 100;
        ts->dev->id.product = 101;
        ts->dev->id.version = 1;

	set_bit(EV_SYN, ts->dev->evbit);
	set_bit(EV_ABS, ts->dev->evbit);
	set_bit(EV_KEY, ts->dev->evbit);

	set_bit(ABS_X, ts->dev->absbit);
	set_bit(ABS_Y, ts->dev->absbit);
	set_bit(ABS_PRESSURE, ts->dev->absbit);

	set_bit(BTN_TOUCH, ts->dev->keybit);

	//设置绝对事件code为ABS_X的value值的范围
	input_set_abs_params(ts->dev, ABS_X, 0, ts->xres, 0, 0);
	input_set_abs_params(ts->dev, ABS_Y, 0, ts->yres, 0, 0);
	input_set_abs_params(ts->dev, ABS_PRESSURE, 0, ts->pressure, 0, 0);
	
	ret = input_register_device(ts->dev);
	if (ret) {
		goto register_input_error;
	}

	ret = request_irq(ts->irq, ts_handler, IRQF_TRIGGER_FALLING, client->name, ts);
	if (ret) {
		goto irq_error;
	}

	i2c_set_clientdata(client, ts);

	return 0;
irq_error:
	input_unregister_device(ts->dev);
register_input_error:
	input_free_device(ts->dev);	
alloc_input_error:
	kfree(ts);
	return ret;
}

int ts_remove(struct i2c_client *client)
{
	struct ts_st *ts;

	ts = i2c_get_clientdata(client);
	free_irq(ts->irq, ts);
	input_unregister_device(ts->dev);
	input_free_device(ts->dev);	
	kfree(ts);

	return 0;
}

struct i2c_device_id id_table[] = {
	{"myts", 123},
	{"herts", 456},
	{},
};

struct i2c_driver ts_drv = {
	.probe = ts_probe,
	.remove = ts_remove,
	.driver = {
		.name = "myts",
	},
	//.....
	.id_table = id_table,
};

//当模块安装的时候执行
static __init int test_init(void)
{
	return i2c_add_driver(&ts_drv);
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	i2c_del_driver(&ts_drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










