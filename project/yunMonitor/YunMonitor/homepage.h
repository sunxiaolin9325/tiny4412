#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "dht22class.h"
#include "menupage.h"
#include "mythread.h"
#include "transdataclass.h"
#include <sqlite3.h>

#include "relayclass.h"

#include "remotethread.h"
#include "remotepage.h"

//yun
//#define PATH    "/home/lin/driver/program/project/git/yunMonitor"
#define PATH    "/root"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

private slots:
    void on_quitPushButton_clicked();

    void on_menuPushButton_clicked();

    //收到dht22的值
    void readDataHandler(dht22_pro_st *pro);
    //收到nrf24l01的信号
    void remoteReadDataHandler(nrf24l01_pro_st *pro);

    void on_resetPushButton_clicked();

private:
    Ui::HomePage *ui;
    TransDataClass *transData[NUM];
    RemoteTansDataClass *remoteTransData;
    MyThread *readDataThread[NUM];
    RemoteThread *remoteReadDataThread;

    //用于链接数据库
    sqlite3 *db;
    //整个类中都可以使用,打开relay,写relay
    RelayClass *relayClass;
    //Nrf24l01Class *nrf24l01Class;
    //创建对象后,传递给menupage
    RemotePage *remotePage;
};

#endif // HOMEPAGE_H
