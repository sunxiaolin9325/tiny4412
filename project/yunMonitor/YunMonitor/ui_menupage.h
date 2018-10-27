/********************************************************************************
** Form generated from reading UI file 'menupage.ui'
**
** Created: Sun May 14 19:24:23 2017
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPAGE_H
#define UI_MENUPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuPage
{
public:
    QPushButton *backPushButton;
    QPushButton *homePushButton;
    QPushButton *menuPushButton;
    QLabel *label_3;
    QLabel *label;
    QPushButton *setPasswdPushButton;
    QPushButton *resetPushButton;
    QPushButton *humiTablePushButton;
    QPushButton *remotePushButton;
    QPushButton *humiGraphPushButton;
    QPushButton *setAlarmPushButton;
    QPushButton *dateTimePushButton;
    QPushButton *tempGraphPushButton;
    QPushButton *tempTablePushButton;

    void setupUi(QDialog *MenuPage)
    {
        if (MenuPage->objectName().isEmpty())
            MenuPage->setObjectName(QString::fromUtf8("MenuPage"));
        MenuPage->resize(800, 480);
        MenuPage->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        backPushButton = new QPushButton(MenuPage);
        backPushButton->setObjectName(QString::fromUtf8("backPushButton"));
        backPushButton->setGeometry(QRect(0, 410, 160, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(32);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        backPushButton->setFont(font);
        backPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        homePushButton = new QPushButton(MenuPage);
        homePushButton->setObjectName(QString::fromUtf8("homePushButton"));
        homePushButton->setGeometry(QRect(320, 410, 160, 70));
        homePushButton->setFont(font);
        homePushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        menuPushButton = new QPushButton(MenuPage);
        menuPushButton->setObjectName(QString::fromUtf8("menuPushButton"));
        menuPushButton->setGeometry(QRect(640, 410, 160, 70));
        menuPushButton->setFont(font);
        menuPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(MenuPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 410, 800, 70));
        QFont font1;
        font1.setPointSize(30);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(211, 219, 43);\n"
"background-color: rgb(35, 35, 35);"));
        label_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(MenuPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 60));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(230, 127, 118);"));
        label->setAlignment(Qt::AlignCenter);
        setPasswdPushButton = new QPushButton(MenuPage);
        setPasswdPushButton->setObjectName(QString::fromUtf8("setPasswdPushButton"));
        setPasswdPushButton->setGeometry(QRect(560, 95, 160, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(28);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        setPasswdPushButton->setFont(font2);
        setPasswdPushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        resetPushButton = new QPushButton(MenuPage);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setGeometry(QRect(560, 305, 160, 70));
        resetPushButton->setFont(font2);
        resetPushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        humiTablePushButton = new QPushButton(MenuPage);
        humiTablePushButton->setObjectName(QString::fromUtf8("humiTablePushButton"));
        humiTablePushButton->setGeometry(QRect(80, 200, 160, 70));
        humiTablePushButton->setFont(font2);
        humiTablePushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        remotePushButton = new QPushButton(MenuPage);
        remotePushButton->setObjectName(QString::fromUtf8("remotePushButton"));
        remotePushButton->setGeometry(QRect(80, 305, 160, 70));
        remotePushButton->setFont(font2);
        remotePushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        humiGraphPushButton = new QPushButton(MenuPage);
        humiGraphPushButton->setObjectName(QString::fromUtf8("humiGraphPushButton"));
        humiGraphPushButton->setGeometry(QRect(320, 200, 160, 70));
        humiGraphPushButton->setFont(font2);
        humiGraphPushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        setAlarmPushButton = new QPushButton(MenuPage);
        setAlarmPushButton->setObjectName(QString::fromUtf8("setAlarmPushButton"));
        setAlarmPushButton->setGeometry(QRect(560, 200, 160, 70));
        setAlarmPushButton->setFont(font2);
        setAlarmPushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        dateTimePushButton = new QPushButton(MenuPage);
        dateTimePushButton->setObjectName(QString::fromUtf8("dateTimePushButton"));
        dateTimePushButton->setGeometry(QRect(320, 305, 160, 70));
        dateTimePushButton->setFont(font2);
        dateTimePushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        tempGraphPushButton = new QPushButton(MenuPage);
        tempGraphPushButton->setObjectName(QString::fromUtf8("tempGraphPushButton"));
        tempGraphPushButton->setGeometry(QRect(320, 95, 160, 70));
        tempGraphPushButton->setFont(font2);
        tempGraphPushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        tempTablePushButton = new QPushButton(MenuPage);
        tempTablePushButton->setObjectName(QString::fromUtf8("tempTablePushButton"));
        tempTablePushButton->setGeometry(QRect(80, 95, 160, 70));
        tempTablePushButton->setFont(font2);
        tempTablePushButton->setStyleSheet(QString::fromUtf8("font: 28pt \"Ubuntu\";\n"
"color: rgb(51, 51, 51);\n"
"background-color: rgb(134, 182, 87);"));
        menuPushButton->raise();
        homePushButton->raise();
        label_3->raise();
        backPushButton->raise();
        label->raise();
        setPasswdPushButton->raise();
        resetPushButton->raise();
        humiTablePushButton->raise();
        remotePushButton->raise();
        humiGraphPushButton->raise();
        setAlarmPushButton->raise();
        dateTimePushButton->raise();
        tempGraphPushButton->raise();
        tempTablePushButton->raise();

        retranslateUi(MenuPage);

        QMetaObject::connectSlotsByName(MenuPage);
    } // setupUi

    void retranslateUi(QDialog *MenuPage)
    {
        MenuPage->setWindowTitle(QApplication::translate("MenuPage", "Dialog", 0, QApplication::UnicodeUTF8));
        backPushButton->setText(QApplication::translate("MenuPage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        homePushButton->setText(QString());
        menuPushButton->setText(QString());
        label_3->setText(QString());
        label->setText(QApplication::translate("MenuPage", "\346\270\251\346\271\277\345\272\246\347\233\221\346\216\247\346\212\245\350\255\246\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        setPasswdPushButton->setText(QApplication::translate("MenuPage", "\350\256\276\347\275\256\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        resetPushButton->setText(QApplication::translate("MenuPage", "\345\207\272\345\216\202\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        humiTablePushButton->setText(QApplication::translate("MenuPage", "\346\271\277\345\272\246\350\241\250", 0, QApplication::UnicodeUTF8));
        remotePushButton->setText(QApplication::translate("MenuPage", "\350\277\234\347\250\213", 0, QApplication::UnicodeUTF8));
        humiGraphPushButton->setText(QApplication::translate("MenuPage", "\346\271\277\345\272\246\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        setAlarmPushButton->setText(QApplication::translate("MenuPage", "\350\256\276\347\275\256\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        dateTimePushButton->setText(QApplication::translate("MenuPage", "\346\227\245\346\234\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        tempGraphPushButton->setText(QApplication::translate("MenuPage", "\346\270\251\345\272\246\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        tempTablePushButton->setText(QApplication::translate("MenuPage", "\346\270\251\345\272\246\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuPage: public Ui_MenuPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPAGE_H
