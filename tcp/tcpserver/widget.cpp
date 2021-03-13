#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务器");
    m_server = new QTcpServer(this);
    if(m_server->listen(QHostAddress::Any,1234))
    {
        ui->textEdit->append("listen success");
    }
    else
    {
        ui->textEdit->append("listen error");
    }
    connect(m_server,SIGNAL(newConnection()),this,SLOT(newClient()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_socket->write(QString("服务器：" + ui->lineEdit->text()).toStdString().c_str());
}

void Widget::newClient()
{
    m_socket = m_server->nextPendingConnection();
    ui->textEdit->append("新的客户端连接：" + QString::number(m_socket->socketDescriptor()));
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(serverReadData()));
}

void Widget::serverReadData()
{
    QString str = m_socket->readAll();
    ui->textEdit->append(str);
}

