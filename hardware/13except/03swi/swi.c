#include <common.h>

void add(void)
{
	printf("%s\n", __FUNCTION__);
}

void sub(void)
{
	printf("%s\n", __FUNCTION__);
}

void mul(void)
{
	printf("%s\n", __FUNCTION__);
}

void div(void)
{
	printf("%s\n", __FUNCTION__);
}

typedef void (*handler)(void);
handler arr[4];

void set_handler(void)
{
	arr[0] = add;
	arr[1] = sub; 
	arr[2] = mul;
	arr[3] = div;
}

//bl do_swi
void do_swi(int no)
{
	//想办法获取swi no
	handler h = arr[no];
	h();
}




