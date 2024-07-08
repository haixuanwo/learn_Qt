#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // 显示对象
    w.show();

    // 行循环执行QApplication对象实例
    return a.exec();
}
