#include "mainwindow.h"
#include <QApplication>
#include "QLabel"
#include "QFile"
#include "QTextStream"
#include "QProcess"
#include "tty_rpmsg.h"
#include <signal.h>
#include <unistd.h>
#include "QtSerialPort/QSerialPort"


void catchUnixSignals(const std::vector<int>& quitSignals,
                      const std::vector<int>& ignoreSignals = std::vector<int>())
{
    auto handler = [](int sig) ->void {
        QCoreApplication::quit();
    };

    for ( int sig : ignoreSignals )
        signal(sig, SIG_IGN);

    for ( int sig : quitSignals )
        signal(sig, handler);
}


int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        MainWindow w;
        QSerialPort serialPort0;

        catchUnixSignals({SIGQUIT, SIGINT, SIGTERM, SIGHUP, SIGKILL});
        serialPort0.setPortName("/dev/ttyRPMSG0");
        serialPort0.open(QIODevice::ReadWrite);
        tty_rpmsg tty_rpmsg(&serialPort0);

        QObject::connect(&tty_rpmsg, &tty_rpmsg::m4_dataAvailable, &w, &MainWindow::processSensorData);

        w.setFixedSize(480, 800);
        w.setStyleSheet("background-color: white;");
        w.centralWidget();
        w.show();
        return a.exec(); 
}
