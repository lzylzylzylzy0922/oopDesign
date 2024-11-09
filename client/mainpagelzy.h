#ifndef MAINPAGELZY_H
#define MAINPAGELZY_H

#include <QWidget>
#include<AccountLzy.h>
#include<userdaolzy.h>
#include<UserLzy.h>
#include<QString>
#include<QCloseEvent>

namespace Ui {
class MainPageLzy;
}

class MainPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit MainPageLzy(QWidget *parent = nullptr);
    ~MainPageLzy();

public slots:
    void recvSignal(QString AccountId);

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::MainPageLzy *ui;
    static AccountLzy* account;
    userDaoLzy* userDao=userDaoLzy::getInstance();

    void closeEvent(QCloseEvent* event) override;
};

#endif // MAINPAGELZY_H
