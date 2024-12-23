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

    query.prepare("select * from user where phone_number=:phoneNumber;");
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
    //先判断user表中用户是否已经存在
    int userId=0;

    QSqlQuery query;
    query.prepare("select * from user where phone_number=:telephone");
    query.bindValue(":telephone",telephone);
    query.exec();
    //qDebug()<<query.size();
    //如果不存在，先向user表中插入，并获得user_id，再向account表中插入
    //如果存在用户，直接向account表中插入
    if(!query.next()){
        //向user表中插入
        UserLzy* user=new UserLzy(birth,QDateTime::currentDateTime(),location,telephone);

        query.prepare("insert into user (birthday,register_date,location,phone_number) values (:birth,:registerDate,:location,:phoneNumber);");

        query.bindValue(":birth",user->getBirthday().toString("yyyy-MM-dd"));
        query.bindValue(":registerDate",user->getRegisterDate().toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":location",user->getLocation());
        query.bindValue(":phoneNumber",user->getPhoneNumber());

        //获得user_id

        if (query.exec()) {  // 确保查询成功并且有记录返回
            userId = query.lastInsertId().toInt();  // 获取user_id
            qDebug() << "User ID:" << userId;
            delete user;
        }else{
            qDebug()<<query.lastError().text();
            return false;
        }
    }else{
        userId=query.value(0).toInt();
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

    return false;
}


AccountLzy* userDaoLzy::returnAccount(const QString& accountId){
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
        return new AccountLzy(accountId, query.value(1).toInt(),AccountType::QQ, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    } else if (query.value(2).toString() == "WECHAT") {
        return new AccountLzy(accountId, query.value(1).toInt(), AccountType::WECHAT, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    } else {
        return new AccountLzy(accountId, query.value(1).toInt(), AccountType::WEIBO, query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
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

    user->setUserId(userId);

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

QSqlQuery userDaoLzy::searchGroupsById(int groupId){
    QSqlQuery query;
    query.prepare("SELECT * FROM user_group WHERE group_id REGEXP :groupId");

    query.bindValue(":groupId", groupId);
    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return query;
    }

    return query;
}

bool userDaoLzy::checkIfFriend(int userId1,int userId2,AccountType type){
    qDebug()<<userId1<<userId2;

    query.prepare("select * from friendship where user_id=:userId1 and friend_id=:userId2 and type=:type");
    query.bindValue(":userId1",userId1);
    query.bindValue(":userId2",userId2);
    QString t;
    if(type==AccountType::QQ){
        t="QQ";
    }else if(type==AccountType::WECHAT){
        t="WECHAT";
    }else{
        t="WEIBO";
    }
    query.bindValue(":type",t);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return false;  // 查询执行失败，返回 nullptr
    }

    if (!query.next()) {
        qWarning() << "No records";
        return false;  // 如果没有记录，返回 nullptr
    }

    return true;
}

bool userDaoLzy::ifSentAddFriendRequest(AccountLzy* account,AccountLzy* friendAccount){
    query.prepare("select * from friend_request where account_id=:accountId and friend_account_id=:friendAccountId");
    query.bindValue(":accountId",account->getAccountId());
    query.bindValue(":friendAccountId",friendAccount->getAccountId());

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return false;  // 查询执行失败，返回 nullptr
    }

    if (!query.next()) {
        qWarning() << "No records";
        return false;  // 如果没有记录，返回 false
    }

    return true;
}

bool userDaoLzy::addFriend(AccountLzy* account,AccountLzy* friendAccount){
    if(this->ifSentAddFriendRequest(account,friendAccount)){
        return false;
    }

    query.prepare("insert into friend_request values (:accountId,:friendAccountId,:time,:status);");
    query.bindValue(":accountId",account->getAccountId());
    query.bindValue(":friendAccountId",friendAccount->getAccountId());
    query.bindValue(":time",((new QDateTime())->currentDateTime()).toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":status","PENDING");

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return false;
    }

    return true;
}

bool userDaoLzy::removeFriend(AccountLzy* account, AccountLzy* friendAccount) {
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    QSqlQuery query;
    int userId = userDao->returnUser(account->getAccountId())->getUserId();
    int friendId = userDao->returnUser(friendAccount->getAccountId())->getUserId();
    QString type = utilsLzy::getInstance()->getType(account);

    query.prepare("delete from friendship where user_id=:userId and friend_id=:friendId and type=:type");
    query.bindValue(":userId", userId);
    query.bindValue(":friendId", friendId);
    query.bindValue(":type", type);

    if (!query.exec()) {
        qWarning() << "remove friend failed:" << query.lastError().text()
        << " | SQL: " << query.executedQuery()
        << " | userId: " << userId << ", friendId: " << friendId << ", type: " << type;
        db.rollback();
        return false;
    }

    query.prepare("delete from friendship where user_id=:userId and friend_id=:friendId and type=:type");
    query.bindValue(":userId", friendId);
    query.bindValue(":friendId", userId);
    query.bindValue(":type", type);

    if (!query.exec()) {
        qWarning() << "remove friend failed:" << query.lastError().text()
        << " | SQL: " << query.executedQuery()
        << " | userId: " << friendId << ", friendId: " << userId << ", type: " << type;
        db.rollback();
        return false;
    }

    db.commit();
    return true;
}

QSqlQuery userDaoLzy::searchRequest(const QString& accountId){
    QSqlQuery query;
    query.prepare("select * from friend_request where friend_account_id=:friendAccountId;");
    query.bindValue(":friendAccountId",accountId);
    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return query;
    }

    return query;
}



void userDaoLzy::agreeFriendRequest(AccountLzy* owner,AccountLzy* friendAccount){
    //更改好友申请表
    query.prepare("delete from friend_request where account_id=:friendAccount;");

    query.bindValue(":friendAccount",friendAccount->getAccountId());

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return;
    }

    //更改好友表(两项）
    query.prepare("insert into friendship values (:userId,:friendId,:type)");

    query.bindValue(":userId",owner->getUserId());

    query.bindValue(":friendId",friendAccount->getUserId());

    if(owner->getType()==AccountType::QQ){
        query.bindValue(":type","QQ");
    }else if(owner->getType()==AccountType::WECHAT){
        query.bindValue(":type","WECHAT");
    }else{
        query.bindValue(":type","WEIBO");
    }

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return;
    }


    query.prepare("insert into friendship values (:userId,:friendId,:type)");

    query.bindValue(":userId",friendAccount->getUserId());

    query.bindValue(":friendId",owner->getUserId());

    if(owner->getType()==AccountType::QQ){
        query.bindValue(":type","QQ");
    }else if(owner->getType()==AccountType::WECHAT){
        query.bindValue(":type","WECHAT");
    }else{
        query.bindValue(":type","WEIBO");
    }

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return;
    }
}

void userDaoLzy::rejectFriendRequest(AccountLzy* owner,AccountLzy* friendAccount){
    //更改好友申请表
    query.prepare("delete from friend_request where account_id=:friendAccount;");

    query.bindValue(":friendAccount",friendAccount->getAccountId());

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return;
    }
}

QSqlQuery userDaoLzy::searchContacts(const QString& accountId){
    QSqlQuery query;

    qDebug()<<accountId;
    AccountLzy* account=userDao->returnAccount(accountId);

    query.prepare("select * from friendship where user_id=:user_Id;");
    query.bindValue(":user_Id",account->getUserId());
    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return query;
    }

    return query;
}

AccountLzy* userDaoLzy::returnAccountByUserId(int userId,const QString& type){
    query.prepare("select * from account where user_id=:userId and type=:type;");

    query.bindValue(":userId",userId);
    query.bindValue(":type",type);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
    }

    if (!query.next()) {
        qWarning() << "No records found";
        return nullptr;
    }

    AccountLzy* account=nullptr;
    if(type=="QQ"){
        account=new AccountLzy(query.value(0).toString(),userId,AccountType::QQ,query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
    }else if(type=="WECHAT"){
        account=new AccountLzy(query.value(0).toString(),userId,AccountType::WECHAT,query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
    }else{
        account=new AccountLzy(query.value(0).toString(),userId,AccountType::WEIBO,query.value(3).toString(),query.value(4).toString(),query.value(5).toString());
    }

    return account;

}


bool userDaoLzy::createGroup(int groupId,QString groupName,QString type,int ownerId,const QDateTime& currentTime){
    query.prepare("insert into user_group (group_id,name,type,owner_id,create_time) values (:groupId,:groupName,:type,:ownerId,:createTime);");

    qDebug()<<groupId<<groupName<<type<<ownerId<<currentTime;

    query.bindValue(":groupId",groupId);
    query.bindValue(":groupName",groupName);
    query.bindValue(":type",type);
    query.bindValue(":ownerId",ownerId);
    query.bindValue(":createTime",currentTime.toString("yyyy-MM-dd hh:mm:ss"));

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlQuery userDaoLzy::searchGroups(const QString& accountId){
    QSqlQuery query;
    query.prepare("select * from group_member where user_id=:userId");

    UserLzy* user=userDao->returnUser(accountId);
    query.bindValue(":userId",user->getUserId());

    delete user;

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
    }

    return query;
}

GroupLzy* userDaoLzy::getGroup(int groupId){
    query.prepare("select * from user_group where group_id=:groupId");
    query.bindValue(":groupId",groupId);

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return nullptr;
    }

    if (!query.next()) {
        qWarning() << "No records found";
        return nullptr;
    }

    QString groupName=query.value(1).toString();
    int ownerId=query.value(3).toInt();
    QString createTime=query.value(2).toString();

    if(query.value(2).toString()=="QQ"){
        return new GroupLzy(groupId,GroupType::QQ,groupName,ownerId);
    }else{
        return new GroupLzy(groupId,GroupType::WECHAT,groupName,ownerId);
    }

}

void userDaoLzy::addGroupMember(GroupLzy* group,UserLzy* user,int role){
    query.prepare("insert into group_member (group_id,user_id,role) values (:groupId,:userId,:role);");

    query.bindValue(":groupId",group->getGroupId());
    query.bindValue(":userId",user->getUserId());
    if(role==0) query.bindValue(":role","OWNER");
    else if(role==1) query.bindValue(":role","ADMIN");
    else query.bindValue(":role","MEMBER");

    if (!query.exec()) {
        qWarning() << "add group member failed:" << query.lastError().text();
        return;
    }
}

bool userDaoLzy::isMember(GroupLzy* group,UserLzy* user){
    query.prepare("select * from group_member where group_id=:groupId and user_id=:userId;");

    query.bindValue(":groupId",group->getGroupId());
    query.bindValue(":userId",user->getUserId());

    if (!query.exec()) {
        qWarning() << "SQL query execution failed:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qWarning() << "No records found";
        return false;
    }

    return true;
}

void userDaoLzy::updateUserService(int userId,QString type){
    query.prepare("insert into user_service (user_id,type,status,create_time) values (:userId,:type,:status,:createTime);");

    query.bindValue(":userId",userId);
    query.bindValue(":type",type);
    query.bindValue(":status",1);
    query.bindValue(":createTime",QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    if (!query.exec()) {
        qWarning() << "update user_service failed:" << query.lastError().text();
        return;
    }
}

QString userDaoLzy::getRole(GroupLzy* group, AccountLzy* acc) {
    QSqlQuery query;
    query.prepare("SELECT group_id, user_id, role FROM group_member WHERE group_id=:groupId AND user_id=:userId");
    query.bindValue(":groupId", group->getGroupId());
    query.bindValue(":userId", userDao->returnUser(acc->getAccountId())->getUserId());

    if (!query.exec()) {
        qWarning() << "getRole failed. SQL error:" << query.lastError().text();
        return "";
    }

    if (!query.next()) {
        qWarning() << "No matching record found for group_id:" << group->getGroupId()
        << "and user_id:" << userDao->returnUser(acc->getAccountId())->getUserId();
        return "";
    }

    QSqlRecord rec = query.record();
    qDebug() << "Query fields:" << rec.fieldName(0) << rec.fieldName(1) << rec.fieldName(2);

    QString role = query.value(2).toString();
    qDebug() << "group_id:" << query.value(0).toInt()
             << "user_id:" << query.value(1).toInt()
             << "role:" << role;

    return role;
}

void userDaoLzy::changeAdmin(int userId,Mode mode){
    query.prepare("update group_member set role=:role where user_id=:userId");

    query.bindValue(":userId",userId);
    QString role;
    if(mode==Mode::ADDADMIN){
        role="ADMIN";
    }else if(mode==Mode::REMOVEADMIN){
        role="MEMBER";
    }

    query.bindValue(":role",role);

    if (!query.exec()) {
        qWarning() << "changeAdmin failed. SQL error:" << query.lastError().text();
        return;
    }
}

bool userDaoLzy::removeMember(GroupLzy* group,int userId){
    query.prepare("delete from group_member where group_id=:groupId and user_id=:userId");
    query.bindValue(":groupId", group->getGroupId());
    query.bindValue(":userId", userId);

    if (!query.exec()) {
        qWarning() << "removeMember failed. SQL error:" << query.lastError().text();
        return false;
    }

    return true;
}

bool userDaoLzy::ifMemberExists(GroupLzy* group,AccountLzy* account){
    QSqlQuery query;
    query.prepare("select * from group_member where group_id=:groupId and user_id=:userId;");
    query.bindValue(":groupId",group->getGroupId());
    query.bindValue(":userId",userDao->returnUser(account->getAccountId())->getUserId());

    if (!query.exec()) {
        qWarning() << "search for member failed. SQL error:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        if(query.value(1).toInt()!=userDao->returnUser(account->getAccountId())->getUserId()){
            qWarning() << "No matching member";
            return false;
        }
    }

    return true;
}

QString userDaoLzy::getAccountByUserId(int userId,QString type){
    QSqlQuery query;
    query.prepare("select * from account where user_id=:userId and type=:type");

    query.bindValue(":userId",userId);
    query.bindValue(":type",type);

    if (!query.exec()) {
        qWarning() << "search for account failed. SQL error:" << query.lastError().text();
        return "";
    }

    if (!query.next()) {
        qDebug()<<"user has no such account";
        return "";
    }

    return query.value(0).toString();
}

QSqlQuery userDaoLzy::getAccountsByUser(UserLzy* user){
    QSqlQuery query;
    query.prepare("select * from user_service where user_id=:userId");

    query.bindValue(":userId",user->getUserId());

    if (!query.exec()) {
        qWarning() << "get accounts failed. SQL error:" << query.lastError().text();
        return query;
    }

    return query;
}

bool userDaoLzy::ifBinding(QString accId1,QString accId2){
    QSqlQuery query;
    query.prepare("select * from account_binding where account_id_1=:accId1 and account_id_2=:accId2");

    query.bindValue(":accId1",accId1);
    query.bindValue(":accId2",accId2);

    if (!query.exec()) {
        qWarning() << "get binding relationship failed. SQL error:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug()<<"not bound yet";
        return false;
    }

    return true;
}

bool userDaoLzy::bindAccounts(int userId, const QString &accountId1, const QString &accountId2) {

    QSqlQuery query;

    query.prepare(
        "insert into account_binding (user_id, account_id_1, account_id_2, create_time) values (:user_id, :account_id_1, :account_id_2, :create_time)"
        );

    query.bindValue(":user_id", userId);
    query.bindValue(":account_id_1", accountId1);
    query.bindValue(":account_id_2", accountId2);
    query.bindValue(":create_time", QDateTime::currentDateTime());

    if (!query.exec()) {
        qWarning() << "failed to bind accounts:" << query.lastError().text();
        return false;
    }

    qDebug() << "successfully bound accounts:" << accountId1 << "and" << accountId2;
    return true;
}

bool userDaoLzy::unbindAccounts(int userId, const QString &accountId1, const QString &accountId2) {
    QSqlQuery query;


    query.prepare(
        "DELETE FROM account_binding WHERE user_id = :user_id AND account_id_1 = :account_id_1 AND account_id_2 = :account_id_2"
        );

    query.bindValue(":user_id", userId);
    query.bindValue(":account_id_1", accountId1);
    query.bindValue(":account_id_2", accountId2);


    if (!query.exec()) {
        qWarning() << "Failed to unbind accounts:" << query.lastError().text();
        return false;
    }

    qDebug() << "Successfully unbound accounts:" << accountId1 << "and" << accountId2;
    return true;
}

QString userDaoLzy::getBoundAccount(const QString& accountId, const QString& type) {
    QSqlQuery query;
    query.prepare("SELECT account_id_1, account_id_2 FROM account_binding WHERE account_id_1 = :account_id OR account_id_2 = :account_id");
    query.bindValue(":account_id", accountId);

    if (!query.exec()) {
        qWarning() << "Failed to execute query on account_binding:" << query.lastError().text();
        return "";
    }

    while (query.next()) {
        QString boundAccount1 = query.value("account_id_1").toString();
        QString boundAccount2 = query.value("account_id_2").toString();

        if (boundAccount1 == accountId) {
            QString accountType = getAccountType(boundAccount2);
            if (accountType == type) {
                return boundAccount2;
            }
        }
        if (boundAccount2 == accountId) {
            QString accountType = getAccountType(boundAccount1);
            if (accountType == type) {
                return boundAccount1;
            }
        }
    }

    return "";
}

QString userDaoLzy::getAccountType(const QString& accountId) {
    QSqlQuery query;
    query.prepare("SELECT type FROM account WHERE account_id = :account_id");
    query.bindValue(":account_id", accountId);

    if (!query.exec()) {
        qWarning() << "Failed to execute query on account table:" << query.lastError().text();
        return "";
    }

    if (query.next()) {
        return query.value("type").toString();
    }

    return "";
}

QSqlQuery userDaoLzy::getMembers(int groupId){
    QSqlQuery query;
    query.prepare("select * from group_member where group_id=:groupId");
    query.bindValue(":groupId",groupId);

    if (!query.exec()) {
        qWarning() << "Failed to get members:" << query.lastError().text();
        return query;
    }

    return query;
}

void userDaoLzy::dissolveGroup(int groupId){
    QSqlQuery query;
    query.prepare("delete from user_group where group_id=:groupId");
    query.bindValue(":groupId",groupId);

    if (!query.exec()) {
        qWarning() << "Failed to dissolve group:" << query.lastError().text();
    }

}
