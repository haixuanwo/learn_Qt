#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("fuckn你ma");

    /*
        a指定b为它的父对象，a放在b上面
        （1）setParent
        （2）通过构造函数传参
        只需父对象显示，子对象自动显示
    */

    QPushButton b;
    b.setText("wo干");
    b.setParent(&w);

    QPushButton b1(&w);
    b1.setText("从天干");
    b1.move(200, 200);

    w.show();

    app.exec();

    return 0;
}
