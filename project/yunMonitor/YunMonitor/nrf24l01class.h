#ifndef NRF24L01CLASS_H
#define NRF24L01CLASS_H

#include <QObject>

extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
}

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

class Nrf24l01Class : public QObject
{
    Q_OBJECT
public:
    explicit Nrf24l01Class(QObject *parent = 0);
    //提供方法
    int openNrf24l01();
    int closeNrf24l01();
    int readNrf24l01(nrf24l01_pro_st *pro);
    int writeNrf24l01(nrf24l01_pro_st *pro);

signals:

public slots:

private:
    int nrf24l01;
};

#endif // NRF24L01CLASS_H
