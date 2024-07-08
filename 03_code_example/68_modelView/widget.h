#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>

typedef enum{
    STUDENT_NUMMBER,
    STUDENT_NAME,
    STUDENT_AGE,
    STUDENT_SCORE
}StudentElement_e;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonConfirm_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonSort_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};
#endif // WIDGET_H
