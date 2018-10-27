///proc/bus/input/devices

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
	struct input_event event;

	if (argc != 2) {
		fprintf(stderr, "input error\n");
		exit(0);
	}

	fd = open(argv[1], O_RDONLY);
	//if error

	while (1) {
		read(fd, &event, sizeof(event));
		//if error
		switch (event.type) {
			case EV_SYN:
				printf("sync\n");
				break;
			case EV_KEY:
				if (event.value) {
					printf("%d down\n", event.code);	
				} else {
					printf("%d up\n", event.code);	
				}
				break;
			case EV_ABS:
				printf("abs %d %d\n", event.code, event.value);
				if (event.code == ABS_X) {
					printf("abs_x:%d\n", event.value);
				} else if (event.code == ABS_Y) {
					printf("abs_y:%d\n", event.value);
				}
				break;
			case EV_REL:
				if (event.code == REL_X) {
					printf("rel_x:%d\n", event.value);
				} else if (event.code == REL_Y) {
					printf("rel_y:%d\n", event.value);
				}
				break;
			default:
				printf("misc event\n");
				break;
		}
	}

	return 0;
}







