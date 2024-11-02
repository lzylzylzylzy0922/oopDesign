#ifndef USERLZY_H
#define USERLZY_H

#include <QObject>
#include<QString>
#include<QDate>

class userLzy : public QObject
{
    Q_OBJECT
public:
    explicit userLzy(QObject *parent = nullptr);
private:

signals:
};

#endif // USERLZY_H
