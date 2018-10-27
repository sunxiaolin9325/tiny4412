/********************************************************************************
** Form generated from reading UI file 'registerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterPage
{
public:
    QLineEdit *passwdLineEdit;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *countLineEdit;

    void setupUi(QDialog *RegisterPage)
    {
        if (RegisterPage->objectName().isEmpty())
            RegisterPage->setObjectName(QStringLiteral("RegisterPage"));
        RegisterPage->resize(300, 200);
        passwdLineEdit = new QLineEdit(RegisterPage);
        passwdLineEdit->setObjectName(QStringLiteral("passwdLineEdit"));
        passwdLineEdit->setGeometry(QRect(80, 80, 161, 27));
        pushButton = new QPushButton(RegisterPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 99, 27));
        radioButton = new QRadioButton(RegisterPage);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(80, 130, 117, 22));
        radioButton_2 = new QRadioButton(RegisterPage);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 130, 117, 22));
        countLineEdit = new QLineEdit(RegisterPage);
        countLineEdit->setObjectName(QStringLiteral("countLineEdit"));
        countLineEdit->setGeometry(QRect(80, 30, 171, 27));

        retranslateUi(RegisterPage);

        QMetaObject::connectSlotsByName(RegisterPage);
    } // setupUi

    void retranslateUi(QDialog *RegisterPage)
    {
        RegisterPage->setWindowTitle(QApplication::translate("RegisterPage", "Dialog", 0));
        passwdLineEdit->setPlaceholderText(QApplication::translate("RegisterPage", "\350\256\276\347\275\256\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("RegisterPage", "\346\263\250\345\206\214", 0));
        radioButton->setText(QApplication::translate("RegisterPage", "\347\224\267", 0));
        radioButton_2->setText(QApplication::translate("RegisterPage", "\345\245\263", 0));
        countLineEdit->setPlaceholderText(QApplication::translate("RegisterPage", "\350\257\267\350\276\223\345\205\245\346\203\263\346\263\250\345\206\214\347\232\204\350\264\246\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterPage: public Ui_RegisterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H
