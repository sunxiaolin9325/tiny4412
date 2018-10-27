#-------------------------------------------------
#
# Project created by QtCreator 2017-01-19T23:41:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YunMonitor
TEMPLATE = app


SOURCES += main.cpp\
        homepage.cpp \
    menupage.cpp \
    transdataclass.cpp \
    mythread.cpp \
    dht22Class.cpp \
    relayclass.cpp \
    remotepage.cpp \
    nrf24l01class.cpp \
    remotetansdataclass.cpp \
    remotethread.cpp

HEADERS  += homepage.h \
    menupage.h \
    transdataclass.h \
    mythread.h \
    dht22class.h \
    relayclass.h \
    remotepage.h \
    nrf24l01class.h \
    remotetansdataclass.h \
    remotethread.h

FORMS    += homepage.ui \
    menupage.ui \
    remotepage.ui

#yun armqmake,链接arm平台用的qt,sqlite3,ts库
INCLUDEPATH +=/home/lin/object/qt/sqlite/include
LIBS +=-L/home/lin/object/qt/sqlite/lib -lsqlite3

#LIBS +=-lsqlite3
