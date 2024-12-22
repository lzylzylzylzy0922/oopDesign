#ifndef ACCOUNTBINDINGPAGELZY_H
#define ACCOUNTBINDINGPAGELZY_H

#include <QWidget>
#include<AccountLzy.h>
#include<userdaolzy.h>
#include<QCheckBox>
#include<QPair>
#include<QVector>

namespace Ui {
class AccountBindingPageLzy;
}

class AccountBindingPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit AccountBindingPageLzy(QWidget *parent = nullptr);
    ~AccountBindingPageLzy();

private:
    Ui::AccountBindingPageLzy *ui;
    AccountLzy* account;
    QVector<QPair<QString,QString>> selectedAccounts;

public slots:
    void recvSignal(AccountLzy* account);
private slots:
    void on_pushButton_clicked();
    void on_unBindButton_clicked();
};

#endif // ACCOUNTBINDINGPAGELZY_H
