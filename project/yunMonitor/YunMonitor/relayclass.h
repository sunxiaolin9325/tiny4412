#ifndef RELAYCLASS_H
#define RELAYCLASS_H

#include <QObject>

extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
}

struct relay_pro_st {
    int no;
    int work;
};

class RelayClass : public QObject
{
    Q_OBJECT
public:
    explicit RelayClass(QObject *parent = 0);
    //提供方法
    int openRealy();
    int closeRelay();
    int writeRelay(relay_pro_st *pro);
    int ioctlRelay(relay_pro_st *pro);
    struct relay_pro_st pro;

signals:

public slots:

private:
    int relay;
};

#endif // RELAYCLASS_H
