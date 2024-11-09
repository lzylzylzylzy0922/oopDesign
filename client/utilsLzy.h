//工具类

#ifndef UTILSLZY_H
#define UTILSLZY_H

#include <QObject>
#include <QString>
#include <QRegularExpression>
#include "AccountType.h"
#include<QRandomGenerator>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTcpServer>

class utilsLzy : public QObject
{
    Q_OBJECT
public:
    static utilsLzy* getInstance(); // 获取单例对象
    bool validatePassword(QString text); // 判断输入密码是否合法
    bool validatePhoneNumber(QString number); // 判断输入手机号是否合法
    QString createAccountId(AccountType type); // 返回一个系统生成的账号

    static QString getLocalIPAddress()          // 获取当前程序运行的IPv4地址
    {
        QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
        for (const QHostAddress &address : addresses) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback()) {
                return address.toString();
            }
        }
        return "127.0.0.1";
    }

    static quint16 getPort(QTcpServer *server)    // 获取当前程序的端口号（与 QTcpServer 配合使用）
    {
        if (server && server->isListening()) {
            return server->serverPort();
        }
        return 0;  // 如果服务器未启动，则返回0
    }

private:
    explicit utilsLzy(QObject *parent = nullptr);
    ~utilsLzy() {};
    static utilsLzy *utils;  // 单例对象
    int qid;  // QQ账户的编号
    int wid;  // 微信/微博账户的编号

signals:
};

#endif // UTILSLZY_H
