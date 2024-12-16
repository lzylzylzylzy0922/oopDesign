#ifndef SEARCHFORCONTACTSLZY_H
#define SEARCHFORCONTACTSLZY_H

#include <QWidget>
#include<AccountLzy.h>
#include<userdaolzy.h>
#include<QSqlQuery>
#include<QCheckBox>
#include<QJsonArray>
#include<QJsonObject>
#include<tcpconnectionmanager.h>
#include<QTcpSocket>

namespace Ui {
class SearchForContactsLzy;
}

class SearchForContactsLzy : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForContactsLzy(QWidget *parent = nullptr);
    ~SearchForContactsLzy();

private:
    Ui::SearchForContactsLzy *ui;
    QJsonArray selectedUsers;
    int groupId;

    friend userDaoLzy;

public slots:
    void recvSignal(AccountLzy* account,int groupId);
private slots:
    void on_pushButton_clicked();
};

#endif // SEARCHFORCONTACTSLZY_H
