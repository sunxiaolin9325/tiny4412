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
	char *s = "hello\n";
	int ret;

	fd = open(DEV, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	ret = write(fd, s, strlen(s));
	if (ret < 0) {
		perror("write");
		exit(1);
	}

	close(fd);

	return 0;
}



