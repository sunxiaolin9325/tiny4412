#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

struct data_pro_st {
	//是否控制
	int control;
	//开关状态
	int value1;
	//开关序号
	int value2;
	char msg[8];
};

//与用户态交互协议
struct nrf24l01_pro_st {
	char txaddr[5];
	char rxaddr[5];
	char tx_channel;
	char rx_channel;
	struct data_pro_st data;
};

struct nrf24l01_pro_st pro[3] = {
	[0] = {
		{0x34, 0x43, 0x10, 0x10, 0x01},
		{0x10, 0x20, 0x30, 0x40, 0x50}, 
		.tx_channel = 41,
		.rx_channel = 40,
		.data = {},
	},
	[1] = {
		{0x11, 0x22, 0x33, 0x44, 0x55},
		{0xaa, 0xbb, 0xcc, 0xdd, 0xee},
		.tx_channel = 51,
		.rx_channel = 50,
		.data = {},
	},
	[2] = {
		{0x34, 0x43, 0x10, 0x10, 0x01},
		{0x10, 0x20, 0x30, 0x40, 0x50}, 
		.tx_channel = 61,
		.rx_channel = 60,
		.data = {},
	},
};

int main(void)
{
	int fd;
	int ret;
	int i = -1;
	/*
	struct nrf24l01_pro_st pro = {
		{0x34, 0x43, 0x10, 0x10, 0x01},
		{0x10, 0x20, 0x30, 0x40, 0x50}, 
		.tx_channel = 41,
		.rx_channel = 40,
		.data = {},
	};
	*/

	fd = open("/dev/nrf24l01", O_RDWR);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	while (1) {
		i++;
		if (i == 3) 
			i = 0;
		printf("i = %d\n", i);
		pro[i].data.control = 0;
		ret = write(fd, &pro[i], sizeof(pro[i]));
		if (ret < 0) {
			perror("write()");
			sleep(1);
			continue;
		//	exit(1);
		}

		//一定不能睡这么长时间,超时了
		//sleep(1);


		ret = read(fd, &pro[i], sizeof(pro[i]));
		if (ret < 0) {
			perror("read()");
			sleep(1);
			continue;
			//exit(1);
		}

		printf("ret = %d\n", ret);
		printf("temp.a= %s\n", pro[i].data.msg);
		printf("temp.b= %d\n", (pro[i].data.value2 >> 16) & 0xff);
		printf("water= %d\n", pro[i].data.value2 & 0xff);
		printf("pm2.5= %d\n", pro[i].data.value1);
		sleep(3);
	}

	close(fd);

	return 0;
}

