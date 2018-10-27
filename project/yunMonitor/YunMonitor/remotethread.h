#ifndef REMOTETHREAD_H
#define REMOTETHREAD_H

#include <QObject>
#include <QThread>
#include "remotetansdataclass.h"

class RemoteThread : public QThread
{
    Q_OBJECT
public:
    RemoteThread();
    RemoteThread(RemoteTansDataClass *remoteTransData);
    ~RemoteThread();

private:
    void run();
    //接收重载方法中的引用
    RemoteTansDataClass *remoteTransData;
    //用于创建对象,类中全局变量
    Nrf24l01Class *nrf24l01Class;

signals:

public slots:
};

#endif // REMOTETHREAD_H
