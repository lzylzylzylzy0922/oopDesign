#ifndef GROUPFORMPAGELZY_H
#define GROUPFORMPAGELZY_H

#include <QWidget>
#include<GroupLzy.h>
#include<AccountLzy.h>
#include<QVBoxLayout>
#include<groupitemframelzy.h>
#include<groupmemberquerylzy.h>
#include<userdaolzy.h>
#include<UserLzy.h>
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

private slots:
    void on_searchMemberButton_clicked();

    void on_tackleAdminButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::GroupFormPageLzy *ui;
    GroupLzy* group;
    AccountLzy* account;

signals:
    void showGroupMemberQuery(int groupId);
};

#endif // GROUPFORMPAGELZY_H
