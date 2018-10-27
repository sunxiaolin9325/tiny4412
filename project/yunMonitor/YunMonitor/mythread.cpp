#include "mythread.h"

//创建MyThread线程后,通过调用AdcClass中的方法读/dec/myadc
//线程从run方法开始执行

//实现构造方法.
MyThread::MyThread()
{
    //打开adc设备文件
    dht22Class = new Dht22Class();
    dht22Class->openDht22();
}

//MyThread方法的重载,接受一个对象的引用
MyThread::MyThread(TransDataClass *transData)
{
    this->transData = transData;
    //打开adc设备
    dht22Class = new Dht22Class();
    dht22Class->openDht22();
}

//自己添加是实现析构方法,也没被调用
MyThread::~MyThread()
{
     dht22Class->closeDht22();
     delete dht22Class;
}

//实现线程执行方法,线程被start后要做的事
//当读到数据后,通过TransDataClass中的方法将数据被包含在信号里,
//将信号发给homePage
void MyThread::run()
{
    while (1) {
        //调用读/dev/dht22的函数
        dht22Class->readDht22Data(transData->getPro());
        //qDebug("no = %d\n", pro.no);
        //有数据返回,就发送信号(传递数据)给主界面
        //这里的transData指向的对象是主界面new的对象了
        transData->sendDht22Data(transData->getPro());
        //至少间隔一秒发一次
        ::sleep(3);
    }
}



