#ifndef TRANSDATACLASS_H
#define TRANSDATACLASS_H

#include <QObject>

#include "dht22class.h"

class TransDataClass : public QObject
{
    Q_OBJECT
public:
    explicit TransDataClass(QObject *parent = 0);
    explicit TransDataClass(int no, QObject *parent = 0);
    //发送数据,用作发信号
    void sendDht22Data(struct dht22_pro_st *pro);
    //获取协议结构体,得到no值
    dht22_pro_st *getPro();

signals:
    //信号:信号与槽,绑定该信号的槽函数会被触发调用,
    //信号可以传递参数给槽函数
    void dataReady(struct dht22_pro_st *pro);

public slots:

private:
    struct dht22_pro_st pro;
};

#endif // TRANSDATACLASS_H
