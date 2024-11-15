#include "userdaolzy.h"

userDaoLzy* userDaoLzy::userDao=nullptr;

userDaoLzy::userDaoLzy(QObject *parent)
    : QObject{parent}
{
    database.open();
}

userDaoLzy* userDaoLzy::getInstance(){
    if(userDao==nullptr){
        userDao=new userDaoLzy;
    }

    return userDao;
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

bool userDaoLzy::createAccount(AccountLzy* account,QDate birth,QString location,QString telephone){
    //先判断account表中用户是否已经存在
    QSqlQuery query;
    query.prepare("select * from account where account_id=:accountId");
    query.bindValue(":accountId",account->getAccountId());
    query.exec();
    //qDebug()<<query.size();
    //如果不存在，先向user表中插入，并获得user_id，再向account表中插入
    if(!query.next()){
        //向user表中插入
        UserLzy* user=new UserLzy(birth,QDateTime::currentDateTime(),location,telephone);

        query.prepare("insert into user (birthday,register_date,location,phone_number) values (:birth,:registerDate,:location,:phoneNumber);");

        query.bindValue(":birth",user->getBirthday().toString("yyyy-MM-dd"));
        query.bindValue(":registerDate",user->getRegisterDate().toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":location",user->getLocation());
        query.bindValue(":phoneNumber",user->getPhoneNumber());

        //获得user_id
        int userId;
        if (query.exec()) {  // 确保查询成功并且有记录返回
            userId = query.lastInsertId().toInt();  // 获取user_id
            qDebug() << "User ID:" << userId;
            delete user;
        }else{
            qDebug()<<query.lastError().text();
            return false;
        }


        //向account表插入数据
        query.prepare("insert into account values (:accountId,:userId,:type,:accountName,:password,:avatar);");
        query.bindValue(":accountId",account->getAccountId());
        query.bindValue(":userId",userId);
        query.bindValue(":avatar",account->getAvatar());

        QString type;
        if(account->getType()==AccountType::QQ){
            type="QQ";
        }else if(account->getType()==AccountType::WECHAT){
            type="WECHAT";
        }else{
            type="WEIBO";
        }
        query.bindValue(":type",type);
        query.bindValue(":accountName",account->getAccountName());
        query.bindValue(":password",account->getPassword());

        query.exec();
        return true;
    }
    return false;
}


AccountLzy* userDaoLzy::returnAccount(QString accountId){
    query.prepare("select * from account where account_id=:accountId");
    query.bindValue(":accountId", accountId);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return nullptr;  // 查询执行失败，返回 nullptr
    }

    if (!query.next()) {
        qWarning() << "No records found for account_id:" << accountId;
        return nullptr;  // 如果没有记录，返回 nullptr
    }


    if (query.value(2).toString() == "QQ") {
        return new AccountLzy(accountId, AccountType::QQ, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    } else if (query.value(2).toString() == "WECHAT") {
        return new AccountLzy(accountId, AccountType::WECHAT, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    } else {
        return new AccountLzy(accountId, AccountType::WEIBO, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    }
}

UserLzy* userDaoLzy::returnUser(QString accountId){
    query.prepare("select user_id from account where account_id=:accountId");
    query.bindValue(":accountId",accountId);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return nullptr;  // 查询执行失败，返回 nullptr
    }

    if (!query.next()) {
        qWarning() << "No records found for account_id:" << accountId;
        return nullptr;  // 如果没有记录，返回 nullptr
    }

    int userId=query.value(0).toInt();

    query.prepare("select * from user where user_id=:userId");
    query.bindValue(":userId",userId);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return nullptr;  // 查询执行失败，返回 nullptr
    }

    if (!query.next()) {
        qWarning() << "No records found for account_id:" << accountId;
        return nullptr;  // 如果没有记录，返回 nullptr
    }

    QDate birth=query.value(1).toDate();
    QDateTime registerTime=query.value(2).toDateTime();
    QString location=query.value(3).toString();
    QString telephone=query.value(4).toString();


    UserLzy* user=new UserLzy(birth,registerTime,location,telephone);

    return user;
}

void userDaoLzy::updateOnlineStatus(AccountLzy* account,loginStatus status){

    QString ip=utilsLzy::getLocalIPAddress();
    int userId=0;
    //QString port=utilsLzy::getPort(&server);
    qDebug()<<ip;
    //获取user_id

    query.prepare("select user_id from account where account_id=:accountId");
    query.bindValue(":accountId",account->getAccountId());
    query.exec();
    if(query.next()){
        userId=query.value(0).toInt();
        qDebug()<<userId;
    }

    //先判断login_status中有没有该用户信息
    query.prepare("select * from login_status where user_id=:userId;");
    query.bindValue(":userId",userId);

    query.exec();
    if(query.next()&&status==loginStatus::OFFLINE){
        query.prepare("update login_status set is_active=:isActive where user_id=:userId;");
        query.bindValue(":isActive",0);
        query.bindValue(":userId",userId);
        query.exec();
        qDebug()<<"更新"<<account->getAccountId()<<"离线";

        return;
    }

    //向login_status插入
    query.prepare("insert into login_status (user_id,type,login_time,is_active,ip,port) values (:userId,:type,:loginTime,:isActive,:ip,:port);");
    query.bindValue(":userId",userId);





    if(account->getType()==AccountType::QQ) query.bindValue(":type","QQ");
    else if(account->getType()==AccountType::WECHAT) query.bindValue(":type","WECHAT");
    else query.bindValue(":type","WEIBO");

    query.bindValue(":loginTime",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    query.bindValue(":isActive",1);
    qDebug()<<"更新"<<account->getAccountId()<<"在线";

    query.bindValue(":ip",ip);
    query.bindValue(":port",0);//暂时写0

    query.exec();


}

QSqlQuery userDaoLzy::searchUsersById(QString text){
    QSqlQuery query;
    query.prepare("select * from account where account_id REGEXP :accountId");
    query.bindValue(":accountId",text);
    query.exec();
    return query;
}
