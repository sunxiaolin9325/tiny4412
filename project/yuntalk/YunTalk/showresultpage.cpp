#include "showresultpage.h"
#include "ui_showresultpage.h"
//包含该头文件
#include "registerpage.h"

ShowResultPage::ShowResultPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowResultPage)
{
    ui->setupUi(this);
}

ShowResultPage::~ShowResultPage()
{
    delete ui;
}

//这几个方法都属于ShowResultPage类
//这里是方法的实现,类包含的方法,等待被调用
void ShowResultPage::setOkButtonMsg(QString msg)
{
    //把msg放到okButton控件
    //setText设置一个控件的文本,
    //一般控件都有这个方法
    ui->okButton->setText(msg);
}

void ShowResultPage::setCancelButtonMsg(QString msg)
{
    ui->cancelButton->setText(msg);
}

void ShowResultPage::setShowLabelMsg(QString msg)
{
    ui->showLabel->setText(msg);
}

//这里也是方法的实现,槽函数的方法,对应的对象(取消按钮)被点击时调用
void ShowResultPage::on_cancelButton_clicked()
{
    //::close();才是C语言的函数
    //关闭对象
    close();

    //show注册界面
    RegisterPage *registerPage =
            new RegisterPage();
    registerPage->setAttribute(Qt::WA_DeleteOnClose);
    registerPage->show();
}

void ShowResultPage::on_okButton_clicked()
{
    close();
}
