#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEV "/dev/test/mydev"

int main(void)
{
	int fd;
	char buf[20];
	int ret;

	fd = open(DEV, O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	ret = read(fd, buf, sizeof(buf));
	if (ret < 0) {
		perror("read");
		exit(1);
	}

	close(fd);

	return 0;
}



