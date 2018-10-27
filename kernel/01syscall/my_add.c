#define _GNU_SOURCE        /* or _BSD_SOURCE or _SVID_SOURCE */
#include <unistd.h>
#include <sys/syscall.h> 

int my_add(int a, int b)
{
	return syscall(378, a, b);
}
