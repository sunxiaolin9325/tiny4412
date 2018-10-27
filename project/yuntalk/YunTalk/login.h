#ifndef LOGIN_H
#define LOGIN_H

//需要哪个类就包含相应头文件
#include <QWidget>
//网络socket编程,udp协议
#include <QUdpSocket>
//用客户端本地数据库保存用户的密码,实现记住密码
#include <sqlite3.h>

//相当于符号导出?
namespace Ui {
class Login;
}

//子类继承父类
class Login : public QWidget
{
    Q_OBJECT

    //公有的,对象使用
public:
    //两个方法都要实现
    //构造方法,new创建对象时就调用
    explicit Login(QWidget *parent = 0);
    //析构方法,释放对象时就调用
    ~Login();

    //槽函数的声明
private slots:
    void on_pushButton_clicked();

    //私有的,只能当前类Login使用
    void on_pushButton_3_clicked();

    //自己声明槽函数,socket收数据,登录是否成功
    void readDataHandler();

    void on_checkBox_clicked();

    void on_countLineEdit_textChanged(const QString &arg1);

private:
    //ui指向Login界面
    Ui::Login *ui;
    //创建一个socket属性,还不是对象
    QUdpSocket *socket;

    //是否选中记住密码按钮
    bool rememberPasswd;

    //用于链接数据库,直接在new创建对象的构造方法中就打开数据库,
    //在析构方法中,关闭数据库
    //在类中定义的属性相当于c中的全局变量,整个类(对象)中都能使用
    sqlite3 *db;
//私有方法,只能在类中使用
    //记住密码处理函数
    int rememberPasswdHandler();
};

#endif // LOGIN_H
