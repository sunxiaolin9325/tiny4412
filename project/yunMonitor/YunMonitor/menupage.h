#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QDialog>

#include <QTableWidget>
//#include <QTableWidgetItem>
#include <QHeaderView>
#include <sqlite3.h>

#include "dht22class.h"
#include "remotepage.h"
#include "nrf24l01class.h"

#include <QDialog>

namespace Ui {
class MenuPage;
}

class MenuPage : public QDialog
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = 0);
    explicit MenuPage(sqlite3 *db, QWidget *parent = 0);

    //重写show方法
    void menuPageShow(RemotePage *remotePage);

    ~MenuPage();

private slots:
    void on_backPushButton_clicked();

    void on_tempTablePushButton_clicked();

    void on_remotePushButton_clicked();

private:
    Ui::MenuPage *ui;
    sqlite3 *db;
    //整个类中使用,打开,关闭/dev/narf24l01
    Nrf24l01Class *nrf24l01;
    //接收homePage的传递
    RemotePage *remotePage;
};

#endif // MENUPAGE_H
