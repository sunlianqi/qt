#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

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
    void finishedSlot();
    void readSlot();
private:
    QNetworkAccessManager *m_network;
    QNetworkReply *m_reply;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
