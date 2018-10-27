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

int add_friend_handler(struct tianjiahaoyou_st *h)
{
	sqlite3 *db;
	int ret;
	char *sql;
	char sql1[256];
	sqlite3_stmt *stmt;

//打开数据库
//MDZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
	//ret = sqlite3_open("./yuntalk.sqlite3", &db);
	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		return -1;
	}
	//网络编程,心跳:用户登录后,间隔1,2秒就给服务器发信息(心跳)

///////////////////////都不合理
//打开注册表
	sql = "select * from zhuce where count=?";
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		printf("ret = %d\n", ret);
		goto prepare_error;
	}

//判断是否已经注册
	sqlite3_bind_text(stmt, 1, h->dst_count, -1, NULL);
	ret = sqlite3_step(stmt);
	//没有注册
	if (ret != SQLITE_ROW) {
		goto step_error;
	}

	sqlite3_finalize(stmt);
//判断是否已经是好友
	sprintf(sql1, "select * from %s where count='%s'", h->src_count
	, h->dst_count);
	ret = sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		printf("select * error\n");
		goto prepare_error;
	}

	ret = sqlite3_step(stmt);
	//如果好友已经存在,返回1
	if (ret == SQLITE_ROW) {
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return 1;
	}

//把好友添加到用好好友表中
	//src_count 表名
	//dst_count 好友
	//注意添加单引号
	sprintf(sql1, "insert into %s(count) values('%s')", h->src_count, h->dst_count);
	ret = sqlite3_exec(db, sql1, NULL, NULL, NULL);
	if (ret != SQLITE_OK) {
		printf("insert into fail\n");
		goto step_error;
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
	struct tianjiahaoyou_st tianjiahaoyou;
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

/*
	//打开数据库
	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		perror("sqlite3_open()");
		exit(1);
	}

	//创建地址
	//地址表dizhi中的addr是二进制数据blob
	//sql = "create table if not exists dizhi(no integer primary key autoincrement not null, count text not null, addr blob)";
	sql = "create table if not exists dizhi(no integer primary key autoincrement not null, count text not null, addr blob)";
	ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "%s\n", errmsg);
		exit(1);
	}

	//.quit
	sqlite3_close(db);
*/

	//创建套接字,报式传输类型,UDP协议
	sd =  socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) {
		perror("socket()");
		exit(1);
	}

	//绑定端口号
	server_addr.sin_family = AF_INET;
	//端口号DENGLU_SERVER_PORT
	server_addr.sin_port = htons(TIANJIAHAOYOU_SERVER_PORT);
	//电脑上有多个网卡,任意网卡收到数据,只要端口号没问题,
	//socket都可以收到数据
	server_addr.sin_addr.s_addr = 0; //INADDR_ANY
	ret = bind(sd, (void *)&server_addr, sizeof(struct sockaddr));
	if (ret < 0) {
		perror("bind");
		exit(1);
	}

	//服务器循环阻塞接收数据,创建子进程处理数据,并发送
	//可以不接收(关心)客户端的地址和端口号,只要往本机的IP,
	//指定的端口号发送,就能接收到
	while (1) {
		ret = recvfrom(sd, &tianjiahaoyou, sizeof(tianjiahaoyou), 0, (void *)&client_addr, &addr_len);
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
			//处理添加好友
			ret = add_friend_handler(&tianjiahaoyou);
			if (ret == 0) {
				//添加成功
				tianjiahaoyou.status = TIANJIAHAOYOU_STATUS_OK;
			}else if (ret == 1) {
				//好友已经存在
				tianjiahaoyou.status = TIANJIAHAOYOU_STATUS_ERROR;
				tianjiahaoyou.flag = 1;

			} else {
				//添加失败
				tianjiahaoyou.status = TIANJIAHAOYOU_STATUS_ERROR;
				tianjiahaoyou.flag = 0;
			}

			sendto(sd, &tianjiahaoyou, sizeof(tianjiahaoyou), 0, (void *)&client_addr, sizeof(client_addr));

			exit(0);
		}
		//父进程继续循环阻塞接收数据
		//但子进程退出了没有wait收尸,需要处理僵尸进程
	}

	return 0;
}










