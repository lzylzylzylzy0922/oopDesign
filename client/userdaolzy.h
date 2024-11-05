//dao类：管理用户

#ifndef USERDAOLZY_H
#define USERDAOLZY_H

#include <QObject>
#include<databaseconnectionlzy.h>
#include<QSqlDatabase>
#include<QSqlQuery>
#include"AccountType.h"
#include<AccountLzy.h>

class userDaoLzy : public QObject
{
    Q_OBJECT
public:
    explicit userDaoLzy(QObject *parent = nullptr);
    bool isUserExistsByAccountAndType(QString accountId,QString type);    //通过账号查找用户是否存在
    bool isPasswordCorrect(QString accountId,QString password);              //校验密码是否正确
    bool isUserExistsByPhoneAndType(QString phoneNumber,AccountType type);//通过手机号和应用类型判断账户是否存在
    bool createAccount(AccountLzy account);                                 //创建账户
private:
    QSqlDatabase database=databaseConnectionLzy::getInstance();
    QSqlQuery query;
signals:
};

#endif // USERDAOLZY_H
