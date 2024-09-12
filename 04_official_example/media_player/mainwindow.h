#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>     // 播放器
#include <QMediaPlaylist>   // 播放队列
#include <QVideoWidget>     // 视频显示窗口

#include "Serial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool init_play_list();

    bool init_serial();

private slots:

    void on_openBtn_clicked();

    void on_playBtn_clicked();   

    void on_replayBtn_clicked();

    void on_cutBtn_clicked();

    void on_audioByn_clicked();

    void protocol_cmd(ProtocolCmd cmd);

    void durationChanged(qint64 duration);

    void positionChanged(qint64 progress);

    void seek(int seconds);

signals:
    void openSerialPort(QString &deviceName);

protected:
    void paintEvent(QPaintEvent *e);

private:

    std::shared_ptr<Serial> serial;

    bool isMute;       // 是否有静音
    bool isPlaying;     // 是否正在播放
    bool isOpen;
    QMediaPlayer *pPlayer;
    QMediaPlaylist *pPlaylist;
    QVideoWidget *pVideoWidget;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
