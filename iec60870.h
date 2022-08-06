#ifndef IEC60870_H
#define IEC60870_H

#include <QObject>
//#include <lib60870-C/examples/cs104_client/simple_client.cpp>
//для задержки времени
#include <QDebug>
#include <stdlib.h>
#include <stdio.h>

//для технологии pipe
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


class Iec60870 : public QObject
{
    Q_OBJECT
    //переменная по которой будем выходить из цикла и завершать выполнение метода
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged);
    //
    //Q_PROPERTY(QString message READ massage WRITE setMassage NOTIFY massageChanged);


public:
    explicit Iec60870(QObject *parent = nullptr);

    bool running() const;
    void setRunning(bool newRunning);

signals:
    //чтобы завершить поток
    void emitStop();
    //отправлять данные с протокола
    void emitSendData(float temperature, float humidity, float pressure);

    void runningChanged();

public slots:
    // слот генерирует числа
    void run();

private:
    bool m_running;
};
#endif // IEC60870_H








