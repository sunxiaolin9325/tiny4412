#include "menupage.h"
#include "ui_menupage.h"
#include <qdatetime.h>

#include <QDebug>

MenuPage::MenuPage(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MenuPage)
{
    ui->setupUi(this);
}

//重载,把homepage的db传过来
MenuPage::MenuPage(sqlite3 *db, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MenuPage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    this->db = db;
}

MenuPage::~MenuPage()
{
    delete ui;
}


//back按钮槽函数
void MenuPage::on_backPushButton_clicked()
{
    close();
}

//温度表按钮
void MenuPage::on_tempTablePushButton_clicked()
{
    //创建0行6列的表
    QTableWidget *tableWidget = new QTableWidget();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(6);
    //设置表格的大小
    tableWidget->resize(800, 480);
    //yun列宽自动平分完全填充    qt5/qt4
#if 0
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
#else
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
#endif
    //表格不允许编辑
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //
    tableWidget->setFont(QFont("WenQuanYi Zen Hei"));
    //设置标题栏内容
    tableWidget->setWindowTitle(QString::fromUtf8("温度/℃"));
    //设置表头内容
    tableWidget->setHorizontalHeaderLabels(
                            QStringList() << QString::fromUtf8("A区") << QString::fromUtf8("B区") << QString::fromUtf8("C区") << QString::fromUtf8("D区") << QString::fromUtf8("E区") << QString::fromUtf8("F区"));

    //从数据库读取数据
    char sql[256];
    sqlite3_stmt *stmt;
    int ret;

    for (int j=0; j<NUM; j++) {
        ::sprintf(sql, "select * from %cArea", 'A' + j);
        ret = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (ret != SQLITE_OK) {
            qDebug() << "prepare error";
            return;
        }

        for (int i=0; ; i++) {
            ret = sqlite3_step(stmt);
            if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
                qDebug() << "select error";
                sqlite3_finalize(stmt);
                return;
            }
            //遍历完跳出循环
            if (ret == SQLITE_DONE) {
                //重复free,段错误
                //sqlite3_finalize(stmt);
                break;
            }
            //添加一行,遍历A区的时候添加一次就可以了
            if (j == 0) {
                int row = tableWidget->rowCount();
                tableWidget->setRowCount(row + 1);
            }
            //设置单元格内容
            tableWidget->setItem(i, j, new
                                 QTableWidgetItem((const char *)sqlite3_column_text(stmt, 1)));
        }

        sqlite3_finalize(stmt);
    }

    tableWidget->show();
}

//实现show方法的重写
void MenuPage::menuPageShow(RemotePage *remotePage)
{
    this->remotePage = remotePage;
    show();
}


//不能在槽函数中循环,等待.在槽函数结束后,界面才会出来
void MenuPage::on_remotePushButton_clicked()
{
    remotePage->show();

    //qt5中有警告
    //结构体,数组,只有在定义时才能以{}初始化.
    //C++中要么不初始化,要么全部初始化
}

