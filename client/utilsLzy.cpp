#include "utilsLzy.h"

utilsLzy* utilsLzy::utils = nullptr;
int utilsLzy::qid=1000;
int utilsLzy::wid=1000;

utilsLzy::utilsLzy(QObject *parent)
    : QObject{parent}
{}

utilsLzy* utilsLzy::getInstance(){
    if(utils==nullptr)
        utils=new utilsLzy();
    return utils;
}

bool utilsLzy::validatePassword(QString text){
    QRegularExpression passwordRegex("^(?=.*[a-zA-Z])(?=.*\\d)[A-Za-z\\d]{6,}");

    QRegularExpressionMatch match=passwordRegex.match(text);
    if(match.hasMatch()){
        return true;
    }else{
        return false;
    }
}

bool utilsLzy::validatePhoneNumber(QString number){
    if(number.length()!=11||number[0]!='1'){
        return false;
    }

    for(int i=1;i<11;i++){
        if(number[i]<'0'&&number[i]>'9')
            return false;
    }

    return true;

}

QString utilsLzy::createAccountId(AccountType type){
    QString accountId;
    if(type==AccountType::QQ||type==AccountType::WEIBO){
        accountId="q"+QString::number(qid);
        qid++;
    }else{
        accountId="w"+QString::number(wid);
        wid++;
    }

    return accountId;
}
