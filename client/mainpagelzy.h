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

public slots:
    void recvSignal(QString AccountId);

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::MainPageLzy *ui;
    static AccountLzy* account;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    QTcpSocket* socket;
    void closeEvent(QCloseEvent* event) override;
};

#endif // MAINPAGELZY_H
