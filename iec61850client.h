#ifndef IEC61850CLIENT_H
#define IEC61850CLIENT_H

#include <QObject>

class Iec61850Client : public QObject
{
    Q_OBJECT
public:

    public slots:
    void run();
};

#endif // IEC61850CLIENT_H
