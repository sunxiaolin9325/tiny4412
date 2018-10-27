#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <utmpx.h>

int main(void)
{
	int ret;

	cpu_set_t set;

	CPU_ZERO(&set);
	CPU_SET(1, &set);
	CPU_SET(2, &set);

	ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
	if (ret < 0) {
		perror("sched");
		exit(1);
	}
	while (1) {
		printf("cpu:%d\n", sched_getcpu());
		sleep(1);
	}
	return 0;
}
