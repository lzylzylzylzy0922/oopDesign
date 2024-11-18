#ifndef INFOFORMPAGELZY_H
#define INFOFORMPAGELZY_H

#include <QWidget>
#include<QVBoxLayout>
#include<infoitemframelzy.h>
#include<userdaolzy.h>

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

private:
    Ui::InfoFormPageLzy *ui;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    AccountLzy* account;//自己
    AccountLzy* searchAccount;

};

#endif // INFOFORMPAGELZY_H
