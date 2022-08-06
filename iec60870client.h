#ifndef IEC60870CLIENT_H
#define IEC60870CLIENT_H

#include <QObject>

class Iec60870Client : public QObject
{
    Q_OBJECT
public:

    public slots:
    void run();
};



#endif // IEC60870CLIENT_H
