//账户绑定类：绑定不同应用之间账户的ID，对应account_binding表

#ifndef ACCOUNTBINDINGLZY_H
#define ACCOUNTBINDINGLZY_H

#include <QObject>
#include <QDateTime>
#include<QString>

class UserLzy;

class AccountBindingLzy : public QObject {
    Q_OBJECT

private:
    UserLzy* user;
    QString accountId1;
    QString accountId2;
    QDateTime createTime;

public:
    AccountBindingLzy(UserLzy* usr, const QString& acc_id1, const QString& acc_id2, const QDateTime& c_time, QObject *parent = nullptr)
        : QObject(parent), user(usr), accountId1(acc_id1), accountId2(acc_id2), createTime(c_time) {}

    UserLzy* getUserId() const { return user; }
    QString getAccountId1() const { return accountId1; }
    QString getAccountId2() const { return accountId2; }
    QDateTime getCreateTime() const { return createTime; }

    void setUserId(UserLzy* usr) { user=usr; }
    void setAccountId1(const QString& acc_id1) { accountId1 = acc_id1; }
    void setAccountId2(const QString& acc_id2) { accountId2 = acc_id2; }
    void setCreateTime(const QDateTime& c_time) { createTime = c_time; }
};

#endif // ACCOUNTBINDINGLZY_H
