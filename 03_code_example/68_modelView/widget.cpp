#include "widget.h"
#include "ui_widget.h"
#if 1
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#endif

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 1
    // 打印支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    // 添加Sqlite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // 连接数据库
    //    db.setHostName("127.0.0.1") // 数据库服务器IP
    //    db.setUserName("root");     // 数据库库用户名
    //    db.setPassword("123456");   // 密码
    db.setDatabaseName("./info.db"); // 数据库名

    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("create table student(id int primary key, name varchar(255), age int, score int);");

    // 设置模型
    model = new QSqlTableModel(this);
    model->setTable("student"); // 指定表

    // 把model放在view
    ui->tableView->setModel(model);

    // 显式model里的数据
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "学号");

    // 设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 初始化显式排序因素
    QStringList sortFactor;
        sortFactor << "学号" << "姓名" << "年龄" << "分数";
    ui->comboBoxSort->addItems(sortFactor);

    // 初始化显式查找因素
    ui->comboBoxSearch->addItems(sortFactor);
#endif
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonAdd_clicked()
{
    // 添加空记录
    QSqlRecord record = model->record(); // 获取空记录
    // 获取行号
    int row = model->rowCount();
    model->insertRecord(row, record);
}

void Widget::on_pushButtonConfirm_clicked()
{
    model->submitAll();
    model->setFilter("");
}

void Widget::on_pushButtonDel_clicked()
{
    // 获取选中模型
    QItemSelectionModel *sModel = ui->tableView->selectionModel();

    // 取出模型中的索引
    QModelIndexList list = sModel->selectedRows();

    // 删除所有选中的行
    for (int i = 0; i < list.size(); i++) {
        model->removeRow(list.at(i).row());
    }
}

void Widget::on_pushButtonSearch_clicked()
{
    QString str;
    QString findStr = ui->lineEdit->text();
    int index = ui->comboBoxSearch->currentIndex();

    switch (index) {
        case STUDENT_NUMMBER:       // 学号
            str = QString("id = '%1'").arg(findStr.toInt());
            break;
        case STUDENT_NAME:          // 姓名
            str = QString("name = '%1'").arg(findStr);
            break;
        case STUDENT_AGE:           // 年龄
            str = QString("age = '%1'").arg(findStr.toInt());
            break;
        case STUDENT_SCORE:         // 分数
            str = QString("score = '%1'").arg(findStr.toInt());
            break;
        default:
            break;
    }

    model->setFilter(str);
    model->select();
}

void Widget::on_pushButtonCancel_clicked()
{
    model->revertAll(); // 取消所有动作
    model->submitAll(); // 提交所有动作
    model->setFilter("");
}

void Widget::on_pushButtonSort_clicked()
{
    static int sortModel = 0;
    Qt::SortOrder so = Qt::AscendingOrder;
    if(sortModel){
        so = Qt::DescendingOrder;
        sortModel = 0;
        qDebug()<<"DescendingOrder";
    }
    else{
        qDebug()<<"AscendingOrder";
        sortModel = 1;
    }

    int index = ui->comboBoxSort->currentIndex();
    qDebug()<<"index:"<<index;
    model->sort(index, so);
    model->select();
}
