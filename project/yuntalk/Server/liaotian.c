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

int send_msg(struct liaotian_st *lt, int sd)
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int ret;
	char *sql;
	struct sockaddr_in *addr;

	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		return -1;
	}

//判断用户的好友是否在线(在地址表中)
	sql = "select * from dizhi where count=?";
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		goto prepare_error;
	}

	sqlite3_bind_text(stmt, 1, lt->dcount, -1, NULL);

	ret = sqlite3_step(stmt);
	if (ret !=SQLITE_DONE && ret != SQLITE_ROW) {
		goto step_error;
	}

	if (ret == SQLITE_DONE) {
	//好友没有登录 不转发, 保存到数据库
		sql = "insert into liaotian(scount, dcount, msg, flag) values(?, ?, ?, 1)";
	} else {
	//好友登录了,转发, 保存到数据库
		//获取表中第2列地址
		addr = (void *)sqlite3_column_blob(stmt, 2);
		//设置状态
		lt->status = LIAOTIAN_STATUS_OK;
		//socket发送
		sendto(sd, lt, sizeof(*lt), 0, (void *)addr, sizeof(*addr));
		sql = "insert into liaotian(scount, dcount, msg, flag) values(?, ?, ?, 0)";
	}

	//只能在这里释放stmt,上面获取地址还要用
	sqlite3_finalize(stmt);

	//登没登录都存到数据库
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		goto prepare_error;
	}

	sqlite3_bind_text(stmt, 1, lt->scount, -1, NULL);
	sqlite3_bind_text(stmt, 2, lt->dcount, -1, NULL);
	sqlite3_bind_text(stmt, 3, lt->msg, -1, NULL);
	ret = sqlite3_step(stmt);
	if (ret != SQLITE_DONE) {
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
	struct liaotian_st liaotian;
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


//创建聊天表
	//flag=1: 代表消息有没有转发过
	sql = "create table if not exists liaotian(no integer primary key autoincrement not null, scount text not null, dcount text not null, msg text, flag integer not null)";
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
	server_addr.sin_port = htons(LIAOTIAN_SERVER_PORT);
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
		ret = recvfrom(sd, &liaotian, sizeof(liaotian), 0, (void *)&client_addr, &addr_len);
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
			//收到消息后转发,并保存到数据库聊天表中
			ret = send_msg(&liaotian, sd);
			if (ret < 0) {
				fprintf(stderr, "send error\n");
			}
		}
		//父进程继续循环阻塞接收数据
		//但子进程退出了没有wait收尸,需要处理僵尸进程
	}

	return 0;
}










