#ifndef SEARCHPAGELZY_H
#define SEARCHPAGELZY_H

#include <QWidget>
#include <AccountLzy.h>
#include<userdaolzy.h>
#include <QMessageBox>
#include<utilsLzy.h>
#include<QDebug>
#include<QDate>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<infoitemframelzy.h>
#include<QList>
#include<QVBoxLayout>
#include<infoformpagelzy.h>

namespace Ui {
class SearchPageLzy;
}

class SearchPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit SearchPageLzy(QWidget *parent = nullptr);
    ~SearchPageLzy();

    friend class utilsLzy;
    friend class userDaoLzy;

public slots:
    void recvSignal(AccountLzy* account);

private slots:
    void on_searchButton_clicked();
    void onInfoItemClicked(AccountLzy* account,const QString& accountId);//第一个参数：自己，第二个参数：别人
private:
    Ui::SearchPageLzy *ui;
    static AccountLzy* account;
    QList<QString> users;
    QList<infoItemFrameLzy*> groups;

    void initUserScrollArea();
    void initGroupScrollArea();
    void searchUsers(QString text);
    void searchGroups(QString text);

};

#endif // SEARCHPAGELZY_H
