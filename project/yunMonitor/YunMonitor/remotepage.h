#ifndef REMOTEPAGE_H
#define REMOTEPAGE_H

#include <QDialog>

namespace Ui {
class RemotePage;
}

class RemotePage : public QDialog
{
    Q_OBJECT

public:
    explicit RemotePage(QWidget *parent = 0);
    ~RemotePage();

    void setATemperatureLabel(QString text);
    void setAHumidityLabel(QString text);
    void setAPm25Label(QString text);
    void setBTemperatureLabel(QString text);
    void setBHumidityLabel(QString text);
    void setBPm25Label(QString text);
    void setCTemperatureLabel(QString text);
    void setCHumidityLabel(QString text);
    void setCPm25Label(QString text);

private slots:
    void on_backPushButton_clicked();

private:
    Ui::RemotePage *ui;
};

#endif // REMOTEPAGE_H
