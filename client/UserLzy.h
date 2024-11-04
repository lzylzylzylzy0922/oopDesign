//用户类：管理用户，对应user表

#ifndef USERLZY_H
#define USERLZY_H

#include <QString>
#include <QDateTime>
#include <QDate>
#include <QObject>
#include <QList>

enum class Location { LOCATION_A, LOCATION_B };

class AccountLzy;

class UserLzy : public QObject {
    Q_OBJECT

private:
    int user_id;
    QDate birthday;
    QDateTime register_date;
    Location location;
    QString avatar;
    QString phone_number;
    QList<AccountLzy*> accounts;

public:
    UserLzy(int id, const QDate& bday, const QDateTime& reg_date, Location loc, const QString& avtr, const QString& phone, QObject *parent = nullptr)
        : QObject(parent), user_id(id), birthday(bday), register_date(reg_date), location(loc), avatar(avtr), phone_number(phone) {}


    int getUserId() const { return user_id; }
    QDate getBirthday() const { return birthday; }
    QDateTime getRegisterDate() const { return register_date; }
    Location getLocation() const { return location; }
    QString getAvatar() const { return avatar; }
    QString getPhoneNumber() const { return phone_number; }

    void setUserId(int id) { user_id = id; }
    void setBirthday(const QDate& bday) { birthday = bday; }
    void setRegisterDate(const QDateTime& reg_date) { register_date = reg_date; }
    void setLocation(Location loc) { location = loc; }
    void setAvatar(const QString& avtr) { avatar = avtr; }
    void setPhoneNumber(const QString& phone) { phone_number = phone; }

    // 添加账户
    void addAccount(AccountLzy* account) {
        accounts.append(account);
    }

    QList<AccountLzy*> getAccounts() const {
        return accounts;
    }
};

#endif // USERLZY_H
