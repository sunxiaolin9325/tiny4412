#ifndef PROTOCAL_H
#define PROTOCAL_H

#define DEFAULT_SERVER_IP               "127.0.0.1"
//#define DEFAULT_SERVER_IP               "192.168.200.107"

//<==================register================>
#define COUNT_SIZE			64
#define ZHUCE_STATUS_OK			0
#define ZHUCE_STATUS_ERROR		1
//服务器的IP
#define ZHUCE_SERVER_IP			DEFAULT_SERVER_IP
#define ZHUCE_SERVER_PORT      		1234

#define ZHUCE_GENDER_MALE		0
#define ZHUCE_GENDER_FEMALE            	1 
struct zhuce_st {
	char count[COUNT_SIZE];
	char passwd[COUNT_SIZE];
	int gender;
	int status;	//是否注册成功
};
//zhuce table
//id(integer, count text, name text, passwd text)

//<==================login================>
#define DENGLU_STATUS_OK                 0
#define DENGLU_STATUS_ERROR          1
//注册服务器的IP
#define DENGLU_SERVER_IP                 DEFAULT_SERVER_IP
#define DENGLU_SERVER_PORT          1235

struct denglu_st {
	char count[COUNT_SIZE];
	char passwd[COUNT_SIZE];
	int status;	//是否登录成功
};

//<=================know address===========>
#define JIZHUDIZHI_SERVER_IP                DEFAULT_SERVER_IP
#define JIZHUDIZHI_SERVER_PORT          1236
#define JIZHUDIZHI_STATUS_OK                0
#define JIZHUDIZHI_STATUS_ERROR         1

struct jizhudizhi_st {
	char count[COUNT_SIZE];
	int status;
};

//denglu table
//denglu(id integer, count text, addr blob)

//<==================addFriend================>
#define TIANJIAHAOYOU_STATUS_OK                 0
#define TIANJIAHAOYOU_STATUS_ERROR          1
#define TIANJIAHAOYOU_STATUS_EXISTS         2
#define TIANJIAHAOYOU_SERVER_IP                 DEFAULT_SERVER_IP
#define TIANJIAHAOYOU_SERVER_PORT           1237

struct tianjiahaoyou_st {
	char src_count[COUNT_SIZE];
	char dst_count[COUNT_SIZE];
	//char name[COUNT_SIZE];//server write
	//1好友已经存在
	int flag;
	int status;
};

//hy_xxx table
//hy_xxx(id integer, count text, name text)

//<==================talk================>
#define LIAOTIAN_STATUS_OK                 0
#define LIAOTIAN_STATUS_ERROR          1
#define LIAOTIAN_SERVER_IP                 DEFAULT_SERVER_IP
#define LIAOTIAN_SERVER_PORT          	1238 
#define MSG_COUNT_SIZE                  1024

#define LIAOTIAN_CLIENT_PORT            8888

#define HAOYOU_ITEM                             2

struct liaotian_st {
	char scount[COUNT_SIZE];
	char dcount[COUNT_SIZE];
	char msg[MSG_COUNT_SIZE];
	int status;
};
#endif // PROTOCAL_H
