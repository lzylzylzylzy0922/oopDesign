#include "utilsLzy.h"

// 静态变量初始化
utilsLzy* utilsLzy::utils = nullptr;

utilsLzy::utilsLzy(QObject *parent)
    : QObject{parent}
{}

utilsLzy* utilsLzy::getInstance(){
    if (utils == nullptr) {
        utils = new utilsLzy();  // 如果实例为空，创建新实例
    }
    return utils;
}

bool utilsLzy::validatePassword(QString text){
    QRegularExpression passwordRegex("^(?=.*[a-zA-Z])(?=.*\\d)[A-Za-z\\d]{6,}");
    QRegularExpressionMatch match = passwordRegex.match(text);
    return match.hasMatch();
}

bool utilsLzy::validatePhoneNumber(QString number){
    if (number.length() != 11 || number[0] != '1') {
        return false;
    }

    for (int i = 1; i < 11; i++) {
        if (number[i] < '0' || number[i] > '9')
            return false;
    }

    return true;
}

QString utilsLzy::createAccountId(AccountType type){
    QString accountId;
    if (type == AccountType::QQ || type == AccountType::WEIBO) {
        qid=QRandomGenerator::global()->bounded(1000000);
        accountId = "q" + QString::number(qid);  // 用qid生成账户ID
        qDebug()<<qid;
    } else {
        wid=QRandomGenerator::global()->bounded(1000000);
        accountId = "w" + QString::number(wid);  // 用wid生成账户ID
        qDebug()<<wid;
    }

    return accountId;
}

QJsonDocument utilsLzy::toJsonDoc(QString type,QString accountId,QString friendAccountId){
    QJsonObject request;
    request["type"]=type;
    request["account_id"]=accountId;
    request["friend_account_id"]=friendAccountId;

    QJsonDocument doc(request);

    return doc;
}

QJsonDocument utilsLzy::toJsonDoc(QString type,QString accountId){
    QJsonObject request;
    request["type"]=type;
    request["account_id"]=accountId;
    QJsonDocument doc(request);

    return doc;
}

QString utilsLzy::getType(AccountLzy* account){
    if(account->getType()==AccountType::QQ){
        return "QQ";
    }else if(account->getType()==AccountType::WECHAT){
        return "WECHAT";
    }else{
        return "WEIBO";
    }
}

