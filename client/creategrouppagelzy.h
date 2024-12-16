#ifndef CREATEGROUPPAGELZY_H
#define CREATEGROUPPAGELZY_H

#include <QWidget>
#include<AccountLzy.h>
#include<userdaolzy.h>
#include<QFileDialog>
#include<QDateTime>

namespace Ui {
class CreateGroupPageLzy;
}

class CreateGroupPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroupPageLzy(QWidget *parent = nullptr);
    ~CreateGroupPageLzy();

private:
    Ui::CreateGroupPageLzy *ui;
    static AccountLzy* account;
    QString avatarPath;
    int groupId;
    userDaoLzy* userDao=userDaoLzy::getInstance();

signals:
    void showSearchForContactsLzy(AccountLzy* account,int groupId);

public slots:
    void recvSignal(AccountLzy* account);
private slots:
    void on_uploadAvatarButton_clicked();
    void on_invitFriendButton_clicked();
    void on_createGroupButton_clicked();

signals:
    void updateMainPageLzy(GroupLzy* group,int type);//0入群，1退群
};

#endif // CREATEGROUPPAGELZY_H
