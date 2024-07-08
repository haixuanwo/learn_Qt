#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPainter>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,300,25));
    label->setText("图片已经生成，保存在项目文件中【text.jpg】。");

    //实例QImage
    QImage image = QPixmap("naruto.jpg").toImage();

    //实例QPainter
    QPainter painter(&image);

    //设置画刷模式
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    //改变画笔和字体
    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    QFont font = painter.font();
    font.setBold(true);//加粗
    font.setPixelSize(50);//改变字体大小
    painter.setPen(pen);
    painter.setFont(font);

    //将文字绘制在图片中心位置
    painter.drawText(image.rect(),Qt::AlignCenter,"你好，朋友。");

    //这个为图片的压缩度。0/100
    int n = 100;

    //保存图片
    image.save("text.jpg","JPG",n);
}

MainWindow::~MainWindow()
{
    delete ui;
}
