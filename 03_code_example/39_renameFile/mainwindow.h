#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
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
    QLineEdit *filePath;
    QLineEdit *newName;
    QPushButton *browseBt;
    QPushButton *saveBt;

private slots:
    void browseFile();
    void saveFile();
};

#endif // MAINWINDOW_H
