#include "dht22class.h"

#include <QDebug>

//构造方法什么也不做
Dht22Class::Dht22Class(QObject *parent) : QObject(parent)
{

}

//实现打开设备节点文件方法
int Dht22Class::openDht22()
{
    //c语言方法
    dht22 = ::open("/dev/dht22", O_RDONLY);
    if (dht22 < 0) {
        qDebug() << "open /dev/dht22 error";
        return -1;
    }

    return 0;
}

//实现关闭文件方法
int Dht22Class::closeDht22()
{
    ::close(dht22);
    return 0;
}

//实现读设备方法
int Dht22Class::readDht22Data(dht22_pro_st *pro)
{
    int ret;

    //error:参数
    ret = ::read(dht22, pro, sizeof(*pro));
    if (ret < 0) {
        qDebug() << "read /dev/dht22 error";
        return -1;
    }

    return 0;
}

