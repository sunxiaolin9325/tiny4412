#ifndef SETUPPAGE_H
#define SETUPPAGE_H

#include <QDialog>

namespace Ui {
class SetupPage;
}

class SetupPage : public QDialog
{
    Q_OBJECT

public:
    explicit SetupPage(QWidget *parent = 0);
    ~SetupPage();

private:
    Ui::SetupPage *ui;
};

#endif // SETUPPAGE_H
