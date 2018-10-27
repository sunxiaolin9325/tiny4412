#include "chatpage.h"
#include "ui_chatpage.h"
//构建addfriendpage对象,show
#include "addfriendpage.h"
//构建setuppage对象,show
#include "setuppage.h"
//协议头文件
#include "protocal.h"
//
#include <qdebug.h>


//构造函数,当new一个对象出来是就会调用
//而不是打开或关闭一个ui界面
ChatPage::ChatPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatPage)
{
    ui->setupUi(this);
//设置头像
    //把文件(路径)转换为字符串对象
    QString *headPath = new QString
            ("/home/lin/driver/program/project/yuntalk/image/head.jpg");
    //把字符串对象(图像,文件)转换成图像对象
    QPixmap *headPix = new QPixmap(*headPath);
    //设置图像对象的大小与控件对象的size一致
    *headPix = headPix->scaled(ui->headLabel->size());
    //把图像对象放到(转换成)控件对象
    //setPixmap用于转换QLabel类
    ui->headLabel->setPixmap(*headPix);

//设置添加按钮
    QString *addPath = new QString
            ("/home/lin/driver/program/project/yuntalk/image/add.jpg");
    QPixmap *addPix = new QPixmap(*addPath);
    *addPix = addPix->scaled(ui->addButton->size());
    //setIcon用于转换QPushButton类
    //注意要使用QIcon进行转换
    ui->addButton->setIcon(QIcon(*addPix));

//设置设置按钮
    QString *setupPath = new QString
            ("/home/lin/driver/program/project/yuntalk/image/setup.jpg");
    QPixmap *setupPix = new QPixmap(*setupPath);
    *setupPix = setupPix->scaled(ui->setupButton->size());
    ui->setupButton->setIcon(QIcon(*setupPix));

    socket = new QUdpSocket();
    connect(socket,SIGNAL(readyRead()),this,
            SLOT(readDataHandler()));

//定时器
    timer = new QTimer();
    //连接定时器信号与槽
    connect(timer,SIGNAL(timeout()),this,SLOT(timerHandler()));
    //定时1s,同时定时器也启动了
    timer->start(1000);
}


//定时器的槽函数,定时器超时就触发一次
void ChatPage::timerHandler()
{
    //获得当前时间
    QDateTime dateTime = QDateTime::currentDateTime();
    //转换为字符串格式的字符串对象
    QString t = dateTime.toString(QString("yy-MM-dd hh:mm:ss"));
    //lcdNumber控件显示t的值
    //display()方法与settext()方法相似
    ui->lcdNumber->display(t);
}


//信号与槽,收到数据触发信号调用该函数
//收到的有,好友表信息和聊天信息
void ChatPage::readDataHandler()
{
    struct liaotian_st liaotian;
    QTreeWidgetItem *item;
    QString msg;

    //收消息
    socket->readDatagram((char *)&liaotian,
                         sizeof(liaotian),
                         NULL,NULL);
    switch (liaotian.status) {
    //聊天失败信息
    case LIAOTIAN_STATUS_ERROR:
        break;
    //收到聊天信息
    case LIAOTIAN_STATUS_OK: 
        //把收到的消息包装一下
        msg.clear();
        msg.append(QString("<font size=5 color=red>"));
        msg.append(QString("["));
        //msg.append(ui->friendLabel->text());
        msg.append(QString(liaotian.src_count));
        msg.append(QString("]: "));
        msg.append(QString(liaotian.msg));
        msg.append(QString("</font>"));
        //把包装号的消息追加到chat文本框中
        ui->chatTextEdit->append(msg);
        break;
    //好友表信息
    case HAOYOU_ITEM:
    //构建好友列表中的item
        item = new QTreeWidgetItem(ui->friendList);
        item->setIcon(0, QIcon(QString(
            "/home/lin/driver/program/project/yuntalk/"
             "image/head.jpg")));
        item->setText(0, QString(liaotian.dst_count));
        break;
    }
}


//show方法的重写的实现
//当show出聊天界面时,就给记住地址服务器发送账号信息
void ChatPage::chatPageShow(QString count)
{
    //把登录时账户赋值给聊天界面
    myCount = count;
    struct jizhudizhi_st jizhudizhi;
    QByteArray c = count.toLatin1();
    char *cc = c.data();

    qsnprintf(jizhudizhi.count,COUNT_SIZE,
              "%s",cc);
    QHostAddress *address = new
            QHostAddress(JIZHUDIZHI_SERVER_IP);
    socket->writeDatagram(
                (const char*)&jizhudizhi,
                sizeof(jizhudizhi),*address,
                JIZHUDIZHI_SERVER_PORT);

    //QTreeWidgetItem类是QTreeWidget控件(类)
    //中的一个条目item(好友列表的一行)
    QTreeWidgetItem *item = new
            QTreeWidgetItem(ui->friendList);
    //设置item的头像
    item->setIcon(0,QIcon(QString
                  ("/home/lin/driver/program/project/yuntalk/image/head.jpg")));
    //设置item的文本
    item->setText(0,count);

//正在聊天中的好友label默认是自己
    ui->friendLabel->setText(myCount);

    show();
}


//析构方法
ChatPage::~ChatPage()
{
    delete ui;
}


//槽函数,点击添加好友按钮调用
void ChatPage::on_addButton_clicked()
{
    AddFriendPage *add =
            new  AddFriendPage();
    add->setAttribute(Qt::WA_DeleteOnClose);
    //指针的传递
    //界面ui和控件都是对应类型的指针
    add->friendList = ui->friendList;
    //登录界面-->聊天界面-->添加好友界面
    add->myCount = myCount;
    //调用自己实现的show方法
    add->addFriendShow();
}


//槽函数,点击设置按钮调用
void ChatPage::on_setupButton_clicked()
{
    SetupPage *setupPage = new SetupPage();
    setupPage->setAttribute(Qt::WA_DeleteOnClose);
    setupPage->show();
}


//点击发送按钮,发送信息给服务器
void ChatPage::on_sendButton_clicked()
{
    //<font size=16 color=blue>nihao</font>
    //html
    QString msg;

    //准备好文本
    msg.clear();
    msg.append(QString("<font size=5 color=blue>"));
    msg.append(QString("["));
    msg.append(myCount);
    //msg.append(QString("--->"));
    //msg.append(ui->friendLabel->text());
    msg.append(QString("]: "));
    msg.append(ui->sendTextEdit->toPlainText());
    msg.append(QString("</font>"));

//把聊天信息追加到本地chat文本框,append自动换行
    ui->chatTextEdit->append(msg);

//把聊天信息发给服务器
    struct liaotian_st liaotian;
    //构建结构体数据
    //text()方法:从控件中得到字符串对象
    //settext()方法:为控件设置字符串对象
    //toLatin1()方法:字符串对象转字符数组对象
    //data()方法:字符数组对象转字符串
    //toPlainText()方法:xxx控件转换为字符串对象
    msg = ui->sendTextEdit->toPlainText();
    QByteArray ba = msg.toLatin1();
    QByteArray ba1 = myCount.toLatin1();
    QByteArray ba2 = ui->friendLabel->text().toLatin1();
    const char *m = ba.data();
    const char *sc = ba1.data();
    const char *dc = ba2.data();

    qsnprintf(liaotian.dst_count, COUNT_SIZE, dc);
    qsnprintf(liaotian.src_count, COUNT_SIZE, sc);
    qsnprintf(liaotian.msg, MSG_COUNT_SIZE, m);
    //socket发送
    QHostAddress *address =
            new QHostAddress(QString(LIAOTIAN_SERVER_IP));
    socket->writeDatagram((const char *)&liaotian,
                          sizeof(liaotian), *address,
                          LIAOTIAN_SERVER_PORT);
    //清空send文本框里的文本
    ui->sendTextEdit->clear();
}


//双击好友列表槽函数
void ChatPage::on_friendList_doubleClicked(const QModelIndex &index)
{
    //双击item得到item中的文本或者头像
    QTreeWidgetItem *item = ui->friendList->currentItem();
    ui->friendLabel->setText(item->text(0));
}







