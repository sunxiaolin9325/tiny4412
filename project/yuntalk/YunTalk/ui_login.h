/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *logoLabel;
    QLabel *headLabel;
    QLineEdit *countLineEdit;
    QLineEdit *PasswdLineEdit;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        logoLabel = new QLabel(Login);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(0, 0, 400, 160));
        logoLabel->setStyleSheet(QStringLiteral(""));
        headLabel = new QLabel(Login);
        headLabel->setObjectName(QStringLiteral("headLabel"));
        headLabel->setGeometry(QRect(30, 170, 90, 90));
        headLabel->setStyleSheet(QStringLiteral(""));
        countLineEdit = new QLineEdit(Login);
        countLineEdit->setObjectName(QStringLiteral("countLineEdit"));
        countLineEdit->setGeometry(QRect(130, 170, 180, 30));
        countLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        PasswdLineEdit = new QLineEdit(Login);
        PasswdLineEdit->setObjectName(QStringLiteral("PasswdLineEdit"));
        PasswdLineEdit->setGeometry(QRect(130, 200, 180, 30));
        PasswdLineEdit->setEchoMode(QLineEdit::Password);
        PasswdLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        checkBox = new QCheckBox(Login);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(130, 240, 90, 22));
        checkBox_2 = new QCheckBox(Login);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(220, 240, 90, 22));
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 170, 80, 30));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 200, 80, 30));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Login);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 265, 180, 30));
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(23, 84, 163);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        logoLabel->setText(QString());
        headLabel->setText(QString());
        countLineEdit->setText(QString());
        countLineEdit->setPlaceholderText(QApplication::translate("Login", "QQ\345\217\267\347\240\201/\346\211\213\346\234\272/\351\202\256\347\256\261", 0));
        PasswdLineEdit->setText(QString());
        PasswdLineEdit->setPlaceholderText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        checkBox->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        checkBox_2->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", 0));
        pushButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        pushButton_2->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", 0));
        pushButton_3->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
