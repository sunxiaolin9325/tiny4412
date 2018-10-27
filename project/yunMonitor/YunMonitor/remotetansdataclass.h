#ifndef REMOTETANSDATACLASS_H
#define REMOTETANSDATACLASS_H

#include <QObject>

#include "nrf24l01class.h"

class RemoteTansDataClass : public QObject
{
    Q_OBJECT
public:
    explicit RemoteTansDataClass(QObject *parent = 0);
    //
    void sendNrf24l01Data(struct nrf24l01_pro_st *pro);
signals:
    //
    void remoteDataReady(struct nrf24l01_pro_st *pro);

public slots:
};

#endif // REMOTETANSDATACLASS_H
