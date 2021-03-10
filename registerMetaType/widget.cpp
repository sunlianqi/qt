#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "mian:" << QThread::currentThread();

    m_myThread = new MyThread;
    QThread *thread = new QThread;
    m_myThread->moveToThread(thread);
    connect(m_myThread,SIGNAL(testSignals(QVector<int>)),this,SLOT(testSlots(QVector<int>)));
    connect(ui->pushButton,SIGNAL(clicked()),m_myThread,SLOT(sendSignals()));
    thread->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::testSlots(QVector<int> temp)
{
    foreach(int vec,temp)
    {
        qDebug() << "temp number:"<< vec;
    }
    qDebug() << "testSlots";
}
