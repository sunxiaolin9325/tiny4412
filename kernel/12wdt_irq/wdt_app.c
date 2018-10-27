#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sched.h>

#define DEV "/dev/test/mydev"

int main(void)
{
	int fd;
	int ret;

	fd = open(DEV, O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	
	//假设看门狗的定时时间是3秒
	while (1) {
		//使能看门狗
		ioctl(fd, 1, 1);
		sleep(20);
		ioctl(fd, 0, 1);
		sleep(20);
	}

	return 0;
}



