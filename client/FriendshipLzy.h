//好友类：管理好友关系，对应friendship表

#ifndef FRIENDSHIPLZY_H
#define FRIENDSHIPLZY_H

#include <QObject>
#include"AccountType.h"

class UserLzy;

class FriendshipLzy : public QObject {
    Q_OBJECT

private:
    UserLzy* user; //用户
    UserLzy* friendUser; //好友对象
    AccountType type;

public:
    FriendshipLzy(UserLzy* usr, UserLzy* f_usr, AccountType f_type, QObject *parent = nullptr)
        : QObject(parent), user(usr), friendUser(f_usr), type(f_type) {}

    UserLzy* getUser() const { return user; }
    UserLzy* getFriend() const { return friendUser; }
    AccountType getType() const { return type; }

    void setUserId(UserLzy* usr) { user = usr; }
    void setFriendId(UserLzy* fd) { friendUser = fd; }
    void setType(AccountType f_type) { type = f_type; }
};

#endif // FRIENDSHIPLZY_H
