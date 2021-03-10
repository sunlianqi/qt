#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    MyThread();
public slots:
    void sendSignals();
signals:
    void testSignals(QVector<int>);
};

#endif // MYTHREAD_H
