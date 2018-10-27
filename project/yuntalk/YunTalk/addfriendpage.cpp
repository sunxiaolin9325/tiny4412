#include "addfriendpage.h"
#include "ui_addfriendpage.h"
#include "protocal.h"
#include "showresultpage.h"

AddFriendPage::AddFriendPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriendPage)
{
    ui->setupUi(this);

    socket = new QUdpSocket();
    connect(socket,SIGNAL(readyRead()),
            this, SLOT(readDataHandler()));

}

//信号与槽,收数据
void AddFriendPage::readDataHandler()
{
    struct tianjiahaoyou_st tianjiahaoyou;
    QTreeWidgetItem *item;

    //new一个显示结果界面
    ShowResultPage *showResult = new
            ShowResultPage();
    showResult->setAttribute(Qt::WA_DeleteOnClose);

//socket收数据
    socket->readDatagram((char *)&tianjiahaoyou,
                         sizeof(tianjiahaoyou),
                         NULL,NULL);
//判断是否添加成功
    switch (tianjiahaoyou.status) {
    case TIANJIAHAOYOU_STATUS_OK:
        //friendList指针来自聊天界面
    //成功,给friendList添加一个条目,并设置头像,文本
        item = new
                QTreeWidgetItem(friendList);
        item->setIcon(0,QIcon
                      (QString("/home/lin/driver/program/"
                               "project/yuntalk/image/head.jpg")));
        item->setText(0,tianjiahaoyou.dst_count);

        showResult->setShowLabelMsg(QString("添加成功"));
        showResult->setOkButtonMsg(QString("继续添加"));\
        showResult->setCancelButtonMsg(QString("立即畅聊"));
        showResult->show();
        break;
    case TIANJIAHAOYOU_STATUS_ERROR:
    //失败,显示结果
        if(tianjiahaoyou.flag == 0) {
            showResult->setShowLabelMsg(QString("添加失败"));
            showResult->setOkButtonMsg(QString("重新添加"));\
            showResult->setCancelButtonMsg(QString("不添加了"));
        } else {
            showResult->setShowLabelMsg(QString("好友已经存在"));
            showResult->setOkButtonMsg(QString("继续添加"));\
            showResult->setCancelButtonMsg(QString("不添加了"));
        }
        showResult->show();
        break;
    default:
        break;
    }
}

//自己实现show方法,重写
void AddFriendPage::addFriendShow()
{
    //自己的方法啥也没做
    show();
}

AddFriendPage::~AddFriendPage()
{
    delete ui;
}

//添加按钮的槽函数
void AddFriendPage::on_pushButton_clicked()
{
//构建添加好友结构体发送给server
    struct tianjiahaoyou_st tianjiahaoyou;

    QString dstCount = ui->lineEdit->text();
    //myCount的值来自聊天界面
    QByteArray dc = dstCount.toLatin1();
    QByteArray sc = myCount.toLatin1();
    char *dst = dc.data();
    char *src = sc.data();
    qsnprintf(tianjiahaoyou.dst_count, COUNT_SIZE,
              "%s", dst);
    qsnprintf(tianjiahaoyou.src_count, COUNT_SIZE,
              "%s", src);

//socket发送
    QHostAddress *address = new
            QHostAddress(QString(TIANJIAHAOYOU_SERVER_IP));
    socket->writeDatagram(
                (const char *)&tianjiahaoyou,
                sizeof(tianjiahaoyou), *address,
                TIANJIAHAOYOU_SERVER_PORT);
}













