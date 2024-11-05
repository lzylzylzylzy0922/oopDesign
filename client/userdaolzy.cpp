#include "userdaolzy.h"

userDaoLzy::userDaoLzy(QObject *parent)
    : QObject{parent}
{
    database.open();
}

bool userDaoLzy::isUserExistsByAccountAndType(QString accountId, QString type) {
    query.prepare("SELECT * FROM account WHERE account_id = :id AND type = :type");
    query.bindValue(":id", accountId);
    query.bindValue(":type", type);

    if (query.exec() && query.next()) {
        return true;
    }
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

bool userDaoLzy::isUserExistsByPhoneAndType(QString phoneNumber,AccountType type){
    QString t;
    if(type==AccountType::QQ){
        t="QQ";
    }else if(type==AccountType::WECHAT){
        t="WECHAT";
    }else{
        t="WEIBO";
    }

    query.prepare("select * from user where phone_number=:phoneNumber");
    query.bindValue(":phoneNumber",phoneNumber);

    query.exec();
    if(query.next()){
        int userId=query.value(0).toInt();
        query.prepare("select * from account where user_id=:userId and type=:type");
        query.bindValue(":userId",userId);
        query.bindValue(":type",t);
        query.exec();
        if(query.next()){
            return true;
        }
    }else{
        return false;
    }

    return false;
}

bool userDaoLzy::createAccount(AccountLzy account){
    //先判断user表中用户是否已经存在


    //如果不存在，先向user表中插入，再向account表中插入
}
