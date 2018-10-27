#ifndef ADDFRIENDPAGE_H
#define ADDFRIENDPAGE_H

#include <QDialog>
//在添加好友界面点击添加按钮,需要向服务器发送数据
#include <QUdpSocket>
//在添加好友界面中操作聊天界面的QTreeWidget类控件(好友列表)
#include <qtreewidget.h>

namespace Ui {
class AddFriendPage;
}

class AddFriendPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriendPage(QWidget *parent = 0);
    ~AddFriendPage();

    //跨界面操作
    //在添加好友界面类里添加了一个好友列表类的属性
    //就可以在添加好友界面操作好友列表
//public公有变量(属性),对象可以直接使用
    QTreeWidget *friendList;
    //用于添加好友的,知道双方的信息
    QString myCount;

    //自己实现show方法,重写
    void addFriendShow();

//自己添加槽函数类型
private slots:
    void readDataHandler();

    void on_pushButton_clicked();

private:
    Ui::AddFriendPage *ui;
    QUdpSocket *socket;
};

#endif // ADDFRIENDPAGE_H
