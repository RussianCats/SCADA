#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QThread>
#include <iec60870.h>
#include <iec60870client.h>
#include <iec61850.h>
#include <iec61850client.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void updateTextEditIec60870(float temperature, float humidity, float pressure);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void updateTextEditIec61850(float temperature, float humidity, float pressure);

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

//iec60870
     // объект на поток
    QThread ThreadIec60870;
    QThread ThreadIec60870Client;
    // создание объекта класса
    Iec60870 iec60870;
    Iec60870Client iec60870Client;

//iec61850
     // объект на поток
    QThread ThreadIec61850;
    QThread ThreadIec61850Client;
    // создание объекта класса
    Iec61850 iec61850;
    Iec61850Client iec61850Client;
};
#endif // MAINWINDOW_H
