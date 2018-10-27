#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
	char buf[10];
	int fd;

	fd = open("/proc/uplooking/123", O_RDONLY);
	if (fd < 0) {
		perror("open");
		exit(1);
	}

	read(fd, buf, 5);
	write(1, buf, 5);	
	write(1,"----------", 10);

	read(fd, buf, 3);
	write(1, buf, 3);
	write(1,"----------", 10);

	read(fd, buf, 6);
	write(1, buf, 6);
	write(1,"----------", 10);
	
	close(fd);

	return 0;
}




