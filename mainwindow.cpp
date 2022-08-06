#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<QDebug>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //как только поток стартует то запускается метод run  из класса Iec60870
    connect(&ThreadIec60870, &QThread::started, &iec60870, &Iec60870::run);
    connect(&ThreadIec60870Client, &QThread::started, &iec60870Client, &Iec60870Client::run);
    //если вызвался сигнал emitStop, то поток завершается
    connect(&iec60870, &Iec60870::emitStop, &ThreadIec60870, &QThread::terminate);
    connect(&iec60870, &Iec60870::emitStop, &ThreadIec60870Client, &QThread::terminate);
    // передать объект в поток
    iec60870.moveToThread(&ThreadIec60870);
    iec60870Client.moveToThread(&ThreadIec60870Client);



}

MainWindow::~MainWindow()
{
    delete ui;
}




 /*----------------------------------------------------// iec60870-5-104 //-----------------------------------------------------*/

void MainWindow::on_checkBox_stateChanged(int arg1)
{
   qInfo() << "нажали 1:" << arg1;
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    qInfo() << "нажали 2:"  << arg1;
}

void MainWindow::updateTextEdit(float temperature, float humidity, float pressure)
{
    QString string = QString::number(temperature) + "\t" + QString::number(humidity) + "\t" + QString::number(pressure) + "\n";
    ui->textEdit->insertPlainText(string);
}


//вкл
void MainWindow::on_pushButton_3_clicked()
{
    //ui->textEdit->insertPlainText("добавил текст\n");
    //начальный текст
    ui->textEdit->insertPlainText("temperature\thumidity\tpressure\n");

    //чтобы выполнялся цикл
    iec60870.setRunning(true);


    //запустить поток
    ThreadIec60870.start();
    ThreadIec60870Client.start();


    //iec60870Client.run();
    //при вызове сигнала emitSendData данные выводятся в gui через метод updateTextEdit
    connect(&iec60870, SIGNAL(emitSendData(float, float, float)), this, SLOT(updateTextEdit(float, float, float)));





}


//выкл
void MainWindow::on_pushButton_6_clicked()
{
    //чтобы остановился цикл
    iec60870.setRunning(false);

    //отключает соеденение с сигнала emitSendData и данных которые выводятся в gui через метод updateTextEdit
    disconnect(&iec60870, SIGNAL(emitSendData(float, float, float)), this, SLOT(updateTextEdit(float, float, float)));

    ui->textEdit->setText("");

}

/*------------------------------------------------------------------------------------------------------------*/
