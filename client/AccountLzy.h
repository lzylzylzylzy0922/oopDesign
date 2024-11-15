//账户类：对应account表

#ifndef ACCOUNTLZY_H
#define ACCOUNTLZY_H

#include <QString>
#include <QObject>
#include"AccountType.h"


class AccountLzy : public QObject {
    Q_OBJECT

private:
    QString accountId;
    int userId;
    AccountType type;
    QString accountName;
    QString password;
    QString avatar;

public:
    AccountLzy(const QString& acc_id, int uid,AccountType acc_type, const QString& acc_name, const QString& pwd, const QString& avt,QObject *parent = nullptr)
        : QObject(parent), accountId(acc_id), userId(uid), type(acc_type), accountName(acc_name), password(pwd),avatar(avt) {}

    QString getAccountId() const { return accountId; }
    int getUserId() const { return userId; }
    AccountType getType() const { return type; }
    QString getAccountName() const { return accountName; }
    QString getPassword() const { return password; }
    QString getAvatar() const { return avatar; }

    void setAccountId(const QString& acc_id) { accountId = acc_id; }
    void setUserId(int user_id) { userId = user_id; }
    void setType(AccountType acc_type) { type = acc_type; }
    void setAccountName(const QString& acc_name) { accountName = acc_name; }
    void setPassword(const QString& pwd) { password = pwd; }
    void setAvatar(const QString& avt) { avatar=avt; }
};

#endif // ACCOUNTLZY_H
