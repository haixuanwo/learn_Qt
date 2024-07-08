#include "mythread.h"

myThread::myThread(QObject *parent) : QThread(parent)
{

}

void myThread::run()
{
    // 很复杂的数据处理
    // 需要耗时5s
    sleep(5);
    emit isDone();
}

