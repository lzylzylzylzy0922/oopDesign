//dao类：管理用户

#ifndef USERDAOLZY_H
#define USERDAOLZY_H

#include <QObject>
#include<databaseconnectionlzy.h>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDate>
#include"AccountType.h"
#include<UserLzy.h>
#include<AccountLzy.h>
#include<LoginStatusLzy.h>
#include<utilsLzy.h>

class userDaoLzy : public QObject
{
    Q_OBJECT
public:
    static userDaoLzy* getInstance();//获得单例对象
    bool isUserExistsByAccountAndType(QString accountId,QString type);    //通过账号查找用户是否存在
    bool isPasswordCorrect(QString accountId,QString password);              //校验密码是否正确
    bool isUserExistsByPhoneAndType(QString phoneNumber,AccountType type);//通过手机号和应用类型判断账户是否存在
    bool createAccount(AccountLzy* account,QDate birth,QString location,QString telephone); //创建账户
    AccountLzy* returnAccount(QString AccountId);                        //通过账户id创建account实体类
    void updateOnlineStatus(AccountLzy* account,loginStatus status);                           // 更新用户状态
private:
    explicit userDaoLzy(QObject *parent = nullptr);
    static userDaoLzy* userDao;
    QSqlDatabase database=databaseConnectionLzy::getInstance();
    QSqlQuery query;
signals:
};

#endif // USERDAOLZY_H
