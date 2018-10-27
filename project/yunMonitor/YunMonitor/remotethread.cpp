#include "remotethread.h"
#include "qdebug.h"

RemoteThread::RemoteThread()
{
    nrf24l01Class = new Nrf24l01Class();
    nrf24l01Class->openNrf24l01();
}

RemoteThread::RemoteThread(RemoteTansDataClass *remoteTransData)
{
    this->remoteTransData = remoteTransData;
    nrf24l01Class = new Nrf24l01Class();
    nrf24l01Class->openNrf24l01();
}

RemoteThread::~RemoteThread()
{
    nrf24l01Class->closeNrf24l01();
    delete nrf24l01Class;
}

void RemoteThread::run()
{
    int i = 0;
    nrf24l01_pro_st pro[3] = {
        {
            {0x34, 0x43, 0x10, 0x10, 0x01},
            {0x10, 0x20, 0x30, 0x40, 0x50},
            41,
            40,
            {0, 0, 0, {}},
        },
        {
            {0x11, 0x22, 0x33, 0x44, 0x55},
            {0xaa, 0xbb, 0xcc, 0xdd, 0xee},
            51,
            50,
            {0, 0, 0, {}},
        },
        {
            {0x34, 0x43, 0x10, 0x10, 0x01},
            {0x10, 0x20, 0x30, 0x40, 0x50},
            61,
            60,
            {0, 0, 0, {}},
        },
    };

    while (1) {
        for (i=0; i<3; i++) {
            pro[i].data.control = 0;
            //发送指令
            nrf24l01Class->writeNrf24l01(&pro[i]);
            //读nrf24l01收到的数据
            nrf24l01Class->readNrf24l01(&pro[i]);
            qDebug() << "00000000000000";
            //将读到的数据发送到主界面,remoteTransData引用主界面的对象
            remoteTransData->sendNrf24l01Data(&pro[i]);
            qDebug() << "111111111111111111";
        }

        ::sleep(3);
    }
}
