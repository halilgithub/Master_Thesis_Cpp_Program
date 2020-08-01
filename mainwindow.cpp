#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QCloseEvent"
#include "QProcess"
#include "QDebug"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void QWidget::closeEvent(QCloseEvent *event){
    QProcess::execute("dd if=/dev/zero of=/dev/fb0");
    QProcess::execute("./fw_cortex_m4.sh stop");
    event->accept();
}

MainWindow::~MainWindow()
{
    if (serial.isOpen())
           serial.close();
    delete ui;
}

void MainWindow::processSensorData(const QString &str){

    QStringList list = str.split(',');
    ui->label->setText(list.at(0));
    ui->label_2->setText(list.at(1));
    ui->label_3->setText(list.at(2));
}


void MainWindow::on_pushButton_3_clicked()
{
    QProcess process;
    process.startDetached("/bin/sh", QStringList()<< "/usr/local/projects/OpenAMP_TTY_echo/lowpower.sh");
}

void MainWindow::on_pushButton_4_clicked()
{
    QProcess process;
    process.startDetached("/bin/sh", QStringList()<< "/usr/local/projects/OpenAMP_TTY_echo/loop.sh");
}
