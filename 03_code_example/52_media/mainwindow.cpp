#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QAxWidget(播放器插件)
    axWidget = new QAxWidget;

    //注册表键值,调用插件
    axWidget->setControl("{22D6F312-B0F6-11D0-94AB-0080C74C7E95}");
    axWidget->setProperty("ShowControls", false);
    axWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(axWidget, SIGNAL(PlayStateChange(int, int)),
    this, SLOT(onPlayStateChange(int, int)));
    connect(axWidget, SIGNAL(ReadyStateChange(ReadyStateConstants)),
    this, SLOT(onReadyStateChange(ReadyStateConstants)));
    connect(axWidget, SIGNAL(PositionChange(double, double)),
    this, SLOT(onPositionChange(double, double)));

    //实例打开文件按钮
    openButton = new QToolButton;
    openButton->setText(tr("浏览.."));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    //实例播放暂停按钮
    playPauseButton = new QToolButton;
    playPauseButton->setText(tr("播放"));
    playPauseButton->setEnabled(false);
    connect(playPauseButton, SIGNAL(clicked()), axWidget, SLOT(Play()));

    //停止按钮
    stopButton = new QToolButton;
    stopButton->setText(tr("停止"));
    stopButton->setEnabled(false);
    connect(stopButton, SIGNAL(clicked()), axWidget, SLOT(Stop()));

    //进度条
    seekSlider = new QSlider(Qt::Horizontal);
    seekSlider->setEnabled(false);
    connect(seekSlider, SIGNAL(valueChanged(int)),
    this, SLOT(sliderValueChanged(int)));
    connect(seekSlider, SIGNAL(sliderPressed()),
    axWidget, SLOT(Pause()));

    //可播放格式，此处简写下面几个
    fileFilters = tr("Video files (*.mpg *.mpeg *.avi *.wmv *.mp4)\n""Audio files (*.mp3 *.wav)");

    //初始化播放时间进度
    updateTimer = 0;

    //三个按钮横向布局
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(playPauseButton);
    buttonLayout->addWidget(stopButton);

    //纵向布局，上面播放器下面三个按钮
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(axWidget);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(seekSlider);

    //显示布局控件
    widget = new QWidget();
    widget->setLayout(mainLayout);
    this->setCentralWidget(widget);
}


//选择音视频文件
void MainWindow::openFile()
{
    //定义QString变量接收文件
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), ".", fileFilters);

    //如果文件不为空,则播放
    if (!fileName.isEmpty())
        axWidget->setProperty("FileName",QDir::toNativeSeparators(fileName));
}

//进度条随播放器移动
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == updateTimer)
    {
        double curPos = axWidget->property("CurrentPosition").toDouble();
        onPositionChange(-1, curPos);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void MainWindow::onPlayStateChange(int, int newState)
{
    playPauseButton->disconnect(axWidget);
    switch (newState)
    {
        case Stopped:
            if (updateTimer)
            {
                killTimer(updateTimer);
                updateTimer = 0;
            }

        case Paused:
            connect(playPauseButton, SIGNAL(clicked()), axWidget, SLOT(Play()));
            stopButton->setEnabled(false);
            playPauseButton->setText(tr("播放"));
            break;

       case Playing:
            if (!updateTimer)
                updateTimer = startTimer(100);

            connect(playPauseButton, SIGNAL(clicked()), axWidget, SLOT(Pause()));
            stopButton->setEnabled(true);
            playPauseButton->setText(tr("暂停"));
    }
}

void MainWindow::onReadyStateChange(ReadyStateConstants ready)
{
    if (ready == Complete)
    {
        double duration = 60 * axWidget->property("Duration").toDouble();
        seekSlider->setMinimum(0);
        seekSlider->setMaximum(int(duration));
        seekSlider->setEnabled(true);
        playPauseButton->setEnabled(true);
    }
}

void MainWindow::onPositionChange(double, double newPos)
{
    seekSlider->blockSignals(true);
    seekSlider->setValue(int(newPos * 60));
    seekSlider->blockSignals(false);
}

void MainWindow::sliderValueChanged(int newValue)
{
    seekSlider->blockSignals(true);
    axWidget->setProperty("CurrentPosition", double(newValue) / 60);
    seekSlider->blockSignals(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
