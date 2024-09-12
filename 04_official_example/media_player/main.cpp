
#include "mainwindow.h"
#include <QApplication>
#include "serial.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<ProtocolCmd>("ProtocolCmd");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
