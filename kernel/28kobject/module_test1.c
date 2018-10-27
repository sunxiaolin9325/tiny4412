#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/kobject.h>

struct kset *myset;
struct kobject myobj;

void my_release(struct kobject *kobj)
{
	printk("%s release\n", kobj->name);
}

ssize_t my_show(struct kobject *obj, struct attribute *att, char *buf)
{
	printk("attr:%s\n", att->name);
	memcpy(buf, "hello", 6);
	return 6;
}

ssize_t my_store(struct kobject *obj,struct attribute *att, const char *buf, size_t count)
{
	printk("attr:%s\n", att->name);
	printk("%d bytes:%s\n", count, buf);

	return count;
}

struct sysfs_ops my_ops = {
	.show = my_show,
	.store = my_store,	
};

struct attribute attr1 = {
	.name = "attr1",
	.mode = 0666,
};

struct attribute attr2 = {
	.name = "attr2",
	.mode = 0666,
};

struct attribute *my_attr[] = {
	&attr1, 
	&attr2,	
	NULL,
};

struct kobj_type mytype = {
	.release = my_release,
	.sysfs_ops = &my_ops,
	.default_attrs = my_attr,
};

//当模块安装的时候执行
static __init int test_init(void)
{
	int ret;

	myset = kset_create_and_add("myset", NULL, NULL);
	if (!myset) {
		return -ENOMEM;
	}

	ret = kobject_init_and_add(&myobj, &mytype, &myset->kobj, "%s", "myobj");
	if (ret) {
		goto obj_add_error;
	}

	return 0;
obj_add_error:
	kset_unregister(myset);
	kfree(myset);
	return ret;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	kobject_del(&myobj);
	kset_unregister(myset);
	kfree(myset);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");










