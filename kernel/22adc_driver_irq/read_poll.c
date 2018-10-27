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

struct adc_value_st {
	int value;
};

int main(void)
{
	int fd;
	char buf[20];
	int ret;
	fd_set read_set;
	struct adc_value_st avs;

	fd = open(DEV, O_RDONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	while (1) {
		FD_ZERO(&read_set);
		FD_SET(fd, &read_set);

		ioctl(fd, 0, 0);
		select(fd + 1, &read_set, NULL, NULL, NULL);
		ret = read(fd, &avs, sizeof(avs));
		if (ret < 0) {
			//perror("read");
			//exit(1);
			continue;
		}
		printf("adc=%d\n", avs.value);
		sleep(1);
	}

	close(fd);

	return 0;
}



