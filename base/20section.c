#include <stdio.h>

int a;  //bss
int b = 0; // bss
int c = 1; // data

int main(void)
{
	int d; //stack
	int e = 5; //stack
	static int f;//bss
	static int g = 6; // data
	char *s = "hello"; //s-->stack
   			   //"hello"--->rodata	
  	static char *ss = "nihao";
			   //ss-->data
			   //"nihao"--->rodata
}
