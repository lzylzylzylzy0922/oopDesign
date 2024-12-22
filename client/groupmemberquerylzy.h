#ifndef GROUPMEMBERQUERYLZY_H
#define GROUPMEMBERQUERYLZY_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QCheckBox>
#include<QJsonArray>
#include<QTcpSocket>
#include<tcpconnectionmanager.h>
#include<userdaolzy.h>
#include<QJsonObject>
#include<QAbstractItemModel>
#include<Mode.h>
#include<QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupMemberQueryLzy; }
QT_END_NAMESPACE

class GroupMemberQueryLzy : public QWidget
{
    Q_OBJECT

public:
    explicit GroupMemberQueryLzy(QWidget *parent = nullptr);
    ~GroupMemberQueryLzy();

    void addCheckBox();
    void tackleMember();

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void recvSignal(int groupId);
    void addAdmin();
    void removeAdmin();
    void removeGroupMembers();

private:
    Ui::GroupMemberQueryLzy *ui;
    int groupIdToQuery;
    void queryGroupMembers();

    QJsonArray selectedUsers;
};

#endif // GROUPMEMBERQUERYLZY_H
