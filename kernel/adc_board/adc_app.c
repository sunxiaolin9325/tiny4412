#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MYDEV	"/dev/myadc"

struct adc_pro_st {
	int value;
};

int main(void)
{
	int fd;
	int ret;
	struct adc_pro_st aps;

	fd = open(MYDEV, O_RDWR);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	while (1) {
		ioctl(fd, 1, 1);
		ret = read(fd, &aps.value, sizeof(aps));
		if (ret < 0) {
			perror("read()");
			exit(1);
		}
		printf("adc: %d\n", aps.value);
		sleep(1);
	}

	close(fd);

	return 0;
}



