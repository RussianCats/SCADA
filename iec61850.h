#ifndef IEC61850_H
#define IEC61850_H

#include <QObject>
#include <QDebug>
#include <stdlib.h>
#include <stdio.h>

//для технологии pipe
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class Iec61850 : public QObject
{
    Q_OBJECT
    //переменная по которой будем выходить из цикла и завершать выполнение метода
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged);
public:
    explicit Iec61850(QObject *parent = nullptr);

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

#endif // IEC61850_H
