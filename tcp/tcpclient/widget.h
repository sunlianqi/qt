#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void on_pushButton_send_clicked();

    void on_pushButton_link_clicked();

    void readData();
private:
    QTcpSocket *m_socket;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
