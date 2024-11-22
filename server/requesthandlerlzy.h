#ifndef REQUESTHANDLERLZY_H
#define REQUESTHANDLERLZY_H

#include <QObject>

class RequestHandlerLzy : public QObject
{
    Q_OBJECT
public:
    explicit RequestHandlerLzy(QObject *parent = nullptr);

signals:
};

#endif // REQUESTHANDLERLZY_H
