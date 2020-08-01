#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSerialPort/QSerialPort"

#define MSG_LEN 7

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void processSensorData(const QString& arg);

private:
    Ui::MainWindow *ui;
    char message_buf[MSG_LEN];

public:
    QSerialPort serial;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // MAINWINDOW_H
