#-------------------------------------------------
#
# Project created by QtCreator 2017-01-14T22:31:19
#
#-------------------------------------------------

#QT核心 图形界面 网络编程
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#目标
TARGET = YunTalk
TEMPLATE = app

#源文件
SOURCES += main.cpp\
        login.cpp \
    registerpage.cpp \
    showresultpage.cpp \
    chatpage.cpp \
    addfriendpage.cpp \
    setuppage.cpp

#头文件
HEADERS  += login.h \
    registerpage.h \
    showresultpage.h \
    chatpage.h \
    addfriendpage.h \
    setuppage.h \
    protocal.h

#ui文件
FORMS    += login.ui \
    registerpage.ui \
    showresultpage.ui \
    chatpage.ui \
    addfriendpage.ui \
    setuppage.ui


#添加头文件的位置
#INCLUDEPATH +=/usr/local/include/

#添加库的位置
#LIBS +=-L/usr/lib -lsqlite3

LIBS +=-lsqlite3

DISTFILES += \
    ../image/36f8dd2c91c77814c57822b487d7033d.jpg \
    ../image/42a028516e29e9c6187d600ca220bc54.jpg \
    ../image/72a4f2ceb6581a4be979054207174476.jpg \
    ../image/95f174a3e813a4ecb9756ce31bbb459a.jpg \
    ../image/96f8f0c9efc692d31ac3b78e4e9ee379.jpg \
    ../image/496c8bbd561bae2d79405be86ce2d378.jpg \
    ../image/749b9756c5129be117c3d8ae0c0bdbc3.jpg \
    ../image/939364c79bf60d407fb3134a89d885c4.jpg \
    ../image/add.jpg \
    ../image/aeb97b95302963efa9914898ddec7903.jpg \
    ../image/d2f6b4bd1a0f4bc265e0ee9ba2fdda69.jpg \
    ../image/d018cd6397c40152ff5952907e33ee7f (1).jpg \
    ../image/d46c77df7bf1a38333c19bada2fc277e.jpg \
    ../image/da8a8ed01d61b6be66d8ac7d2a678457.jpg \
    ../image/f15a0c4a54e47fadbef8ab3661bd6fd5.jpg \
    ../image/head.jpg \
    ../image/head1.jpg \
    ../image/head2.jpg \
    ../image/logo.jpg \
    ../image/logo1.jpg \
    ../image/setup.jpg


