#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <signal.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "protocal.h"

#include <sqlite3.h>

#define IPSTRSIZE               128

//登录成功返回0,失败返回-1
	//查询数据库
int login_handler(struct denglu_st *d)
{
	int ret;
	char *sql;
	sqlite3 *db;
	sqlite3_stmt *stmt;
printf("%s %s\n", d->count, d->passwd);
	//sqlite3 yuntalk.salite 打开数据库
	//db指针链接(指向)数据库
	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		return -1;
	}

//查询注册表,账号密码是否匹配
	sql = "select * from zhuce where count=? and passwd=?";
	//准备
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		goto prepare_error;
	}

	//绑定,匹配
	sqlite3_bind_text(stmt, 1, d->count, -1, NULL);
	sqlite3_bind_text(stmt, 2, d->passwd, -1, NULL);
	//这个函数执行一次最多能查询到一条记录
	//执行上面的sqlite语句
	ret = sqlite3_step(stmt);
	//没找到就goto step_error
	if (ret != SQLITE_ROW) {
		goto step_error;
	}

	//到这里就说明账号密码匹配,准备把用户放到登录表
	//用完就释放了,在sqlite3_prepare_v2分配了空间
	sqlite3_finalize(stmt);

//判断是否已经登录
	sql = "select * from denglu where count=?";
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		goto prepare_error;
	}

	sqlite3_bind_text(stmt, 1, d->count, -1, NULL);
	ret = sqlite3_step(stmt);
	if (ret != SQLITE_ROW) {
		sqlite3_finalize(stmt);
		sql = "insert into denglu(count) values(?)";
		ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (ret != SQLITE_OK) {
			goto prepare_error;
		}

		sqlite3_bind_text(stmt, 1, d->count, -1, NULL);
		ret = sqlite3_step(stmt);
		if (ret != SQLITE_DONE) {
			goto step_error;
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;

step_error:
	sqlite3_finalize(stmt);
prepare_error:
	sqlite3_close(db);
	return -1;
}

int main(void)
{
	int sd;
	int ret;
	pid_t pid;
	struct denglu_st denglu;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_len = sizeof(server_addr);
	struct sigaction action;
	char ipstr[IPSTRSIZE];

	sqlite3 *db;
	char *sql;
	char *errmsg;

//信号处理僵尸进程
	action.sa_handler = SIG_IGN;
	action.sa_flags = SA_NOCLDWAIT;
	sigaction(SIGCHLD, &action, NULL);

//打开数据库
	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		perror("sqlite3_open()");
		exit(1);
	}

//创建注册表
	sql = "create table if not exists zhuce(no integer primary key autoincrement not null, count text not null, passwd text, gender integer)";
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "%s\n", errmsg);
		exit(1);
	}

//创建登录表
	sql = "create table if not exists denglu(no integer primary key autoincrement not null, count text not null)";
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "%s\n", errmsg);
		exit(1);
	}

	//.quit
	sqlite3_close(db);
	

//创建套接字,报式传输类型,UDP协议
	sd =  socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) {
		perror("socket()");
		exit(1);
	}

//绑定端口号
	server_addr.sin_family = AF_INET;
	//端口号DENGLU_SERVER_PORT
	server_addr.sin_port = htons(DENGLU_SERVER_PORT);
	//电脑上有多个网卡,任意网卡收到数据,只要端口号没问题,
	//socket都可以收到数据
	server_addr.sin_addr.s_addr = 0; //INADDR_ANY
	//struct sockaddr还是struct sockaddr_in
	ret = bind(sd, (void *)&server_addr, sizeof(struct sockaddr));
	if (ret < 0) {
		perror("bind");
		exit(1);
	}

//服务器循环阻塞接收数据,创建子进程处理数据,并发送
	//可以不接收(关心)客户端的地址和端口号,只要往本机的IP,
	//指定的端口号发送,就能接收到
	while (1) {
		ret = recvfrom(sd, &denglu, sizeof(denglu), 0, (void *)&client_addr, &addr_len);
		if (ret < 0) {
			continue;
		}

		inet_ntop(AF_INET, &client_addr.sin_addr, ipstr, IPSTRSIZE);
                printf("-----Message from %s: %d----\n", ipstr, ntohs(client_addr.sin_port));

		pid = fork();
		if (pid < 0) {
			perror("for()");
			exit(1);
		}
		if (pid == 0) {
			//处理登录
			ret = login_handler(&denglu);
			if (ret == 0) {
				denglu.status = DENGLU_STATUS_OK;
			}else {
				denglu.status = DENGLU_STATUS_ERROR;
			}
			sendto(sd, &denglu, sizeof(denglu), 0, (void *)&client_addr, sizeof(struct sockaddr_in));
			exit(0);
		}
		//父进程继续循环阻塞接收数据
		//但子进程退出了没有wait收尸,需要处理僵尸进程
	}

	return 0;
}










