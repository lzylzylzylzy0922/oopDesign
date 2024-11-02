#ifndef DATABASECONNECTIONLZY_H
#define DATABASECONNECTIONLZY_H

#include <QObject>
#include<QSqlDatabase>
#include<QDebug>

class databaseConnectionLzy : public QObject
{
    Q_OBJECT
public:
    static QSqlDatabase getInstance();

private:
    explicit databaseConnectionLzy(QObject *parent = nullptr);
    ~databaseConnectionLzy(){};
    static QSqlDatabase database;

signals:
};

#endif // DATABASECONNECTIONLZY_H
