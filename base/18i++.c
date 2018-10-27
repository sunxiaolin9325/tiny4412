#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	//arm-linux-gcc编译器
	//从第二个表达式开始运算,i++,i的值不变,直到++i,i的值才变
	    //1  + 1    +2    + 2   + 2
	j = i++ + ++i + ++i + i++ + i++;
	//gcc 编译器
	    //0    2     3    3     4 

	printf("i = %d\n", i);
	printf("j = %d\n", j);

	return 0;
}




