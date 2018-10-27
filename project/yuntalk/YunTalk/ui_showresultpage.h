/********************************************************************************
** Form generated from reading UI file 'showresultpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRESULTPAGE_H
#define UI_SHOWRESULTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowResultPage
{
public:
    QLabel *showLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ShowResultPage)
    {
        if (ShowResultPage->objectName().isEmpty())
            ShowResultPage->setObjectName(QStringLiteral("ShowResultPage"));
        ShowResultPage->resize(200, 100);
        showLabel = new QLabel(ShowResultPage);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        showLabel->setGeometry(QRect(30, 10, 131, 31));
        showLabel->setAlignment(Qt::AlignCenter);
        okButton = new QPushButton(ShowResultPage);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(10, 50, 99, 27));
        cancelButton = new QPushButton(ShowResultPage);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(110, 50, 99, 27));

        retranslateUi(ShowResultPage);

        QMetaObject::connectSlotsByName(ShowResultPage);
    } // setupUi

    void retranslateUi(QDialog *ShowResultPage)
    {
        ShowResultPage->setWindowTitle(QApplication::translate("ShowResultPage", "Dialog", 0));
        showLabel->setText(QApplication::translate("ShowResultPage", "\346\230\276\347\244\272\346\226\207\346\234\254\344\277\241\346\201\257", 0));
        okButton->setText(QApplication::translate("ShowResultPage", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("ShowResultPage", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowResultPage: public Ui_ShowResultPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRESULTPAGE_H
