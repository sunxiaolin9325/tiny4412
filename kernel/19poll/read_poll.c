#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define DEV "/dev/test/mydev"

int main(void)
{
	int fd;
	char buf[20];
	int ret;
	fd_set read_set;

	fd = open(DEV, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	while (1) {
		FD_ZERO(&read_set);
		FD_SET(fd, &read_set);

		//监视，程序由这里进入内核，在内核中睡眠等待，只有被监视的fd状态可读时，mask | POLLIN返回后，程序向下执行。
		select(fd + 1, &read_set, NULL, NULL, NULL);
		ret = read(fd, buf, sizeof(buf));
		if (ret < 0) {
			//perror("read");
			//exit(1);
			continue;
		}
		write(1, buf, ret);
	}

	close(fd);

	return 0;
}



