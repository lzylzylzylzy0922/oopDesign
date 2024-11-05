//工具类

#ifndef UTILSLZY_H
#define UTILSLZY_H

#include <QObject>
#include<QString>
#include<QRegularExpression>
#include"AccountType.h"

class utilsLzy : public QObject
{
    Q_OBJECT
public:
    static utilsLzy* getInstance();//获得单例对象
    bool validatePassword(QString text);//判断输入密码是否合法
    bool validatePhoneNumber(QString number);//判断输入手机号是否合法
    QString createAccountId(AccountType type);//返回一个系统生成的账号

private:
    explicit utilsLzy(QObject *parent = nullptr);
    ~utilsLzy(){};
    static utilsLzy *utils;
    static int qid;
    static int wid;
signals:
};

#endif // UTILSLZY_H
