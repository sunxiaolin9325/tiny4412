#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEV "/dev/myadc"

struct adc_value_st {
        int value;
};

int main(void)
{
	int fd;
	int ret;
	struct adc_value_st avs;

	fd = open(DEV, O_RDONLY);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	while (1) {
		ioctl(fd, 0, 0);
		ret = read(fd, &avs, sizeof(avs));
		if (ret < 0) {
			perror("read");
			exit(1);
		}

		printf("adc_value=%d\n", avs.value);
		sleep(1);
	}

	close(fd);

	return 0;
}



