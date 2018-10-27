#include "homepage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOverrideCursor(Qt::BlankCursor);
    //字体库
    //选定一个字体族
    //ui界面也设置了字体
    //如果字体库中没有上面两种字体就会使用默认字体
    QFont font;
    //font.setPointSize(160);//实际上是16的字号，但设成16却不行
    font.setFamily(("WenQuanYi Zen Hei"));
    //font.setFamily(("wenquanyi"));
    //font.setBold(false);

    a.setFont(font);

    HomePage w;
    w.show();

    return a.exec();
}


//界面是非线程安全的,不能多个线程设置ui,由主线程来设置.
//采集数据的对象和主线程对象通信,通过中间对象,这个对象具有按钮
//信号与槽的参数类型必须一致

//主界面起来后,创建一个读线程,读线程用adcclass类中的方法,读取
///dev/adc/文件的数据,读到数据就用transdataclass中的方法
//向主界面发出dataready信号,主界面将该信号绑定了自readdatahandler
//槽函数,槽函数讲数据显示到主界面的控件上.

//      new--->             adcclass方法-->读
//主界面---------------读线程------------------/dev/adc
//     发信号<---trans方法       <---读到数据返回

//transdataclass类的作用就是有一个方法可以发信号,信号带参数
//ReadDataThread线程保存TransDataClass对象的引用,收到数据后
//讲数据发给该引用绑定的槽函数.-------------------


//Qt下子线程从run函数开始执行，Qt线程类对象的声明并非执行在子线程中，而是在主线程中


//绑定信号与槽:首先一个类里有信号,new出一个对象,将








