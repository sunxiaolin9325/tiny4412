/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QLabel *label;
    QLabel *headLabel;
    QPushButton *sendButton;
    QLabel *friendLabel;
    QTreeWidget *friendList;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTextEdit *chatTextEdit;
    QTextEdit *sendTextEdit;
    QPushButton *setupButton;
    QPushButton *addButton;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QStringLiteral("ChatPage"));
        ChatPage->resize(600, 500);
        label = new QLabel(ChatPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 70, 500));
        label->setStyleSheet(QStringLiteral("background-color: rgb(32, 225, 213);"));
        headLabel = new QLabel(ChatPage);
        headLabel->setObjectName(QStringLiteral("headLabel"));
        headLabel->setGeometry(QRect(0, 0, 70, 70));
        headLabel->setStyleSheet(QStringLiteral("background-color: rgb(191, 196, 51);"));
        sendButton = new QPushButton(ChatPage);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(530, 430, 70, 70));
        friendLabel = new QLabel(ChatPage);
        friendLabel->setObjectName(QStringLiteral("friendLabel"));
        friendLabel->setGeometry(QRect(220, 0, 380, 30));
        friendLabel->setStyleSheet(QStringLiteral("background-color: rgb(99, 170, 229);"));
        friendList = new QTreeWidget(ChatPage);
        QFont font;
        font.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        friendList->setHeaderItem(__qtreewidgetitem);
        friendList->setObjectName(QStringLiteral("friendList"));
        friendList->setGeometry(QRect(70, 0, 150, 500));
        QFont font1;
        font1.setPointSize(12);
        friendList->setFont(font1);
        friendList->setStyleSheet(QStringLiteral("background-color: rgb(144, 193, 221);"));
        friendList->setIconSize(QSize(20, 20));
        label_4 = new QLabel(ChatPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 390, 380, 40));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(29, 142, 243);"));
        pushButton = new QPushButton(ChatPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 390, 40, 40));
        pushButton_5 = new QPushButton(ChatPage);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 390, 40, 40));
        pushButton_6 = new QPushButton(ChatPage);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 390, 40, 40));
        pushButton_7 = new QPushButton(ChatPage);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(340, 390, 40, 40));
        chatTextEdit = new QTextEdit(ChatPage);
        chatTextEdit->setObjectName(QStringLiteral("chatTextEdit"));
        chatTextEdit->setGeometry(QRect(220, 30, 380, 360));
        QFont font2;
        font2.setPointSize(11);
        chatTextEdit->setFont(font2);
        chatTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(228, 234, 235);"));
        sendTextEdit = new QTextEdit(ChatPage);
        sendTextEdit->setObjectName(QStringLiteral("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(220, 430, 310, 70));
        setupButton = new QPushButton(ChatPage);
        setupButton->setObjectName(QStringLiteral("setupButton"));
        setupButton->setGeometry(QRect(0, 430, 70, 70));
        setupButton->setIconSize(QSize(70, 70));
        addButton = new QPushButton(ChatPage);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(0, 360, 70, 70));
        addButton->setIconSize(QSize(70, 70));
        lcdNumber = new QLCDNumber(ChatPage);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(230, 230, 341, 40));
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(64, 202, 32);"));
        lcdNumber->setLineWidth(0);
        lcdNumber->setDigitCount(17);
        lcdNumber->setProperty("value", QVariant(1.23457e+16));

        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QDialog *ChatPage)
    {
        ChatPage->setWindowTitle(QApplication::translate("ChatPage", "Dialog", 0));
        label->setText(QString());
        headLabel->setText(QString());
        sendButton->setText(QApplication::translate("ChatPage", "\345\217\221\351\200\201", 0));
        friendLabel->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = friendList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ChatPage", "\345\245\275\345\217\213\345\210\227\350\241\250", 0));
        label_4->setText(QString());
        pushButton->setText(QApplication::translate("ChatPage", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("ChatPage", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("ChatPage", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("ChatPage", "PushButton", 0));
        setupButton->setText(QString());
        addButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
