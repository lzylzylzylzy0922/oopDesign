#include "searchforcontactslzy.h"
#include "ui_searchforcontactslzy.h"

SearchForContactsLzy::SearchForContactsLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchForContactsLzy)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setHorizontalHeaderLabels({"用户名","ID","选择"});
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
}

SearchForContactsLzy::~SearchForContactsLzy()
{
    delete ui;
}

void SearchForContactsLzy::recvSignal(AccountLzy* account,int groupId){
    this->groupId=groupId;
    userDaoLzy* userDao = userDaoLzy::getInstance();

    QSqlQuery query = userDao->searchContacts(account->getAccountId());

    int row = 0;
    while (query.next()) {
        QString type;
        if (account->getType() == AccountType::QQ) {
            type = "QQ";
        } else if (account->getType() == AccountType::WECHAT) {
            type = "WECHAT";
        } else {
            type = "WEIBO";
        }

        AccountLzy* friendAccount = userDao->returnAccountByUserId(query.value(1).toInt(), type);
        QString name = friendAccount->getAccountName();
        QString accountId = friendAccount->getAccountId();

        // 确保表格有足够的行
        if (row >= ui->tableWidget->rowCount()) {
            ui->tableWidget->insertRow(row);
        }

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(accountId));

        QCheckBox* checkBox = new QCheckBox();
        ui->tableWidget->setCellWidget(row, 2, checkBox);

        connect(checkBox, &QCheckBox::toggled, [this,row]() {
            QString accId;
            QString name;

            accId = ui->tableWidget->item(row, 1)->text();

            selectedUsers.append(accId);
        });

        row++;
    }

    this->show();
}

void SearchForContactsLzy::on_pushButton_clicked()
{
    //json
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    QJsonObject obj;
    obj["type"]="invit_friends";
    obj["data"]=selectedUsers;
    obj["group_id"]=groupId;

    qDebug()<<obj<<Qt::endl;
    QJsonDocument doc(obj);
    clientSocket->write(doc.toJson());
    clientSocket->flush();

    //插入group_member表中
    userDaoLzy* userDao=userDaoLzy::getInstance();
    QJsonArray dataArray = obj["data"].toArray();

    for (const QJsonValue &value : dataArray) {
        if (value.isString()) {
            QString accountId = value.toString();
            if(userDao->isMember(userDao->getGroup(groupId),userDao->returnUser(accountId)))
                continue;
            userDao->addGroupMember(userDao->getGroup(groupId),userDao->returnUser(accountId),2);//普通群成员
        }
    }

}

