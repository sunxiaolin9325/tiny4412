#include "login.h"
#include "ui_login.h"
//一般类名和头文件名是一致的
//一切皆对象,需要把图像构建成对象,构建对象
//就需要使用该类中的方法
//一般qt的类以Q开头
#include "QPixmap"
//用于调试打印
#include "qdebug.h"
//点击注册账号按钮,构建好注册界面对象后,调用show
#include "registerpage.h"
//点击登录按钮,构建好聊天界面,调用show
#include "chatpage.h"
//协议头文件
#include "protocal.h"
//登录失败的话需要显示失败结果
#include "showresultpage.h"
//md5加密
#include "QCryptographicHash"
//调用数据库,在.pro中添加头文件和库的路径
#include <sqlite3.h>

#include <qdebug.h>


//类名::方法
//实现构造函数
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
//根据login.ui文件构建界面
    ui->setupUi(this);
//自己完善界面
    QString *logoPath = new QString
            ("/home/lin/driver/program/project/yuntalk/image/logo.jpg");
    //方法中参数写了=,则参数可不传,选择默认的
    //&代表传引用,传引用就相当于传对象
    //构造了一个对象,*pix(对象)就是logoPath路径下的图片
    QPixmap *pix = new QPixmap(*logoPath);
    //设置图片的大小w宽度h高度
    //获得信息都得调用类中的方法
    int w = ui->logoLabel->width();
    int h = ui->logoLabel->height();
    //该方法返回一个新的对象传递给*pix
    //scaled比例,缩放
    *pix = pix->scaled(w, h);
    //ui就是当前界面的对象
    //headLabel是ui界面中的控件(对象),调用父类的setPixmap
    //方法,为控件设置了一张图片
    ui->logoLabel->setPixmap(*pix);

    QString *headPath = new QString
            ("/home/lin/driver/program/project/yuntalk/image/head.jpg");
    QPixmap *pix1 = new QPixmap(*headPath);

    //去掉int w 的int,不然重复定义了
    w = ui->headLabel->width();
    h = ui->headLabel->height();
    *pix1 = pix1->scaled(w, h);

    ui->headLabel->setPixmap(*pix1);

    //::sleep();
    //c++掉c函数,包含该头文件,用上面的方式调用

//创建socket,信号与槽
    //this->socket = new QUdpSocket();
    //不能阻塞收数据,目前客户端只有一个线程,用信号与槽函数收
    socket = new QUdpSocket();
    //报式传输udp协议客户端不用bind,自动分配端口号
    //socket->bind(11111);
    //连接信号与槽函数
    //当socket收到数据,出发信号,将信号与槽函数关联
    //SLOT:槽,SIGNAL(readyRead()):读信号
    connect(socket,SIGNAL(readyRead()),this,
                          SLOT(readDataHandler()));
//初始化private成员,还是在类中使用,并没有通过对象.成员
    rememberPasswd = false;
//打开(创建)数据库
    sqlite3_open("/home/lin/driver/program/project/yuntalk"
                 "/client.sqlite", &db);
}


//private方法,只能在Login类中使用,也只需要在类中使用
//不要new一个Login对象来用.
//实现记住密码
//在用户登录成功后,并且选中了记住密码就调用,
//用于创建数据库并保存到passwd表中.在用户输入账号
//时可以自动显示密码
int Login::rememberPasswdHandler()
{
    int ret;
    sqlite3_stmt *stmt;
    QByteArray c, p;
    const char *cc, *pp;

//创建passwd表
    const char *sql = "create table if not exists passwd(count text, passwd text)";
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK) {
        goto exec_error;
    }

//判断是否已经保存了密码
    sql = "select * from passwd where count=?";
    ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (ret != SQLITE_OK) {
        goto exec_error;
    }

    c = ui->countLineEdit->text().toLatin1();
    cc = c.data();

    sqlite3_bind_text(stmt, 1, cc, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret !=SQLITE_DONE && ret != SQLITE_ROW) {
        goto step_error;
    }

    sqlite3_finalize(stmt);
//有则update，无则insert
    if (ret == SQLITE_ROW) {
        sql = "update passwd set passwd=? where count=?";
    } else {
        sql = "insert into passwd(passwd, count) values(?, ?)";
    }

    ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (ret != SQLITE_OK) {
        goto exec_error;
    }

    p = ui->PasswdLineEdit->text().toLatin1();
    pp = p.data();

    sqlite3_bind_text(stmt, 1, pp, -1, NULL);
    sqlite3_bind_text(stmt, 2, cc, -1, NULL);

    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE) {
        goto step_error;
    }

    sqlite3_finalize(stmt);
    return 0;

step_error:
    sqlite3_finalize(stmt);
exec_error:
//qDebug() << 123;
    return -1;
}

//登录过程
//1.client-->server
//2.server-->client
//用于接受socket数据的槽函数实现,有数据时调用
void Login::readDataHandler()
{
//qDebug() << 100 << 200;
    struct denglu_st denglu;
    ChatPage *chatPage;
    ShowResultPage *result;
    //readDatagram:QUdpSocket类中的方法,收数据报,
    //在该登录界面只收denglu_st数据,与C中receve函数相似
    //方法中的传参类型必须一致
    socket->readDatagram((char *)&denglu,
                         sizeof(denglu));
    switch (denglu.status) {
//登录成功show聊天界面
    case DENGLU_STATUS_OK:
        chatPage = new ChatPage();
        chatPage->setAttribute(Qt::WA_DeleteOnClose);
        //登录成功了给聊天界面传个账号信息
        chatPage->myCount = ui->countLineEdit->text();
        //chatPage->show();
        //调用重写方法
        chatPage->chatPageShow(
                    ui->countLineEdit->text());
    //如果选中了记住密码,就把密码放到数据库
        //没选中的话应该清除之前保存过的密码
        if (rememberPasswd == 1)
            rememberPasswdHandler();
        //登录后关闭登录界面
    //close();
        break;
//登录失败show结果界面
    case DENGLU_STATUS_ERROR:
        result = new ShowResultPage();
        result->setAttribute(Qt::WA_DeleteOnClose);
        result->setShowLabelMsg(QString("登录失败"));
        result->setOkButtonMsg(QString("重新登录"));
        result->setCancelButtonMsg(QString("取消登录"));
        result->show();
        break;
    default:
        break;
    }
}

//实现析构方法
Login::~Login()
{
    sqlite3_close(db);
    //释放对象
    delete ui;
}

//槽函数,点击注册按钮后调用
void Login::on_pushButton_clicked()
{
    //qDebug("%d", 100);
    //<<输出流
    //qDebug()<<100<<200<<endl;
    //1.构建一个注册界面对象
    //相当于malloc了,当用户关闭对象时要free
    RegisterPage *registerPage =
            new RegisterPage();
    //设置这个属性就实现了关闭时free
    //Qt::枚举类型
    registerPage->setAttribute(Qt::WA_DeleteOnClose);
    //2让对象显示
    registerPage->show();
}


//槽函数,点击登录按钮后调用
//给服务器发数据
void Login::on_pushButton_3_clicked()
{
    struct denglu_st denglu;

    //text()方法获得控件中字符串对象
    QString count = ui->countLineEdit->text();
    QString passwd = ui->PasswdLineEdit->text();
    //通过toLatin1()方法把字符串对象返回为字符数组对象
    QByteArray c = count.toLatin1();
    QByteArray p = passwd.toLatin1();
    //通过hash()方法给字符数组对象加密返回
    p = QCryptographicHash::hash(p,QCryptographicHash::Md5);

passwd.clear();
passwd.append(p.toHex());
p = passwd.toLatin1();

    //通过data()方法返回得到字符串
    char *cc = c.data();
    char *pp = p.data();
    //讲字符串打印到结构体中的count数组
    qsnprintf(denglu.count,COUNT_SIZE,"%s",cc);
    qsnprintf(denglu.passwd,COUNT_SIZE,"%s",pp);

    //IP地址字符串转换为QHostAddress类的对象
    //端口号是数字,在C中也是
    QHostAddress *address = new
            QHostAddress(QString(DENGLU_SERVER_IP));
    //通过QUdpSocket类中的方法writeDatagram,相当于c中
    //的sendto(),发送数据
    socket->writeDatagram((const char *)&denglu,
                          sizeof(denglu),*address,
                          DENGLU_SERVER_PORT);
}


//记住密码按钮槽函数
//在登录界面点击一下就会调用一次
void Login::on_checkBox_clicked()
{
    //记住或者没记住
    rememberPasswd = ui->checkBox->isChecked();
}


//账号输入框槽函数
//用户输入什么就传过来什么
//实时出发调用
void Login::on_countLineEdit_textChanged(const QString &arg1)
{
    sqlite3_stmt *stmt;
    int ret;
    QByteArray c = arg1.toLatin1();
    char *cc = c.data();
//查询passwd表是时候有当前账号
    const char *sql = "select * from passwd where count=?";
    ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (ret != SQLITE_OK) {
        return;
    }

    sqlite3_bind_text(stmt, 1, cc, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE && ret != SQLITE_ROW) {
        sqlite3_finalize(stmt);
        return;
    }
//当前时刻账号输入框中的账号
//保存过密码则显示,反则清空密码框
    if (ret == SQLITE_ROW) {
        //获得stmt中的passwd
        char *p = (char *)sqlite3_column_text(stmt, 1);
        ui->PasswdLineEdit->setText(QString(p));
    } else {
        ui->PasswdLineEdit->clear();
    }

    sqlite3_finalize(stmt);
}


