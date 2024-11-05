//登录状态类：管理用户在线/离线，对应login_status表

#ifndef LOGINSTATUSLZY_H
#define LOGINSTATUSLZY_H

#include <QObject>
#include <QDateTime>
#include"AccountType.h"

class UserLzy;

class LoginStatusLzy : public QObject {
    Q_OBJECT

private:
    UserLzy* user; // 用户
    AccountType type;
    QDateTime loginTime;
    bool isActive;
    QString ip;
    int port;

public:
    LoginStatusLzy(UserLzy* usr, AccountType acc_type, const QDateTime& log_time, bool active, const QString& ip_addr, int port_num, QObject *parent = nullptr)
        : QObject(parent), user(usr), type(acc_type), loginTime(log_time), isActive(active), ip(ip_addr), port(port_num) {}

    // Getters
    UserLzy* getUser() const { return user; }
    AccountType getType() const { return type; }
    QDateTime getLoginTime() const { return loginTime; }
    bool getIsActive() const { return isActive; }
    QString getIp() const { return ip; }
    int getPort() const { return port; }

    // Setters
    void setUser(UserLzy* usr) { user = usr; }
    void setType(AccountType acc_type) { type = acc_type; }
    void setLoginTime(const QDateTime& log_time) { loginTime = log_time; }
    void setIsActive(bool active) { isActive = active; }
    void setIp(const QString& ip_addr) { ip = ip_addr; }
    void setPort(int port_num) { port = port_num; }
};

#endif // LOGINSTATUSLZY_H
