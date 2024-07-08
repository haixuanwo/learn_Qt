#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);

protected:
    // QThread的虚函数
    // 线程处理函数
    // 不能直接调用，通过start
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
