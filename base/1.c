#include <stdio.h>

int main(void)
{
	char *s = "hello";
	char *p = s;

	p++;

	*p = 'n';
	printf("%s\n", s);
	return 0;
}
