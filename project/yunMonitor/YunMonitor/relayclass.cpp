#include "relayclass.h"

#include <QDebug>

RelayClass::RelayClass(QObject *parent) : QObject(parent)
{

}

//实现方法
int RelayClass::openRealy()
{
    relay = ::open("/dev/relay", O_RDWR);
    if (relay < 0) {
        qDebug() << "open /dev/relay error";
        return -1;
    }

    return 0;
}

int RelayClass::closeRelay()
{
    ::close(relay);
    return 0;
}

//指定继电器工作
int RelayClass::writeRelay(relay_pro_st *pro)
{
    int ret;

    ret = ::write(relay, pro, sizeof(*pro));
    if (ret < 0) {
        qDebug() << "write /dev/ralay error";
        return -1;
    }

    return 0;
}

//复位专用
int RelayClass::ioctlRelay(relay_pro_st *pro)
{
    int ret;

    //参数没啥用
    pro->work = 0;
    ret = ::ioctl(relay, 0, 0);
    if (ret < 0) {
        qDebug() << "ioctl /dev/ralay error";
        return -1;
    }

    return 0;
}





