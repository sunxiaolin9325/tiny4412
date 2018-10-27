///proc/bus/input/devices

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>

#include <linux/input.h>

// ./test /dev/event2
//
// type = EV_REL
// code = REL_X 
// value = -3

//#define EV_SYN                  0x00
//#define EV_KEY                  0x01
//#define EV_REL                  0x02
//#define EV_ABS                  0x03
//#define EV_MSC                  0x04

int main(int argc, char *argv[])
{
	int fd;
	int i;
	struct input_event event;

	if (argc != 2) {
		fprintf(stderr, "input error\n");
		exit(0);
	}

	fd = open(argv[1], O_RDWR);
	//if error

	while (1) {
		//----->x
		for (i = 0; i < 10; i++) {	
			event.type = EV_REL;	
			event.code = REL_X;
			event.value = 10;
			write(fd, &event, sizeof(event));
			event.type = EV_SYN;
			event.code = 0;
			event.value = 1;
			write(fd, &event, sizeof(event));
			usleep(100000);	
		}

		for (i = 0; i < 10; i++) {	
			event.type = EV_REL;
			event.code = REL_Y;
			event.value = 10;
			write(fd, &event, sizeof(event));
			event.type = EV_SYN;
			event.code = 0;
			event.value = 1;
			write(fd, &event, sizeof(event));
			usleep(100000);	
		}
		
		for (i = 0; i < 10; i++) {
			event.type = EV_REL;
			event.code = REL_X;
			event.value = -10;
			write(fd, &event, sizeof(event));
			event.type = EV_SYN;
			event.code = 0;
			event.value = 1;
			write(fd, &event, sizeof(event));
			usleep(100000);	
		}

		for (i = 0; i < 10; i++) {
			event.type = EV_REL;
			event.code = REL_Y;
			event.value = -10;
			write(fd, &event, sizeof(event));
			event.type = EV_SYN;
			event.code = 0;
			event.value = 1;
			write(fd, &event, sizeof(event));
			usleep(100000);	
		}
	}

	close(fd);

	return 0;
}







