
#include <QApplication>
#include <QFile>
#include <QtDebug>


void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);//调试信息
        break;
    case QtInfoMsg:
        txt = QString("Info: %1").arg(msg);//一般信息
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);//警告信息
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);//严重错误信息
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);//致命错误信息
        break;
    }

    txt = txt + QString(" line:%1").arg(context.line);

    QFile logFile("log.txt");
    logFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream in(&logFile);
    in << txt << endl;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //先注册自己的MessageHandler
    qInstallMessageHandler(customMessageHandler);

    qDebug() << "This is a debug message";
    qInfo() << "This is a info message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    qFatal("This is a fatal message");

}
