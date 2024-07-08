#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *label;
    QImage *img;
    QPushButton *hBt;
    QPushButton *vBt;
    QPushButton *angleBt;

private slots:
    void hShow();
    void vShow();
    void angleShow();
};

#endif // MAINWINDOW_H
