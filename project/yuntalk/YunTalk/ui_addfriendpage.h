/********************************************************************************
** Form generated from reading UI file 'addfriendpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDPAGE_H
#define UI_ADDFRIENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddFriendPage
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *AddFriendPage)
    {
        if (AddFriendPage->objectName().isEmpty())
            AddFriendPage->setObjectName(QStringLiteral("AddFriendPage"));
        AddFriendPage->resize(300, 200);
        lineEdit = new QLineEdit(AddFriendPage);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 201, 51));
        pushButton = new QPushButton(AddFriendPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(78, 100, 131, 41));

        retranslateUi(AddFriendPage);

        QMetaObject::connectSlotsByName(AddFriendPage);
    } // setupUi

    void retranslateUi(QDialog *AddFriendPage)
    {
        AddFriendPage->setWindowTitle(QApplication::translate("AddFriendPage", "Dialog", 0));
        lineEdit->setPlaceholderText(QApplication::translate("AddFriendPage", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
        pushButton->setText(QApplication::translate("AddFriendPage", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFriendPage: public Ui_AddFriendPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDPAGE_H
