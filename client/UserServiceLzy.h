//用户开通服务表：对应user_service表

#ifndef USERSERVICELZY_H
#define USERSERVICELZY_H

#include <QObject>
#include <QDateTime>

class UserLzy;

enum class AccountType { BASIC, PREMIUM };

class UserServiceLzy : public QObject {
    Q_OBJECT

private:
    UserLzy* user;
    AccountType type;
    bool status; // 1开通/0未开通
    QDateTime createTime;

public:
    UserServiceLzy(UserLzy* usr, AccountType acc_type, bool stat, const QDateTime& c_time, QObject *parent = nullptr)
        : QObject(parent), user(usr), type(acc_type), status(stat), createTime(c_time) {}

    // Getters
    UserLzy* getUser() const { return user; }
    AccountType getType() const { return type; }
    bool getStatus() const { return status; }
    QDateTime getCreateTime() const { return createTime; }

    // Setters
    void setUser(UserLzy* usr) { user = usr; }
    void setType(AccountType acc_type) { type = acc_type; }
    void setStatus(bool stat) { status = stat; }
    void setCreateTime(const QDateTime& c_time) { createTime = c_time; }
};

#endif // USERSERVICELZY_H
