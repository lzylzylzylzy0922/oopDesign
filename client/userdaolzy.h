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
#include<GroupLzy.h>
#include<QMessageBox>
#include <QSqlRecord>
#include<Mode.h>


class userDaoLzy : public QObject
{
    Q_OBJECT
public:
    static userDaoLzy* getInstance();//获得单例对象
    bool isUserExistsByAccountAndType(QString accountId,QString type);    //通过账号查找用户是否存在
    bool isPasswordCorrect(QString accountId,QString password);              //校验密码是否正确
    bool isUserExistsByPhoneAndType(QString phoneNumber,AccountType type);//通过手机号和应用类型判断账户是否存在
    bool createAccount(AccountLzy* account,QDate birth,QString location,QString telephone); //创建账户
    AccountLzy* returnAccount(const QString& AccountId);                        //通过账户id返回account实体指针
    UserLzy* returnUser(QString AccountId);                             //通过账号id返回user实体指针
    void updateOnlineStatus(AccountLzy* account,loginStatus status);     // 更新用户状态
    QSqlQuery searchUsersById(QString text);
    QSqlQuery searchGroupsById(int groupId);
    bool checkIfFriend(int userId1,int userId2,AccountType type);                                                  //查询双方是否为好友
    bool addFriend(AccountLzy* account,AccountLzy* friendAccount);//添加好友
    bool removeFriend(AccountLzy* account,AccountLzy* friendAccount);
    bool ifSentAddFriendRequest(AccountLzy* account,AccountLzy* friendAccount);//是否已经发送好友申请
    QSqlQuery searchRequest(const QString& accountId);
    QSqlQuery searchGroups(const QString& accountId);
    void agreeFriendRequest(AccountLzy* owner,AccountLzy* friendAccount);//同意好友申请
    void rejectFriendRequest(AccountLzy* owner,AccountLzy* friendAccount);
    QSqlQuery searchContacts(const QString& accountId);
    AccountLzy* returnAccountByUserId(int userId,const QString& type);
    bool createGroup(int groupId,QString groupName,QString type,int ownerId,const QDateTime& currentTime);
    GroupLzy* getGroup(int groupId);
    void addGroupMember(GroupLzy* group,UserLzy* user,int role);//0群主，1管理员，2普通成员
    bool isMember(GroupLzy* group,UserLzy* user);
    void updateUserService(int userId,QString type);
    QString getRole(GroupLzy* group,AccountLzy* acc);
    void changeAdmin(int userId,Mode mode);
    bool removeMember(GroupLzy* group,int userId);
    bool ifMemberExists(GroupLzy* group,AccountLzy* account);
    QString getAccountByUserId(int userId,QString type);
    QSqlQuery getAccountsByUser(UserLzy* user);
    bool ifBinding(QString accId1,QString accId2);
    bool bindAccounts(int userId, const QString &accountId1, const QString &accountId2);
    bool unbindAccounts(int userId, const QString &accountId1, const QString &accountId2);
    QString getBoundAccount(const QString& accountId, const QString& type);
    QString getAccountType(const QString& accountId);
    QSqlQuery getMembers(int groupId);
    void dissolveGroup(int groupId);

private:
    explicit userDaoLzy(QObject *parent = nullptr);
    static userDaoLzy* userDao;
    QSqlDatabase database=databaseConnectionLzy::getInstance();
    QSqlQuery query;
signals:
};

#endif // USERDAOLZY_H
