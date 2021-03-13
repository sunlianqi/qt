#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void newClient();
    void serverReadData();

private:
    QTcpServer *m_server;
    QTcpSocket *m_socket;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
