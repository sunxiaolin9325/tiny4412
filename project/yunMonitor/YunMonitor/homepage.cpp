#include "homepage.h"
#include "ui_homepage.h"
#include <sqlite3.h>
#include <qdebug.h>

HomePage::HomePage(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::HomePage)
{
    ui->setupUi(this);
    //调用该构造方法的对象(ui界面)没有标题栏(边框)
    setWindowFlags(Qt::FramelessWindowHint);

    //创建remotePage对象
    remotePage = new RemotePage();

    //创建transData对象,对象中有个信号成员
    //transData:对象
    //dataReady():对象中的信号成员
    //int:发送信号是传递的参数
    //this:本对象transData
    //readDataHandler:绑定的槽函数
    //int:与int值一样,传递过来的
    for (int i=0; i<NUM; i++) {
        transData[i] = new TransDataClass(i);
        connect(transData[i], SIGNAL(dataReady(struct dht22_pro_st *)),this,
                SLOT(readDataHandler(struct dht22_pro_st *)));
    }

    //创建remoteTransData对象
    remoteTransData = new RemoteTansDataClass;
    connect(remoteTransData, SIGNAL(remoteDataReady(nrf24l01_pro_st*)), this,
            SLOT(remoteReadDataHandler(nrf24l01_pro_st *)));

    //创建ReadDataThread线程,调用重载方法
    //将TransDataClass对象的引用传递给ReadDataThread线程
    //该对象中有个成员就是dataReady信号,所以要一一对应,
    //向指定对象发信号,调用指定对象绑定的槽函数
    for (int i=0; i<NUM; i++) {
        readDataThread[i] =
                        new MyThread(transData[i]);
        //启动线程
        readDataThread[i]->start();
    }

    //yun调用了没有重载的构造方法,导致错误
    //创建remoteThread线程
    remoteReadDataThread = new RemoteThread(remoteTransData);
    remoteReadDataThread->start();

    //创建或打开数据库,创建表
    //要链接LIBS+=-lsqlite3库
    //打开数据局,实时保存检测到的数据
    sqlite3_open(PATH"/monitor.sqlite", &db);

    //为每个区域创建一张表
    char sql[256];
    int ret;

    for (int i=0; i<NUM; i++) {
        ::sprintf(sql, "create table if not exists %cArea(no integer primary key autoincrement not null, "
                       "temperature float, humidity float)", i + 'A');
        ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
        if (ret != SQLITE_OK) {
            qDebug() << "create table error";
        }
    }

    //创建relay对象,并打开设备文件
    relayClass = new RelayClass();
    relayClass->openRealy();

    //!!!这里不要创建,由线程来创建,打开,读取
    //创建nrf24l01对象,并打开设备文件
    // nrf24l01Class = new Nrf24l01Class();
    //nrf24l01Class->openNrf24l01();

}

void HomePage::remoteReadDataHandler(nrf24l01_pro_st *pro)
{
    qDebug() << "222222222222222";
    switch (pro->rx_channel) {
    case 40:
        remotePage->setATemperatureLabel(QString(QString::number((pro->data.value2 >> 16) & 0xff)));
        remotePage->setAHumidityLabel(QString(QString::number(pro->data.value2 & 0xff)));
        remotePage->setAPm25Label(QString(QString::number(pro->data.value1)));
        break;
    case 50:
        remotePage->setBTemperatureLabel(QString(QString::number((pro->data.value2 >> 16) & 0xff)));
        remotePage->setBHumidityLabel(QString(QString::number(pro->data.value2 & 0xff)));
        remotePage->setBPm25Label(QString(QString::number(pro->data.value1)));
        break;
    case 60:
        remotePage->setCTemperatureLabel(QString(QString::number((pro->data.value2 >> 16) & 0xff)));
        remotePage->setCHumidityLabel(QString(QString::number(pro->data.value2 & 0xff)));
        remotePage->setCPm25Label(QString(QString::number(pro->data.value1)));
        break;
    default:
        break;
    }
}

//实现信号与槽函数
void HomePage::readDataHandler(struct dht22_pro_st *pro)
{
    char sql[256];
    int ret;
    QLabel *tempLabel, *humiLabel, *stateLabel;

    //保存到数据库
    ::sprintf(sql, "insert into %cArea(temperature, humidity) values(%f, %f)", pro->no + 'A', pro->temp / 10.0, pro->humi / 10.0);
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK) {
        qDebug() << "insert into error";
    }

    //显示到界面
    switch (pro->no) {
    case 0:
        tempLabel = ui->aTemperatureLabel;
        humiLabel = ui->aHumidityLabel;
        stateLabel = ui->aStateLabel;
        break;
    case 1:
        tempLabel = ui->bTemperatureLabel;
        humiLabel = ui->bHumidityLabel;
        stateLabel = ui->bStateLabel;
        break;
    case 2:
        tempLabel = ui->cTemperatureLabel;
        humiLabel = ui->cHumidityLabel;
        stateLabel = ui->cStateLabel;
        break;
    case 3:
        tempLabel = ui->dTemperatureLabel;
        humiLabel = ui->dHumidityLabel;
        stateLabel = ui->dStateLabel;
        break;
    case 4:
        tempLabel = ui->eTemperatureLabel;
        humiLabel = ui->eHumidityLabel;
        stateLabel = ui->eStateLabel;
        break;
    case 5:
        tempLabel = ui->fTemperatureLabel;
        humiLabel = ui->fHumidityLabel;
        stateLabel = ui->fStateLabel;
        break;
    default:
        qDebug() << "invalid thread";
        return;
        //用break;编译会报警告,三个变量没有初始化.
    }

    tempLabel->setText(QString::number(pro->temp / 10.0, 'f', 1));
    humiLabel->setText(QString::number(pro->humi / 10.0, 'f', 1));
    if (pro->temp == 0 || pro->humi == 0) {
        //ui->aStateLabel->setStyleSheet("background-color:rgb(0, 0, 0)");
        stateLabel->setStyleSheet("background-color:blue");
    } else if (pro->temp >= 200 && pro->temp < 300 && pro->humi >= 200 && pro->humi < 900) {
        stateLabel->setStyleSheet("background-color:green");
    } else if (pro->temp >= 100 && pro->temp < 400 && pro->humi >= 100 && pro->humi < 950) {
        stateLabel->setStyleSheet("background-color:yellow");
    } else {
        stateLabel->setStyleSheet("background-color:red");
        //警报拉响
        relayClass->pro.no = pro->no;
        relayClass->pro.work = 1;
        relayClass->writeRelay(&relayClass->pro);
    }
}


HomePage::~HomePage()
{
    relayClass->closeRelay();
    delete relayClass;
    sqlite3_close(db);
    delete ui;
}


//quit按钮槽函数
void HomePage::on_quitPushButton_clicked()
{
    //程序异常结束-------------------------
    close();
}


//menu槽函数
void HomePage::on_menuPushButton_clicked()
{
    MenuPage *w = new MenuPage(db);
    //关闭xxx时free对象
    setAttribute(Qt::WA_DeleteOnClose);
    w->menuPageShow(remotePage);
}


//复位按钮槽函数
void HomePage::on_resetPushButton_clicked()
{
    //参数没啥用
    relayClass->ioctlRelay(&relayClass->pro);
}







