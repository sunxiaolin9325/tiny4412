/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created: Sun May 14 19:24:23 2017
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QLabel *dStateLabel;
    QLabel *label_31;
    QLabel *label_3;
    QLabel *fTemperatureLabel;
    QLabel *bHumidityLabel;
    QLabel *cStateLabel;
    QLabel *label;
    QLabel *eTemperatureLabel;
    QLabel *eStateLabel;
    QLabel *bStateLabel;
    QLabel *cHumidityLabel;
    QLabel *label_10;
    QLabel *label_16;
    QLabel *dTemperatureLabel;
    QLabel *fHumidityLabel;
    QPushButton *menuPushButton;
    QPushButton *resetPushButton;
    QLabel *label_9;
    QPushButton *quitPushButton;
    QLabel *label_17;
    QLabel *aTemperatureLabel;
    QLabel *aStateLabel;
    QLabel *fStateLabel;
    QLabel *label_6;
    QLabel *eHumidityLabel;
    QLabel *dHumidityLabel;
    QLabel *aHumidityLabel;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *bTemperatureLabel;
    QLabel *cTemperatureLabel;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QString::fromUtf8("HomePage"));
        HomePage->resize(800, 480);
        HomePage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dStateLabel = new QLabel(HomePage);
        dStateLabel->setObjectName(QString::fromUtf8("dStateLabel"));
        dStateLabel->setGeometry(QRect(600, 260, 200, 50));
        QFont font;
        font.setPointSize(20);
        dStateLabel->setFont(font);
        dStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(255, 0, 0);\n"
"color: rgb(124, 177, 74);"));
        dStateLabel->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(HomePage);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(600, 60, 200, 50));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_31->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(HomePage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 410, 800, 70));
        QFont font1;
        font1.setPointSize(30);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(211, 219, 43);\n"
"background-color: rgb(27, 27, 27);"));
        label_3->setAlignment(Qt::AlignCenter);
        fTemperatureLabel = new QLabel(HomePage);
        fTemperatureLabel->setObjectName(QString::fromUtf8("fTemperatureLabel"));
        fTemperatureLabel->setGeometry(QRect(200, 360, 200, 50));
        fTemperatureLabel->setFont(font);
        fTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        fTemperatureLabel->setAlignment(Qt::AlignCenter);
        bHumidityLabel = new QLabel(HomePage);
        bHumidityLabel->setObjectName(QString::fromUtf8("bHumidityLabel"));
        bHumidityLabel->setGeometry(QRect(400, 160, 200, 50));
        bHumidityLabel->setFont(font);
        bHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        bHumidityLabel->setAlignment(Qt::AlignCenter);
        cStateLabel = new QLabel(HomePage);
        cStateLabel->setObjectName(QString::fromUtf8("cStateLabel"));
        cStateLabel->setGeometry(QRect(600, 210, 200, 50));
        cStateLabel->setFont(font);
        cStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(230, 127, 118);\n"
"color: rgb(124, 177, 74);"));
        cStateLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(HomePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 60));
        QFont font2;
        font2.setPointSize(32);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
"color: rgb(230, 127, 118);"));
        label->setAlignment(Qt::AlignCenter);
        eTemperatureLabel = new QLabel(HomePage);
        eTemperatureLabel->setObjectName(QString::fromUtf8("eTemperatureLabel"));
        eTemperatureLabel->setGeometry(QRect(200, 310, 200, 50));
        eTemperatureLabel->setFont(font);
        eTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        eTemperatureLabel->setAlignment(Qt::AlignCenter);
        eStateLabel = new QLabel(HomePage);
        eStateLabel->setObjectName(QString::fromUtf8("eStateLabel"));
        eStateLabel->setGeometry(QRect(600, 310, 200, 50));
        eStateLabel->setFont(font);
        eStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(0, 255, 0);\n"
"color: rgb(124, 177, 74);"));
        eStateLabel->setAlignment(Qt::AlignCenter);
        bStateLabel = new QLabel(HomePage);
        bStateLabel->setObjectName(QString::fromUtf8("bStateLabel"));
        bStateLabel->setGeometry(QRect(600, 160, 200, 50));
        bStateLabel->setFont(font);
        bStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(255, 206, 68);\n"
"color: rgb(124, 177, 74);"));
        bStateLabel->setAlignment(Qt::AlignCenter);
        cHumidityLabel = new QLabel(HomePage);
        cHumidityLabel->setObjectName(QString::fromUtf8("cHumidityLabel"));
        cHumidityLabel->setGeometry(QRect(400, 210, 200, 50));
        cHumidityLabel->setFont(font);
        cHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        cHumidityLabel->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(HomePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 210, 200, 50));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(HomePage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 310, 200, 50));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_16->setAlignment(Qt::AlignCenter);
        dTemperatureLabel = new QLabel(HomePage);
        dTemperatureLabel->setObjectName(QString::fromUtf8("dTemperatureLabel"));
        dTemperatureLabel->setGeometry(QRect(200, 260, 200, 50));
        dTemperatureLabel->setFont(font);
        dTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        dTemperatureLabel->setAlignment(Qt::AlignCenter);
        fHumidityLabel = new QLabel(HomePage);
        fHumidityLabel->setObjectName(QString::fromUtf8("fHumidityLabel"));
        fHumidityLabel->setGeometry(QRect(400, 360, 200, 50));
        fHumidityLabel->setFont(font);
        fHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        fHumidityLabel->setAlignment(Qt::AlignCenter);
        menuPushButton = new QPushButton(HomePage);
        menuPushButton->setObjectName(QString::fromUtf8("menuPushButton"));
        menuPushButton->setGeometry(QRect(640, 410, 160, 70));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(32);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        menuPushButton->setFont(font3);
        menuPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        resetPushButton = new QPushButton(HomePage);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setGeometry(QRect(0, 410, 160, 70));
        resetPushButton->setFont(font3);
        resetPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(HomePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 160, 200, 50));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_9->setAlignment(Qt::AlignCenter);
        quitPushButton = new QPushButton(HomePage);
        quitPushButton->setObjectName(QString::fromUtf8("quitPushButton"));
        quitPushButton->setGeometry(QRect(0, 410, 160, 70));
        quitPushButton->setFont(font3);
        quitPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(77, 140, 245);\n"
"font: 32pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        label_17 = new QLabel(HomePage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 360, 200, 50));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_17->setAlignment(Qt::AlignCenter);
        aTemperatureLabel = new QLabel(HomePage);
        aTemperatureLabel->setObjectName(QString::fromUtf8("aTemperatureLabel"));
        aTemperatureLabel->setGeometry(QRect(200, 110, 200, 50));
        aTemperatureLabel->setFont(font);
        aTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        aTemperatureLabel->setAlignment(Qt::AlignCenter);
        aStateLabel = new QLabel(HomePage);
        aStateLabel->setObjectName(QString::fromUtf8("aStateLabel"));
        aStateLabel->setGeometry(QRect(600, 110, 200, 50));
        aStateLabel->setFont(font);
        aStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(26, 162, 96);\n"
"color: rgb(124, 177, 74);"));
        aStateLabel->setAlignment(Qt::AlignCenter);
        fStateLabel = new QLabel(HomePage);
        fStateLabel->setObjectName(QString::fromUtf8("fStateLabel"));
        fStateLabel->setGeometry(QRect(600, 360, 200, 50));
        fStateLabel->setFont(font);
        fStateLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"background-color: rgb(255, 255, 0);\n"
"color: rgb(124, 177, 74);"));
        fStateLabel->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(HomePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 60, 200, 50));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_6->setAlignment(Qt::AlignCenter);
        eHumidityLabel = new QLabel(HomePage);
        eHumidityLabel->setObjectName(QString::fromUtf8("eHumidityLabel"));
        eHumidityLabel->setGeometry(QRect(400, 310, 200, 50));
        eHumidityLabel->setFont(font);
        eHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        eHumidityLabel->setAlignment(Qt::AlignCenter);
        dHumidityLabel = new QLabel(HomePage);
        dHumidityLabel->setObjectName(QString::fromUtf8("dHumidityLabel"));
        dHumidityLabel->setGeometry(QRect(400, 260, 200, 50));
        dHumidityLabel->setFont(font);
        dHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        dHumidityLabel->setAlignment(Qt::AlignCenter);
        aHumidityLabel = new QLabel(HomePage);
        aHumidityLabel->setObjectName(QString::fromUtf8("aHumidityLabel"));
        aHumidityLabel->setGeometry(QRect(400, 110, 200, 50));
        aHumidityLabel->setFont(font);
        aHumidityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        aHumidityLabel->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(HomePage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, 260, 200, 50));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_15->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(HomePage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(400, 60, 200, 50));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_11->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(HomePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 60, 200, 50));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(251, 203, 67);\n"
"background-color: rgb(79, 102, 102);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(HomePage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 110, 200, 50));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"color: rgb(23, 106, 171);"));
        label_8->setAlignment(Qt::AlignCenter);
        bTemperatureLabel = new QLabel(HomePage);
        bTemperatureLabel->setObjectName(QString::fromUtf8("bTemperatureLabel"));
        bTemperatureLabel->setGeometry(QRect(200, 160, 200, 50));
        bTemperatureLabel->setFont(font);
        bTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        bTemperatureLabel->setAlignment(Qt::AlignCenter);
        cTemperatureLabel = new QLabel(HomePage);
        cTemperatureLabel->setObjectName(QString::fromUtf8("cTemperatureLabel"));
        cTemperatureLabel->setGeometry(QRect(200, 210, 200, 50));
        cTemperatureLabel->setFont(font);
        cTemperatureLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(113, 170, 61);"));
        cTemperatureLabel->setAlignment(Qt::AlignCenter);
        quitPushButton->raise();
        dStateLabel->raise();
        label_31->raise();
        label_3->raise();
        fTemperatureLabel->raise();
        bHumidityLabel->raise();
        cStateLabel->raise();
        label->raise();
        eTemperatureLabel->raise();
        eStateLabel->raise();
        bStateLabel->raise();
        cHumidityLabel->raise();
        label_10->raise();
        label_16->raise();
        dTemperatureLabel->raise();
        fHumidityLabel->raise();
        menuPushButton->raise();
        resetPushButton->raise();
        label_9->raise();
        label_17->raise();
        aTemperatureLabel->raise();
        aStateLabel->raise();
        fStateLabel->raise();
        label_6->raise();
        eHumidityLabel->raise();
        dHumidityLabel->raise();
        aHumidityLabel->raise();
        label_15->raise();
        label_11->raise();
        label_5->raise();
        label_8->raise();
        bTemperatureLabel->raise();
        cTemperatureLabel->raise();

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "HomePage", 0, QApplication::UnicodeUTF8));
        dStateLabel->setText(QString());
        label_31->setText(QApplication::translate("HomePage", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        fTemperatureLabel->setText(QString());
        bHumidityLabel->setText(QString());
        cStateLabel->setText(QString());
        label->setText(QApplication::translate("HomePage", "\346\270\251\346\271\277\345\272\246\347\233\221\346\216\247\346\212\245\350\255\246\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        eTemperatureLabel->setText(QString());
        eStateLabel->setText(QString());
        bStateLabel->setText(QString());
        cHumidityLabel->setText(QString());
        label_10->setText(QApplication::translate("HomePage", "C\345\214\272", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("HomePage", "E\345\214\272", 0, QApplication::UnicodeUTF8));
        dTemperatureLabel->setText(QString());
        fHumidityLabel->setText(QString());
        menuPushButton->setText(QApplication::translate("HomePage", "\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        resetPushButton->setText(QApplication::translate("HomePage", "\345\244\215\344\275\215", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HomePage", "B\345\214\272", 0, QApplication::UnicodeUTF8));
        quitPushButton->setText(QApplication::translate("HomePage", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HomePage", "F\345\214\272", 0, QApplication::UnicodeUTF8));
        aTemperatureLabel->setText(QString());
        aStateLabel->setText(QString());
        fStateLabel->setText(QString());
        label_6->setText(QApplication::translate("HomePage", "\346\270\251\345\272\246/\342\204\203", 0, QApplication::UnicodeUTF8));
        eHumidityLabel->setText(QString());
        dHumidityLabel->setText(QString());
        aHumidityLabel->setText(QString());
        label_15->setText(QApplication::translate("HomePage", "D\345\214\272", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HomePage", "\346\271\277\345\272\246/%RH", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HomePage", "\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HomePage", "A\345\214\272", 0, QApplication::UnicodeUTF8));
        bTemperatureLabel->setText(QString());
        cTemperatureLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
