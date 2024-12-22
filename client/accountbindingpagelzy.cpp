#include "accountbindingpagelzy.h"
#include "ui_accountbindingpagelzy.h"

AccountBindingPageLzy::AccountBindingPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountBindingPageLzy)
{
    ui->setupUi(this);
}

AccountBindingPageLzy::~AccountBindingPageLzy()
{
    delete ui;
}

void AccountBindingPageLzy::recvSignal(AccountLzy* account){
    QString accountId=account->getAccountId();

    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

    this->account=account;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    QSqlQuery query=userDao->getAccountsByUser(userDao->returnUser(account->getAccountId()));

    int row=0;
    while(query.next()){
        QString type=query.value(1).toString();
        QString accId=userDao->getAccountByUserId(account->getUserId(),type);
        AccountLzy* acc=userDao->returnAccount(accId);

        if(accId==account->getAccountId()){
            continue;
        }

        // 确保表格有足够的行
        if (row >= ui->tableWidget->rowCount()) {
            ui->tableWidget->insertRow(row);
        }

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(type));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(accId));

        if(userDao->ifBinding(account->getAccountId(),accId))
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString("已绑定")));
        else{
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString("未绑定")));
        }

        QCheckBox* checkBox = new QCheckBox();
        ui->tableWidget->setCellWidget(row, 3, checkBox);
        connect(checkBox, &QCheckBox::toggled, [account,this,row]() {
            QString accId;
            QString name;

            accId = ui->tableWidget->item(row, 1)->text();
            selectedAccounts.append(qMakePair(account->getAccountId(),accId));
        });

        row++;
    }

    this->show();
}

void AccountBindingPageLzy::on_pushButton_clicked()
{
    for (const auto &accountPair : selectedAccounts) {
        QString accId1 = accountPair.first;
        QString accId2 = accountPair.second;

        userDaoLzy* userDao=userDaoLzy::getInstance();
        if(userDao->ifBinding(accId1,accId2)){
            continue;
        }

        int userId=userDao->returnUser(accId1)->getUserId();
        if (userDao->bindAccounts(userId,accId1, accId2)&&userDao->bindAccounts(userId,accId2,accId1)) {
            QMessageBox::information(this,"提示","绑定成功");
            qDebug() << "successfully bound accounts:" << accId1 << "and" << accId2;

        } else {
            qWarning() << "failed to bind accounts:" << accId1 << "and" << accId2;
        }
    }
}


void AccountBindingPageLzy::on_unBindButton_clicked()
{
    for (const auto &accountPair : selectedAccounts) {
        QString accId1 = accountPair.first;
        QString accId2 = accountPair.second;

        userDaoLzy* userDao=userDaoLzy::getInstance();

        int userId=userDao->returnUser(accId1)->getUserId();
        if (userDao->unbindAccounts(userId,accId1, accId2)&&userDao->unbindAccounts(userId,accId2,accId1)) {
            QMessageBox::information(this,"提示","解绑成功");
            qDebug() << "successfully unbound accounts:" << accId1 << "and" << accId2;

        } else {
            qWarning() << "failed to unbind accounts:" << accId1 << "and" << accId2;
        }
    }
}

