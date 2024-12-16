#ifndef MAINPAGELZY_H
#define MAINPAGELZY_H

#include <QWidget>
#include<AccountLzy.h>
#include<userdaolzy.h>
#include<UserLzy.h>
#include<QString>
#include<QCloseEvent>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>
#include<infoitemframelzy.h>
#include<QVBoxLayout>
#include<infoformpagelzy.h>
#include<tcpconnectionmanager.h>
#include<QThread>
#include<utilsLzy.h>
#include<groupitemframelzy.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8000


namespace Ui {
class MainPageLzy;
}

class MainPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit MainPageLzy(QWidget *parent = nullptr);
    ~MainPageLzy();
signals:
    void showSearchPageLzy(AccountLzy* acoount);
    void showCreateGroupPageLzy(AccountLzy* account);

public slots:
    void recvSignal(QString AccountId);
    void updateByCreateGroupPageLzy(GroupLzy* group,int type);//0入群,1退群

private slots:
    void on_comboBox_activated(int index);
    void onInfoItemClicked(AccountLzy* account,AccountLzy* friendAccount);
    void onGroupItemClicked(GroupLzy* group);
    void OnReadyRead();//处理server发送的信息
    void updateByInfoFormPageLzy(AccountLzy* searchAccount,TackleFriendRequest tfs);

private:
    Ui::MainPageLzy *ui;
    static AccountLzy* account;//自己
    userDaoLzy* userDao=userDaoLzy::getInstance();
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();

    void initRequestTab(const QString& accountId);
    void initContactsTab(const QString& accountId);
    void initGroupTab(const QString& accountId);
    void updateRequestTab(AccountLzy* account);
    void closeEvent(QCloseEvent* event) override;
};

#endif // MAINPAGELZY_H
