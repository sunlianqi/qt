#include "widget.h"
#include "ui_widget.h"
#include <QNetworkRequest>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_network = new QNetworkAccessManager(this);
    ui->lineEdit->setText("https://www.baidu.com");
    m_reply = nullptr;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_reply =  m_network->get(QNetworkRequest(QUrl(ui->lineEdit->text())));
    connect(m_reply,&QNetworkReply::finished,this,&Widget::finishedSlot);
    connect(m_reply,&QNetworkReply::readyRead,this,&Widget::readSlot);
}

void Widget::finishedSlot()
{
    m_reply->deleteLater();
    m_reply = nullptr;
    qDebug() << "reply finished";
}

void Widget::readSlot()
{
    qDebug() << m_reply->readAll();
}
