#ifndef DHT22CLASS_H
#define DHT22CLASS_H

#include <QObject>

//c的头文件
extern "C" {
#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
}

#define NUM     6

//用户与内核交互的协议
struct dht22_pro_st {
    int no;
    int temp;
    int humi;
};

class Dht22Class : public QObject
{
    Q_OBJECT
public:
    explicit Dht22Class(QObject *parent = 0);
    //提供几个方法
    int openDht22();
    int readDht22Data(dht22_pro_st *pro);
    int closeDht22();

signals:

public slots:

private:
    //私有属性,只能在类中使用,这里用作fd
    int dht22;
};

#endif // DHT22CLASS_H
