#include "registerpage.h"
#include "ui_registerpage.h"
//包含该头文件
#include "showresultpage.h"
//协议头文件
#include "protocal.h"
#include "qcryptographichash.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);

    //注册界面socket,信号与槽
    socket = new QUdpSocket();
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(readDataHandler()));
}

//收到server发送的注册信息数据后调用
void RegisterPage::readDataHandler()
{
    struct zhuce_st zhuce;

    //点击注册按钮时,创建showResultPage对象
    ShowResultPage *showResultPage =
            new ShowResultPage();
    showResultPage->setAttribute(Qt::WA_DeleteOnClose);

    socket->readDatagram((char *)&zhuce,sizeof(zhuce));
    switch (zhuce.status) {
    case ZHUCE_STATUS_OK:
        //该对象调用该类中的方法
        //方法的声明,方法的实现,方法的调用
        //这里是方法的调用
        showResultPage->setOkButtonMsg(QString("马上登录"));
        showResultPage->setCancelButtonMsg(QString("再试一次"));
        showResultPage->setShowLabelMsg("恭喜注册成功");
        break;
    case ZHUCE_STATUS_ERROR:
        showResultPage->setOkButtonMsg(QString("继续注册"));
        showResultPage->setCancelButtonMsg(QString("取消注册"));
        showResultPage->setShowLabelMsg("注册失败");
        break;
    default:
        break;
    }

    showResultPage->show();
    //点击注册后把自己关掉
    close();
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

//点击注册按钮执行槽函数
void RegisterPage::on_pushButton_clicked()
{
    struct zhuce_st zhuce;

    //从注册界面控件获取注册信息并进行转换
    QString count = ui->countLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();

    QByteArray c = count.toLatin1();
    QByteArray p = passwd.toLatin1();

    p = QCryptographicHash::hash
            (p,QCryptographicHash::Md5);

passwd.clear();
passwd.append(p.toHex());
p = passwd.toLatin1();

    char *cc = c.data();
    char *pp = p.data();

    qsnprintf(zhuce.count, COUNT_SIZE, "%s",cc);
    qsnprintf(zhuce.passwd, COUNT_SIZE, "%s",pp);

    //把注册信息发送给server
    QHostAddress *address = new
            QHostAddress(QString(ZHUCE_SERVER_IP));
    socket->writeDatagram((const char *)&zhuce,
                          sizeof(zhuce),*address,
                          ZHUCE_SERVER_PORT);
}








