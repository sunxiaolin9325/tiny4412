#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QDialog>
//socket
#include <qudpsocket.h>
//定时器类
#include <qtimer.h>
//时间日期类
#include <QDateTime>

namespace Ui {
class ChatPage;
}

class ChatPage : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget *parent = 0);
    ~ChatPage();

    //自己实现show方法(方法的重写),可以传递自己的参数
    void chatPageShow(QString count);
//公有public变量(属性),对象可以直接使用
    QString myCount;

//都是槽函数
private slots:
    void on_addButton_clicked();

    void on_setupButton_clicked();

    void on_sendButton_clicked();

    void on_friendList_doubleClicked(const QModelIndex &index);

    //收数据槽函数
    void readDataHandler();
    //定时器槽函数
    void timerHandler();


private:
    Ui::ChatPage *ui;

    QUdpSocket *socket;
    //定时器
    QTimer *timer;

};

#endif // CHATPAGE_H
