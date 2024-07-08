#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>  // 引用鼠标类头文件
#include <QPushButton>  // 引用按钮类头文件

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // 鼠标按下
    void mousePressEvent(QMouseEvent *e);

    // 鼠标移动
    void mouseMoveEvent(QMouseEvent *e);

    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QPushButton *btClose;
    QPoint last;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
