#include "nrf24l01class.h"

#include <QDebug>

Nrf24l01Class::Nrf24l01Class(QObject *parent) : QObject(parent)
{

}

//实现方法
int Nrf24l01Class::openNrf24l01()
{
    nrf24l01 = ::open("/dev/nrf24l01", O_RDWR);
    if (nrf24l01 < 0) {
        qDebug("nrf24l01 = %d\n", nrf24l01);
        qDebug() << "open /dev/nrf24l01 error";
        return -1;
    }

    return 0;
}

int Nrf24l01Class::closeNrf24l01()
{
    ::close(nrf24l01);
    return 0;
}

int Nrf24l01Class::readNrf24l01(nrf24l01_pro_st *pro)
{
    int ret;

    ret = ::read(nrf24l01, pro, sizeof(*pro));
    if (ret < 0) {
        qDebug() << "read /dev/nrf24l01 error";
        return -1;
    }

    return 0;
}

int Nrf24l01Class::writeNrf24l01(nrf24l01_pro_st *pro)
{
    int ret;

    ret = ::write(nrf24l01, pro, sizeof(*pro));
    if (ret < 0) {
        qDebug() << "write /dev/nrf24l01 error";
        return -1;
    }

    return 0;
}


