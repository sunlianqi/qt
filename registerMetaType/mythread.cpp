#include "mythread.h"
#include <QThread>
#include <QtDebug>

MyThread::MyThread()
{

}

void MyThread::sendSignals()
{
    qDebug() << "MyThread:" << QThread::currentThread();
    QVector<int> temp;
    temp.append(1);
    emit testSignals(temp);
}
