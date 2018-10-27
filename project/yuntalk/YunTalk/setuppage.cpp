#include "setuppage.h"
#include "ui_setuppage.h"

SetupPage::SetupPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupPage)
{
    ui->setupUi(this);
}

SetupPage::~SetupPage()
{
    delete ui;
}
