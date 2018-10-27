/********************************************************************************
** Form generated from reading UI file 'setuppage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPPAGE_H
#define UI_SETUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetupPage
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SetupPage)
    {
        if (SetupPage->objectName().isEmpty())
            SetupPage->setObjectName(QStringLiteral("SetupPage"));
        SetupPage->resize(300, 200);
        lineEdit = new QLineEdit(SetupPage);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 50, 261, 41));
        lineEdit_2 = new QLineEdit(SetupPage);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 90, 261, 41));
        pushButton = new QPushButton(SetupPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 99, 41));

        retranslateUi(SetupPage);

        QMetaObject::connectSlotsByName(SetupPage);
    } // setupUi

    void retranslateUi(QDialog *SetupPage)
    {
        SetupPage->setWindowTitle(QApplication::translate("SetupPage", "Dialog", 0));
        lineEdit->setPlaceholderText(QApplication::translate("SetupPage", "\350\257\267\350\276\223\345\205\245\351\227\256\351\242\230", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("SetupPage", "\350\257\267\350\276\223\345\205\245\347\255\224\346\241\210", 0));
        pushButton->setText(QApplication::translate("SetupPage", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class SetupPage: public Ui_SetupPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPPAGE_H
