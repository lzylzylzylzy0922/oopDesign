#include "databaseconnectionlzy.h"

QSqlDatabase databaseConnectionLzy::database;


databaseConnectionLzy::databaseConnectionLzy(QObject *parent)
    : QObject{parent}
{
}

QSqlDatabase databaseConnectionLzy::getInstance(){
    if(!database.isOpen()){
        database=QSqlDatabase::addDatabase("QMYSQL");
        database.setDatabaseName("dev");
        database.setHostName("127.0.0.1");
        database.setUserName("root");
        database.setPassword("197830LZy,");
    }

    if(database.open()){
        qDebug()<<"数据库连接成功";
    }else{
        qDebug()<<"数据库连接失败";
    }

    return database;
}
