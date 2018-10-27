#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

int no = 6;
char *buf = "lin";
bool val = 1;
int arr[10] = {1, 2, 3};
int len = 5;
char *str;
//声明模块参数 
//module_param_named(a, no, int, 0);
//module_param_named(b, buf, charp, 0);
//module_param_named(c, value, bool, 0);
// 内核模块参数，可直接赋值，也可在安装模块时传参（类似./main xxx xxx...）
// 安装成功后/sys/module/module_test1/parameters/路径下
// 会保存模块参数，参数可以修改
module_param(no, int, 0664);
module_param(buf, charp, 0664);
module_param(val, bool, 0664);
module_param_array(arr, int, &len, 0664);
module_param_string(str, "hello", 10, 0664);
//当模块安装的时候执行
static __init int test_init(void)
{
	int i;

	printk("test_init\n");
	printk("no = %d\n", no);
	printk("buf = %s\n", buf);
	printk("val = %d\n", val);
	for (i=0; i<len; i++) {
		printk("arr[%d] = %d\n", i, arr[i]);
	}
	printk("str = %s\n", str);
	
	return 0;
}

//当模块卸载的时候执行
static __exit void test_exit(void)
{
	int i;

	printk("test_exit\n");
	printk("no = %d\n", no);
	printk("buf = %s\n", buf);
	printk("val = %d\n", val);
	for (i=0; i<len; i++) {
		printk("arr[%d] = %d\n", i, arr[i]);
	}
	printk("str = %s\n", str);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
