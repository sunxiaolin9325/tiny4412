/********************************************************************************
** Form generated from reading UI file 'remotepage.ui'
**
** Created: Sun May 14 19:24:23 2017
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTEPAGE_H
#define UI_REMOTEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RemotePage
{
public:
    QLabel *dHumidityLabel;
    QLabel *label_10;
    QPushButton *menuPushButton;
    QLabel *eHumidityLabel;
    QLabel *label_6;
    QPushButton *resetPushButton;
    QLabel *label_5;
    QPushButton *backPushButton;
    QLabel *aPm25Label;
    QLabel *label_9;
    QLabel *aTemperatureLabel;
    QLabel *dTemperatureLabel;
    QLabel *cTemperatureLabel;
    QLabel *eTemperatureLabel;
    QLabel *bPm25Label;
    QLabel *label_15;
    QLabel *ePm25Label;
    QLabel *fHumidityLabel;
    QLabel *fPm25Label;
    QLabel *label_31;
    QLabel *label;
    QLabel *label_17;
    QLabel *bTemperatureLabel;
    QLabel *fTemperatureLabel;
    QLabel *label_3;
    QLabel *cHumidityLabel;
    QLabel *label_11;
    QLabel *aHumidityLabel;
    QLabel *dPm25Label;
    QLabel *bHumidityLabel;
    QLabel *cPm25Label;
    QLabel *label_16;
    QLabel *label_8;

    void setupUi(QDialog *RemotePage)
    {
        if (RemotePage->objectName().isEmpty())
            RemotePage->setObjectName(QString::fromUtf8("RemotePage"));
        RemotePage->resize(800, 480);
        RemotePage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dHumidityLabel = new QLabel(RemotePage);
        dHumidityLabel->setObjectName(QString::fromUtf8("dHumidityLabel"));
        dHumidityLabel->setGeometry(QRect(400, 260, 200, 50));
        QFont font;
        font.setPointSize(20);
        dHumidityLabel->setFont(font);
        dHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        dHumidityLabel->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(RemotePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 210, 200, 50));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_10->setAlignment(Qt::AlignCenter);
        menuPushButton = new QPushButton(RemotePage);
        menuPushButton->setObjectName(QString::fromUtf8("menuPushButton"));
        menuPushButton->setGeometry(QRect(640, 410, 160, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        menuPushButton->setFont(font1);
        menuPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        eHumidityLabel = new QLabel(RemotePage);
        eHumidityLabel->setObjectName(QString::fromUtf8("eHumidityLabel"));
        eHumidityLabel->setGeometry(QRect(400, 310, 200, 50));
        eHumidityLabel->setFont(font);
        eHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        eHumidityLabel->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(RemotePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 60, 200, 50));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_6->setAlignment(Qt::AlignCenter);
        resetPushButton = new QPushButton(RemotePage);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setGeometry(QRect(320, 410, 160, 70));
        resetPushButton->setFont(font1);
        resetPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(RemotePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 60, 200, 50));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_5->setAlignment(Qt::AlignCenter);
        backPushButton = new QPushButton(RemotePage);
        backPushButton->setObjectName(QString::fromUtf8("backPushButton"));
        backPushButton->setGeometry(QRect(0, 410, 160, 70));
        backPushButton->setFont(font1);
        backPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        aPm25Label = new QLabel(RemotePage);
        aPm25Label->setObjectName(QString::fromUtf8("aPm25Label"));
        aPm25Label->setGeometry(QRect(600, 110, 200, 50));
        aPm25Label->setFont(font);
        aPm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        aPm25Label->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(RemotePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 160, 200, 50));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_9->setAlignment(Qt::AlignCenter);
        aTemperatureLabel = new QLabel(RemotePage);
        aTemperatureLabel->setObjectName(QString::fromUtf8("aTemperatureLabel"));
        aTemperatureLabel->setGeometry(QRect(200, 110, 200, 50));
        aTemperatureLabel->setFont(font);
        aTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        aTemperatureLabel->setAlignment(Qt::AlignCenter);
        dTemperatureLabel = new QLabel(RemotePage);
        dTemperatureLabel->setObjectName(QString::fromUtf8("dTemperatureLabel"));
        dTemperatureLabel->setGeometry(QRect(200, 260, 200, 50));
        dTemperatureLabel->setFont(font);
        dTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        dTemperatureLabel->setAlignment(Qt::AlignCenter);
        cTemperatureLabel = new QLabel(RemotePage);
        cTemperatureLabel->setObjectName(QString::fromUtf8("cTemperatureLabel"));
        cTemperatureLabel->setGeometry(QRect(200, 210, 200, 50));
        cTemperatureLabel->setFont(font);
        cTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        cTemperatureLabel->setAlignment(Qt::AlignCenter);
        eTemperatureLabel = new QLabel(RemotePage);
        eTemperatureLabel->setObjectName(QString::fromUtf8("eTemperatureLabel"));
        eTemperatureLabel->setGeometry(QRect(200, 310, 200, 50));
        eTemperatureLabel->setFont(font);
        eTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        eTemperatureLabel->setAlignment(Qt::AlignCenter);
        bPm25Label = new QLabel(RemotePage);
        bPm25Label->setObjectName(QString::fromUtf8("bPm25Label"));
        bPm25Label->setGeometry(QRect(600, 160, 200, 50));
        bPm25Label->setFont(font);
        bPm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        bPm25Label->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(RemotePage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, 260, 200, 50));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_15->setAlignment(Qt::AlignCenter);
        ePm25Label = new QLabel(RemotePage);
        ePm25Label->setObjectName(QString::fromUtf8("ePm25Label"));
        ePm25Label->setGeometry(QRect(600, 310, 200, 50));
        ePm25Label->setFont(font);
        ePm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        ePm25Label->setAlignment(Qt::AlignCenter);
        fHumidityLabel = new QLabel(RemotePage);
        fHumidityLabel->setObjectName(QString::fromUtf8("fHumidityLabel"));
        fHumidityLabel->setGeometry(QRect(400, 360, 200, 50));
        fHumidityLabel->setFont(font);
        fHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        fHumidityLabel->setAlignment(Qt::AlignCenter);
        fPm25Label = new QLabel(RemotePage);
        fPm25Label->setObjectName(QString::fromUtf8("fPm25Label"));
        fPm25Label->setGeometry(QRect(600, 360, 200, 50));
        fPm25Label->setFont(font);
        fPm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        fPm25Label->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(RemotePage);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(600, 60, 200, 50));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_31->setAlignment(Qt::AlignCenter);
        label = new QLabel(RemotePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 60));
        QFont font2;
        font2.setPointSize(32);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
"color: rgb(230, 127, 118);"));
        label->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(RemotePage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 360, 200, 50));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_17->setAlignment(Qt::AlignCenter);
        bTemperatureLabel = new QLabel(RemotePage);
        bTemperatureLabel->setObjectName(QString::fromUtf8("bTemperatureLabel"));
        bTemperatureLabel->setGeometry(QRect(200, 160, 200, 50));
        bTemperatureLabel->setFont(font);
        bTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        bTemperatureLabel->setAlignment(Qt::AlignCenter);
        fTemperatureLabel = new QLabel(RemotePage);
        fTemperatureLabel->setObjectName(QString::fromUtf8("fTemperatureLabel"));
        fTemperatureLabel->setGeometry(QRect(200, 360, 200, 50));
        fTemperatureLabel->setFont(font);
        fTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        fTemperatureLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(RemotePage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 410, 800, 70));
        QFont font3;
        font3.setPointSize(30);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(211, 219, 43);\n"
"background-color: rgb(27, 27, 27);"));
        label_3->setAlignment(Qt::AlignCenter);
        cHumidityLabel = new QLabel(RemotePage);
        cHumidityLabel->setObjectName(QString::fromUtf8("cHumidityLabel"));
        cHumidityLabel->setGeometry(QRect(400, 210, 200, 50));
        cHumidityLabel->setFont(font);
        cHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        cHumidityLabel->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(RemotePage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(400, 60, 200, 50));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_11->setAlignment(Qt::AlignCenter);
        aHumidityLabel = new QLabel(RemotePage);
        aHumidityLabel->setObjectName(QString::fromUtf8("aHumidityLabel"));
        aHumidityLabel->setGeometry(QRect(400, 110, 200, 50));
        aHumidityLabel->setFont(font);
        aHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        aHumidityLabel->setAlignment(Qt::AlignCenter);
        dPm25Label = new QLabel(RemotePage);
        dPm25Label->setObjectName(QString::fromUtf8("dPm25Label"));
        dPm25Label->setGeometry(QRect(600, 260, 200, 50));
        dPm25Label->setFont(font);
        dPm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        dPm25Label->setAlignment(Qt::AlignCenter);
        bHumidityLabel = new QLabel(RemotePage);
        bHumidityLabel->setObjectName(QString::fromUtf8("bHumidityLabel"));
        bHumidityLabel->setGeometry(QRect(400, 160, 200, 50));
        bHumidityLabel->setFont(font);
        bHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        bHumidityLabel->setAlignment(Qt::AlignCenter);
        cPm25Label = new QLabel(RemotePage);
        cPm25Label->setObjectName(QString::fromUtf8("cPm25Label"));
        cPm25Label->setGeometry(QRect(600, 210, 200, 50));
        cPm25Label->setFont(font);
        cPm25Label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        cPm25Label->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(RemotePage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 310, 200, 50));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_16->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(RemotePage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 110, 200, 50));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_8->setAlignment(Qt::AlignCenter);
        menuPushButton->raise();
        resetPushButton->raise();
        label_3->raise();
        dHumidityLabel->raise();
        label_10->raise();
        eHumidityLabel->raise();
        label_6->raise();
        label_5->raise();
        backPushButton->raise();
        aPm25Label->raise();
        label_9->raise();
        aTemperatureLabel->raise();
        dTemperatureLabel->raise();
        cTemperatureLabel->raise();
        eTemperatureLabel->raise();
        bPm25Label->raise();
        label_15->raise();
        ePm25Label->raise();
        fHumidityLabel->raise();
        fPm25Label->raise();
        label_31->raise();
        label->raise();
        label_17->raise();
        bTemperatureLabel->raise();
        fTemperatureLabel->raise();
        cHumidityLabel->raise();
        label_11->raise();
        aHumidityLabel->raise();
        dPm25Label->raise();
        bHumidityLabel->raise();
        cPm25Label->raise();
        label_16->raise();
        label_8->raise();

        retranslateUi(RemotePage);

        QMetaObject::connectSlotsByName(RemotePage);
    } // setupUi

    void retranslateUi(QDialog *RemotePage)
    {
        RemotePage->setWindowTitle(QApplication::translate("RemotePage", "Dialog", 0, QApplication::UnicodeUTF8));
        dHumidityLabel->setText(QString());
        label_10->setText(QApplication::translate("RemotePage", "C\345\214\272", 0, QApplication::UnicodeUTF8));
        menuPushButton->setText(QString());
        eHumidityLabel->setText(QString());
        label_6->setText(QApplication::translate("RemotePage", "\346\270\251\345\272\246/\342\204\203", 0, QApplication::UnicodeUTF8));
        resetPushButton->setText(QString());
        label_5->setText(QApplication::translate("RemotePage", "\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        backPushButton->setText(QApplication::translate("RemotePage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        aPm25Label->setText(QString());
        label_9->setText(QApplication::translate("RemotePage", "B\345\214\272", 0, QApplication::UnicodeUTF8));
        aTemperatureLabel->setText(QString());
        dTemperatureLabel->setText(QString());
        cTemperatureLabel->setText(QString());
        eTemperatureLabel->setText(QString());
        bPm25Label->setText(QString());
        label_15->setText(QApplication::translate("RemotePage", "D\345\214\272", 0, QApplication::UnicodeUTF8));
        ePm25Label->setText(QString());
        fHumidityLabel->setText(QString());
        fPm25Label->setText(QString());
        label_31->setText(QApplication::translate("RemotePage", "PM2.5/\316\274g/m\302\263", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RemotePage", "\346\270\251\346\271\277\345\272\246\347\233\221\346\216\247\346\212\245\350\255\246\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("RemotePage", "F\345\214\272", 0, QApplication::UnicodeUTF8));
        bTemperatureLabel->setText(QString());
        fTemperatureLabel->setText(QString());
        label_3->setText(QString());
        cHumidityLabel->setText(QString());
        label_11->setText(QApplication::translate("RemotePage", "\346\271\277\345\272\246/%RH", 0, QApplication::UnicodeUTF8));
        aHumidityLabel->setText(QString());
        dPm25Label->setText(QString());
        bHumidityLabel->setText(QString());
        cPm25Label->setText(QString());
        label_16->setText(QApplication::translate("RemotePage", "E\345\214\272", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RemotePage", "A\345\214\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RemotePage: public Ui_RemotePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEPAGE_H
