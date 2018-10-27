#ifndef MYTHREAD_H
#define MYTHREAD_H

//手动添加
#include <QObject>
#include <QThread>
#include "transdataclass.h"
#include "dht22class.h"

class MyThread : public QThread
{
    //必须添加
    Q_OBJECT
public:
    MyThread();
    //构造方法的重载
    MyThread(TransDataClass *transData);
    ~MyThread();

private:
    //定义一个私有属性,相当于类中的全局变量来使用
    Dht22Class *dht22Class;
    //线程被创建,start后从run()开始执行
    void run();
    //重载方法中接收TransDataClass的指针
    TransDataClass *transData;
};

#endif // MYTHREAD_H
