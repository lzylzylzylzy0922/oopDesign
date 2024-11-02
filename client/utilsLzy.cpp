#include "utilsLzy.h"

utilsLzy* utilsLzy::utils = nullptr;

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
