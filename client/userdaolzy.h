#ifndef USERDAOLZY_H
#define USERDAOLZY_H

#include <QObject>
#include<databaseconnectionlzy.h>
#include<QSqlDatabase>
#include<QSqlQuery>

class userDaoLzy : public QObject
{
    Q_OBJECT
public:
    explicit userDaoLzy(QObject *parent = nullptr);
    //bool isUserExistsByAccount(QString accountId);    //通过账号查找用户是否存在
private:
    QSqlDatabase database=databaseConnectionLzy::getInstance();
signals:
};

#endif // USERDAOLZY_H
