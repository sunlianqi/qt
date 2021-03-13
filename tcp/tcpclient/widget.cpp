#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    m_socket = new QTcpSocket(this);
    ui->lineEdit_ip->setText("127.0.0.1");
    ui->lineEdit_port->setText("1234");
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(readData()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readData()
{
    ui->textEdit->append(m_socket->readAll());
}

void Widget::on_pushButton_send_clicked()
{
    QString str = "客户端:" + ui->lineEdit_send->text();
    m_socket->write(str.toStdString().c_str());
}

void Widget::on_pushButton_link_clicked()
{
    m_socket->connectToHost(ui->lineEdit_ip->text(),ui->lineEdit_port->text().toInt());
    if(m_socket->waitForConnected(3000))
    {
        ui->textEdit->append("connect server success");
    }
    else
    {
        ui->textEdit->append("connect server fail");
    }
}
