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

int addr_handler(int sd, struct jizhudizhi_st *j, struct sockaddr_in *addr)
{
	sqlite3 *db;
	int ret;
	char *sql;
	sqlite3_stmt *stmt;
	char ipstr[IPSTRSIZE];
	char sql1[256];
	char *count;
	struct liaotian_st haoyou;

	inet_ntop(AF_INET, &addr->sin_addr, ipstr, IPSTRSIZE);
	printf("%s %s: %d\n", j->count, ipstr, ntohs(addr->sin_port));

//打开数据库
//MDZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
	//ret = sqlite3_open("./yuntalk.sqlite3", &db);
	ret = sqlite3_open("./yuntalk.sqlite", &db);
	if (ret != SQLITE_OK) {
		return -1;
	}
	//网络编程,心跳:用户登录后,间隔1,2秒就给服务器发信息(心跳)

//打开记住地址表
	sql = "select * from dizhi where count=?";
	ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		printf("ret = %d\n", ret);
		goto prepare_error;
	}

//判断是否已经存在
	sqlite3_bind_text(stmt, 1, j->count, -1, NULL);
	ret = sqlite3_step(stmt);
	if (ret == SQLITE_ROW) {
	//存在则更新update
		sqlite3_finalize(stmt);
		sql = "update dizhi set addr=? where count=?";
		ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (ret != SQLITE_OK) {
			goto prepare_error;
		}
		sqlite3_bind_blob(stmt, 1, addr, sizeof(*addr), NULL);
		sqlite3_bind_text(stmt, 2, j->count, -1, NULL);
		//error:没有接收返回值
		ret = sqlite3_step(stmt);
		if (ret != SQLITE_DONE) {
			goto step_error;
		}
	} else {
	//不存在则添加insert into
		sqlite3_finalize(stmt);
		sql = "insert into dizhi(count, addr) values(?, ?)";
		ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (ret != SQLITE_OK) {
			goto prepare_error;
		}
		sqlite3_bind_text(stmt, 1, j->count, -1, NULL);
		sqlite3_bind_blob(stmt, 2, addr, sizeof(*addr), NULL);
//MDzzzzzzzzzzzzzzzzzzzzzzZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
		//sqlite3_step(stmt);
		ret = sqlite3_step(stmt);
		if (ret != SQLITE_DONE) {
printf("ret = %d\n", ret);
			goto step_error;
		}
	}

	sqlite3_finalize(stmt);

//查询用户的好友表,将好友一个一个发送给用户,客户端把好友放到好友列表
	//新的更方便的sql方法
	sprintf(sql1, "select * from %s", j->count);	
	ret = sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL);
	if (ret != SQLITE_OK) {
		printf("select * error\n");
		goto step_error;//	????????????????????????
	}

	//循环遍历好友表
	while (1) {
		//??????????????????????????怎么跳出循环
		printf("1=======\n");
		ret = sqlite3_step(stmt);
		printf("ret = %d\n", ret);
		//	找到了			//遍历完了
		//if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
		if (ret != SQLITE_ROW) {
			printf("1.5=====\n");
			goto step_error;
		}
		//获得stmt中count,就是好友账号
		count = (void *)sqlite3_column_text(stmt, 1);
		//构建结构体
		sprintf(haoyou.dcount, "%s", count);
		haoyou.status = HAOYOU_ITEM;
		//发送
		//error:addr已经是指针,发送失败,又没校验返回值
		sendto(sd, &haoyou, sizeof(haoyou), 0, (void *)addr, sizeof(*addr));
		printf("2=======\n");
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
	struct jizhudizhi_st jizhudizhi;
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


	//创建套接字,报式传输类型,UDP协议
	sd =  socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) {
		perror("socket()");
		exit(1);
	}

	//绑定端口号
	server_addr.sin_family = AF_INET;
	//端口号DENGLU_SERVER_PORT
	server_addr.sin_port = htons(JIZHUDIZHI_SERVER_PORT);
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
		ret = recvfrom(sd, &jizhudizhi, sizeof(jizhudizhi), 0, (void *)&client_addr, &addr_len);
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
			//处理记住地址
			ret = addr_handler(sd, &jizhudizhi, &client_addr);
			if (ret < 0) {
				fprintf(stderr, "jizhudizhi shibai\n");
			}

			exit(0);
		}
		//父进程继续循环阻塞接收数据
		//但子进程退出了没有wait收尸,需要处理僵尸进程
	}

	return 0;
}










