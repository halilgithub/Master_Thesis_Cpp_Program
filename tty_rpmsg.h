#ifndef TTY_RPMSG_H
#define TTY_RPMSG_H

#include <QtCore/QObject>
#include <QtCore/QTextStream>
#include <QtSerialPort/QSerialPort>

class tty_rpmsg : public QObject
{
    Q_OBJECT
public:
    explicit tty_rpmsg(QSerialPort *serialPort, QObject *parent = nullptr);
    ~tty_rpmsg();

public slots:
    void sendCommand(const QByteArray& arg);

signals:
    void m4_dataAvailable(const QString& arg);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
};

#endif // TTY_RPMSG_H
