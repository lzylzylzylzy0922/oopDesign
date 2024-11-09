#ifndef REGISTERPAGELZY_H
#define REGISTERPAGELZY_H

#include <QWidget>
#include <AccountLzy.h>
#include<userdaolzy.h>
#include"utilsLzy.h"
#include <QMessageBox>
#include<QDebug>
#include<QDate>
#include<QSqlDatabase>
#include<QSqlQuery>

namespace Ui {
class RegisterPageLzy;
}

class RegisterPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPageLzy(QWidget *parent = nullptr);
    ~RegisterPageLzy();
    friend class utilsLzy;
    friend class userDaoLzy;

signals:
    void showWelcomePage();
public slots:
    void recvSignal();
    void updateEchoMode();

private slots:
    void on_registerButton_clicked();


    void on_openWelcomePageButton_clicked();

private:
    Ui::RegisterPageLzy *ui;


};

#endif // REGISTERPAGELZY_H
