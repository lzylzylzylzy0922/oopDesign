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
    explicit InfoFormPageLzy(AccountLzy* account,QString acid,QWidget *parent = nullptr);
    ~InfoFormPageLzy();

private:
    Ui::InfoFormPageLzy *ui;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    AccountLzy* account;

};

#endif // INFOFORMPAGELZY_H
