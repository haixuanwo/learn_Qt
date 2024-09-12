#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>      // 文件查找对话框
#include <QPaintEvent>      // 绘图事件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isPlaying(false)
    , isMute(false)
{
    ui->setupUi(this);

    setWindowTitle("媒体播放器");

    isOpen = false;

    pPlayer = new QMediaPlayer;
    pPlaylist = new QMediaPlaylist;
    pVideoWidget = new QVideoWidget(ui->label);
    pVideoWidget->resize(ui->label->size());

    init_play_list();
    // pPlaylist->playbackModeChanged(QMediaPlaylist::Loop);
    pPlaylist->setPlaybackMode(QMediaPlaylist::Loop);

    pPlayer->setPlaylist(pPlaylist);
    pPlayer->setVideoOutput(pVideoWidget);

    init_serial();

    connect(pPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(pPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(ui->progress, &QSlider::sliderMoved, this, &MainWindow::seek);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init_play_list()
{
    // 设置你想要列出文件的目录
    QString path = "media";

    // 创建QDir对象
    QDir dir(path);

    // 获取目录下的所有文件
    QFileInfoList list = dir.entryInfoList(QDir::Files);

    // 遍历文件信息列表
    for (int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        qDebug() << fileInfo.fileName(); // 输出文件名

        QUrl url(fileInfo.absoluteFilePath());
        pPlaylist->addMedia(url);
    }

    // pPlaylist->next();
    isOpen = true;
    return true;
}

bool MainWindow::init_serial()
{
    serial = std::make_shared<Serial>();
    connect(serial.get(), &Serial::protocol_cmd, this, &MainWindow::protocol_cmd);
    // connect(this, &MainWindow::openSerialPort, serial.get(), &Serial::openSerialPort);

    QStringList commPortList;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString portName = info.portName();
        qDebug() << "portName: " << portName;
        if (!portName.contains("COM1"))
        {
            serial->openSerialPort(portName);
            break;
        }
    }

    return true;
}

void MainWindow::on_openBtn_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "查看文件",
                                 "D:/txh/raw",
                                 // "E:/02_Clark/小学期课程资料 - 基于FFmpeg+SDL的视频播放器的制/工具/testvideo",
                                "allfiles(*.*);;"
                                "MP3(*.mp3);;"
                                "MP4(*.mp4);;"
                                "MKV(*.mkv);;"
                                "AVI(*.avi);;");

    pPlaylist->clear();
    foreach(QString const &str, fileNames)
    {
        qDebug() << str;        
        QUrl url = QUrl::fromLocalFile(QFileInfo(str).absoluteFilePath());
        pPlaylist->addMedia(url);
    }

    isOpen = true;
}

void MainWindow::on_playBtn_clicked()
{
    qDebug() << "play: " << isPlaying;
    if (isPlaying)
    {
        isPlaying = false;
        pPlayer->pause();
        ui->playBtn->setText("播放");
    }
    else
    {
        pPlayer->play();
        pVideoWidget->resize(ui->label->size());
        isPlaying = true;
        ui->playBtn->setText("暂停");
    }
}

void MainWindow::durationChanged(qint64 duration)
{
    qDebug() << "duration: " << duration;
    qint64 m_duration = duration / 1000;
    ui->progress->setMaximum(m_duration);
}

void MainWindow::positionChanged(qint64 progress)
{
    if (!ui->progress->isSliderDown())
        ui->progress->setValue(progress / 1000);

    //updateDurationInfo(progress / 1000);
}

void MainWindow::seek(int seconds)
{
    pPlayer->setPosition(seconds * 1000);
}

// void MainWindow::on_stopBtn_clicked()
// {
//     pPlayer->stop();
//     isPlaying = false;
//     ui->playBtn->setText("播放");
// }

void MainWindow::paintEvent(QPaintEvent *e)
{
    if (isOpen)
    {
        pVideoWidget->resize(ui->label->size());
    }
}

void MainWindow::on_replayBtn_clicked()
{
    pPlayer->stop();
    pPlayer->play();
    qDebug() << "replay: ";
}

void MainWindow::on_cutBtn_clicked()
{
    pPlaylist->next();
    pPlayer->play();
    qDebug() << "next: ";
}


void MainWindow::on_audioByn_clicked()
{
    isMute = !isMute;
    pPlayer->setMuted(isMute);
    ui->audioByn->setText(isMute?"伴唱":"原唱");
    qDebug() << "isMute: " << isMute;
}

void MainWindow::protocol_cmd(ProtocolCmd cmd)
{
    qDebug() << "MainWindow::protocol_cmd: " << cmd;
    switch (cmd)
    {
        case SWITCH_SONG:       // [切歌:02]
        {
            on_cutBtn_clicked();
            break;
        }
        case PLAY_STOP:         // [播放/暂停:03]
        {
            on_playBtn_clicked();
            break;
        }
        case REPLAY:            // [重唱:0b]
        {
            on_replayBtn_clicked();
            break;
        }
        case ORIGINAL_VOCALIST: // [原伴唱:0c]
        {
            on_audioByn_clicked();
            break;
        }
        default:
        {
            qDebug() << "unknow cmd: " << cmd;
            break;
        }
    }
}
