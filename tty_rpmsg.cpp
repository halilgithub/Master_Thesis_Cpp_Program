#include "tty_rpmsg.h"
#include <QByteArray>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

tty_rpmsg::tty_rpmsg(QSerialPort *serialPort, QObject *parent)
    : QObject(parent)
    , m_serialPort(serialPort)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &tty_rpmsg::handleReadyRead);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
                this, &tty_rpmsg::handleError);
}

tty_rpmsg::~tty_rpmsg()
{
    m_serialPort->close();
}

void tty_rpmsg::handleReadyRead()
{
    emit m4_dataAvailable(m_serialPort->readAll());
}

void tty_rpmsg::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ReadError) {
        QMessageBox msgBox;
        msgBox.setText("IO error occured");
        msgBox.exec();
    }
}

void tty_rpmsg::sendCommand(const QByteArray &arg)
{
    m_serialPort->write(arg, arg.length());
}
