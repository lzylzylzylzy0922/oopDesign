#ifndef GROUPFORMPAGELZY_H
#define GROUPFORMPAGELZY_H

#include <QWidget>
#include<GroupLzy.h>
#include<AccountLzy.h>
#include<AccountType.h>

namespace Ui {
class GroupFormPageLzy;
}

class GroupFormPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit GroupFormPageLzy(GroupLzy* grp,AccountLzy* acc,QWidget *parent = nullptr);
    ~GroupFormPageLzy();

private:
    Ui::GroupFormPageLzy *ui;
    GroupLzy* group;
    AccountLzy* account;
};

#endif // GROUPFORMPAGELZY_H
