#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
	int ret = 0;
	pid_t pid;
	int errno;

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		ret = execl("/home/lin/driver/program/project/yuntalk/Server/zhuce", "zhuce", NULL);
		//代码不会继续向下执行了,除非execl出错了
		//返回值为-1;
		if (ret == -1)
			printf("execl zhuce fail\n");
		exit(0);
	}
	usleep(500000);
	printf("zhuce ok\n");

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		ret = execl("/home/lin/driver/program/project/yuntalk/Server/denglu", "denglu", NULL);
		if (ret == -1)
			printf("execl denglu fail\n");
		exit(0);
	}
	usleep(500000);
	printf("denglu ok\n");

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		ret = execl("/home/lin/driver/program/project/yuntalk/Server/jizhudizhi", "jizhudizhi", NULL);
		if (ret == -1)
			printf("execl jizhudizhi fail\n");
		exit(0);
	}
	usleep(500000);
	printf("jizhudizhi ok\n");

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		ret = execl("/home/lin/driver/program/project/yuntalk/Server/tianjiahaoyou", "tianjiahaoyou", NULL);
		if (ret == -1)
			printf("execl tianjiahaoyou fail\n");
		exit(0);
	}
	usleep(500000);
	printf("tianjiahaoyou ok\n");

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		ret = execl("/home/lin/driver/program/project/yuntalk/Server/liaotian", "liaotian", NULL);
		if (ret == -1)
			printf("execl liaotian fail\n");
		exit(0);
	}
	usleep(500000);
	printf("liaotian ok\n");

	while (1) {
		errno = 0;
		ret = wait(NULL);
		//当没有子进程了,wait返回-ECHILD
		if (ret < 0 && errno == ECHILD)  {
			break;
		}
	}

	return 0;
}

	//step的返回值:执行select语句,找到则返回SQLITE_ROW,
	//遍历完没找到返回SQLITE_DONE
	//执行insert语句,正常返回SQLITE_OK
	//执行其他语句正常返回SQLITE_DONE




