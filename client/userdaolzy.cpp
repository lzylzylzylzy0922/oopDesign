#include "userdaolzy.h"

userDaoLzy::userDaoLzy(QObject *parent)
    : QObject{parent}
{
    database.open();
}

bool userDaoLzy::isUserExistsByAccount(QString accountId){
    query.prepare("select * from account where account_id=:id");
    query.bindValue(":id",accountId);

    query.exec();
    if(query.next())
        return true;
    return false;
}

bool userDaoLzy::isPasswordCorrect(QString accountId,QString password){
    query.prepare("select * from account where account_id=:id and password=:password");
    query.bindValue(":id",accountId);
    query.bindValue(":password",password);

    query.exec();
    if(query.size()>0){
        return true;
    }

    return false;
}
