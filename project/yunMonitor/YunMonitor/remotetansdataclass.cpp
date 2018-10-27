#include "remotetansdataclass.h"

RemoteTansDataClass::RemoteTansDataClass(QObject *parent) : QObject(parent)
{

}

void RemoteTansDataClass::sendNrf24l01Data(struct nrf24l01_pro_st *pro)
{
    emit remoteDataReady(pro);
}
