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
    int userId;
    QDate birthday;
    QDateTime registerDate;
    Location location;
    QString avatar;
    QString phoneNumber;
    QList<AccountLzy*> accounts;

public:
    UserLzy(const QDate& bday, const QDateTime& reg_date, Location loc, const QString& avtr, const QString& phone, QObject *parent = nullptr)
        : QObject(parent), birthday(bday), registerDate(reg_date), location(loc), avatar(avtr), phoneNumber(phone) {}


    int getUserId() const { return userId; }
    QDate getBirthday() const { return birthday; }
    QDateTime getRegisterDate() const { return registerDate; }
    Location getLocation() const { return location; }
    QString getAvatar() const { return avatar; }
    QString getPhoneNumber() const { return phoneNumber; }

    void setUserId(int id) { userId = id; }
    void setBirthday(const QDate& bday) { birthday = bday; }
    void setRegisterDate(const QDateTime& reg_date) { registerDate = reg_date; }
    void setLocation(Location loc) { location = loc; }
    void setAvatar(const QString& avtr) { avatar = avtr; }
    void setPhoneNumber(const QString& phone) { phoneNumber = phone; }

    // 添加账户
    void addAccount(AccountLzy* account) {
        accounts.append(account);
    }

    QList<AccountLzy*> getAccounts() const {
        return accounts;
    }
};

#endif // USERLZY_H
