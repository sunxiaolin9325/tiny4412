#ifndef SHOWRESULTPAGE_H
#define SHOWRESULTPAGE_H

#include <QDialog>

namespace Ui {
class ShowResultPage;
}

class ShowResultPage : public QDialog
{
    Q_OBJECT

public:
    explicit ShowResultPage(QWidget *parent = 0);
    ~ShowResultPage();

    //声明了三个方法,在对应的cpp中实现,包含该头文件的
    //cpp就可以调用该方法,在Login.cpp中的注册账号
    //按钮槽函数中调用,设置注册界面的信息
    void setOkButtonMsg(QString msg);
    void setCancelButtonMsg(QString msg);
    void setShowLabelMsg(QString msg);

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::ShowResultPage *ui;
};

#endif // SHOWRESULTPAGE_H
