#include "login.h"
#include <QApplication>

//整个程序运行起来就是一个进程,进程中只有一个main(ui)线程
//目前该线程不能阻塞处理事件
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //定义一个对象,同时调用了构造方法
    Login w;
    //对象继承了父类方法,可以调用,带界面的对象都能show
    w.show();

    //同一个类用同一个构造方法构造出两个一模一样的对象
    //Login m;
    //m.show();

    return a.exec();
}


//类中的语句不会被执行,只有通过new出一个对象,实例化以后
//从构造方法开始执行

//类的声明定义都在头文件中,类:方法+属性
//方法的声明在类中,方法的实现在cpp文件中
//方法:构造方法+普通方法
    //构造方法:new创建对象时调用
//属性和方法:private+public+...
    //私有:只能在类中使用
    //公有:对象可以使用

//一般方法声明为public,属性为private,对象可以通
//过public方法使用private属性.
