#ifndef INFOFORMPAGELZY_H
#define INFOFORMPAGELZY_H

#include <QWidget>
#include<QVBoxLayout>
#include<infoitemframelzy.h>
#include<userdaolzy.h>
#include<utilsLzy.h>
#include<QJsonDocument>
#include<QJsonObject>
#include<QTcpSocket>
#include<tcpconnectionmanager.h>

enum class TackleFriendRequest{AGREE,REJECT};

namespace Ui {
class InfoFormPageLzy;
}

class InfoFormPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit InfoFormPageLzy(AccountLzy* account,AccountLzy* searchAccount,QWidget *parent = nullptr);
    ~InfoFormPageLzy();

private slots:
    void on_addFriendButton_clicked();

    void on_agreeButton_clicked();

private:
    Ui::InfoFormPageLzy *ui;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    utilsLzy* utils=utilsLzy::getInstance();
    AccountLzy* account;//自己
    AccountLzy* searchAccount;
signals:
    void updateMainPageLzy(AccountLzy* searchAccount,TackleFriendRequest tfr);
};

#endif // INFOFORMPAGELZY_H
