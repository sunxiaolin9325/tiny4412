#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>

#define DEV "/dev/exynos4-led"

struct led_pro_st {
	int led_no;
	int light;
	int status;
};

int main(void)
{
	int fd;
	char buf[20];
	int ret;
	struct led_pro_st lps;

	lps.led_no = 0;
	lps.light = 1;

	fd = open(DEV, O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	write(fd, &lps, sizeof(lps));
	read(fd, &lps, sizeof(lps));	
	sleep(3);
	ioctl(fd, 0, 1);
	sleep(3);
	ioctl(fd, 1, 1);

	close(fd);

	return 0;
}



