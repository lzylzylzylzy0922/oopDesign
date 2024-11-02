#ifndef UTILSLZY_H
#define UTILSLZY_H

#include <QObject>
#include<QString>
#include<QRegularExpression>

class utilsLzy : public QObject
{
    Q_OBJECT
public:
    static utilsLzy* getInstance();//获得单例对象
    bool validatePassword(QString text);//判断输入密码是否合法
private:
    explicit utilsLzy(QObject *parent = nullptr);
    ~utilsLzy(){};
    static utilsLzy *utils;
signals:
};

#endif // UTILSLZY_H
