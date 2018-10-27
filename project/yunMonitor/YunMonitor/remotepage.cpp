#include "remotepage.h"
#include "ui_remotepage.h"

RemotePage::RemotePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemotePage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

RemotePage::~RemotePage()
{
    delete ui;
}

void RemotePage::on_backPushButton_clicked()
{
    close();
}

void RemotePage::setATemperatureLabel(QString text)
{
    ui->aTemperatureLabel->setText(text);
}

void RemotePage::setAHumidityLabel(QString text)
{
    ui->aHumidityLabel->setText(text);
}

void RemotePage::setAPm25Label(QString text)
{
    ui->aPm25Label->setText(text);
}

void RemotePage::setBTemperatureLabel(QString text)
{
    ui->bTemperatureLabel->setText(text);
}

void RemotePage::setBHumidityLabel(QString text)
{
    ui->bHumidityLabel->setText(text);
}

void RemotePage::setBPm25Label(QString text)
{
    ui->bPm25Label->setText(text);
}

void RemotePage::setCTemperatureLabel(QString text)
{
    ui->cTemperatureLabel->setText(text);
}

void RemotePage::setCHumidityLabel(QString text)
{
    ui->cHumidityLabel->setText(text);
}

void RemotePage::setCPm25Label(QString text)
{
    ui->cPm25Label->setText(text);
}






