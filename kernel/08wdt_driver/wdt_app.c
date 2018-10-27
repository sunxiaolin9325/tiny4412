#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sched.h>

#define DEV "/dev/test/mydev"

struct wdt_feed_st {
	int time;
};

int main(void)
{
	int fd;
	int ret;
	struct wdt_feed_st wfs; 
	struct sched_param param;

	wfs.time = 15625 * 3;

	fd = open(DEV, O_RDWR);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	
	param.sched_priority = sched_get_priority_max(SCHED_FIFO);

	sched_setscheduler(0, SCHED_FIFO, &param);

	//使能看门狗
	ioctl(fd, 1, 1);
	//假设看门狗的定时时间是3秒
	while (1) {
		write(fd, &wfs, sizeof(wfs));
		sleep(2);
	}

	return 0;
}



