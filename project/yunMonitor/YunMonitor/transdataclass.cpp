#include "transdataclass.h"

//实现构造方法
TransDataClass::TransDataClass(QObject *parent) : QObject(parent)
{

}

//实现重载构造方法
TransDataClass::TransDataClass(int no, QObject *parent) : QObject(parent)
{
    memset(&pro, 0, sizeof(pro));
    this->pro.no = no;
}

//实现发送数据方法
void TransDataClass::sendDht22Data(struct dht22_pro_st *pro)
{
    //产生dataReady信号,传递数据给槽
    emit dataReady(pro);
}

//实现获取pro结构体地址
dht22_pro_st *TransDataClass::getPro()
{
    return &this->pro;
}
