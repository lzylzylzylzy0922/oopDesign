#include "GroupMemberQueryLzy.h"
#include "ui_GroupMemberQueryLzy.h"
#include <QMessageBox>
#include <QHeaderView>

GroupMemberQueryLzy::GroupMemberQueryLzy(QWidget *parent)
    : QWidget(parent), ui(new Ui::GroupMemberQueryLzy)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Group ID", "User ID", "Role"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->removeAdminButton->hide();
    //connect(ui->queryButton, &QPushButton::clicked, this, &GroupMemberQueryLzy::queryGroupMembers);

    connect(ui->removeMemberButton,&QPushButton::clicked,this,&GroupMemberQueryLzy::removeGroupMembers);
}

GroupMemberQueryLzy::~GroupMemberQueryLzy()
{
    delete ui;
}

void GroupMemberQueryLzy::closeEvent(QCloseEvent *event)
{
    delete this; // 销毁当前对象
    event->accept(); // 接受关闭事件
}

void GroupMemberQueryLzy::recvSignal(int groupId)
{
    groupIdToQuery = groupId;
    queryGroupMembers();

    this->show();
}

void GroupMemberQueryLzy::queryGroupMembers()
{
    ui->queryButton->hide();
    ui->removeMemberButton->hide();
    ui->removeAdminButton->hide();

    QSqlQuery query;
    query.prepare("select group_id, user_id, role from group_member WHERE group_id = :group_id");
    query.bindValue(":group_id", groupIdToQuery);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return;
    }

    ui->tableWidget->setRowCount(0);

    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("group_id").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("user_id").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("role").toString()));
    }
}

void GroupMemberQueryLzy::addCheckBox(){
    ui->removeAdminButton->show();
    ui->queryButton->show();
    ui->removeMemberButton->hide();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Group ID", "User ID", "Role","CheckBox"});
    ui->queryButton->setText("设置为管理员");
    connect(ui->queryButton,&QPushButton::clicked,this,&GroupMemberQueryLzy::addAdmin);
    connect(ui->removeAdminButton,&QPushButton::clicked,this,&GroupMemberQueryLzy::removeAdmin);

    QAbstractItemModel *model = ui->tableWidget->model();

    if (model) {
        for (int row = 0; row < model->rowCount(); ++row) {
            QTableWidgetItem* item = ui->tableWidget->item(row,2);
            if(item->text()=="OWNER") continue;

            QCheckBox* checkBox = new QCheckBox();
            ui->tableWidget->setCellWidget(row, 3, checkBox);

            connect(checkBox, &QCheckBox::toggled, [this,row]() {
                int userId;

                userId = ui->tableWidget->item(row, 1)->text().toInt();

                selectedUsers.append(userId);

                qDebug()<<selectedUsers;
            });
        }
    }
}

void GroupMemberQueryLzy::tackleMember(){
    ui->removeAdminButton->hide();
    ui->queryButton->hide();
    ui->removeMemberButton->show();
}

void GroupMemberQueryLzy::addAdmin(){
    userDaoLzy* userDao=userDaoLzy::getInstance();
    for (const QJsonValue &value : selectedUsers) {
        int userId=value.toInt();
        if(userId==userDao->getGroup(groupIdToQuery)->getOwnerId()) continue;
        userDao->changeAdmin(userId,Mode::ADDADMIN);
    }

    QMessageBox::information(this,"提示","添加管理员成功");
}

void GroupMemberQueryLzy::removeAdmin(){
    userDaoLzy* userDao=userDaoLzy::getInstance();
    for (const QJsonValue &value : selectedUsers) {
        int userId=value.toInt();
        if(userId==userDao->getGroup(groupIdToQuery)->getOwnerId()) continue;
        userDao->changeAdmin(userId,Mode::REMOVEADMIN);
    }

    QMessageBox::information(this,"提示","移除管理员成功");
}

void GroupMemberQueryLzy::removeGroupMembers() {
    userDaoLzy* userDao = userDaoLzy::getInstance();
    QJsonArray removedUsers;

    for (const QJsonValue& value : selectedUsers) {
        int userId = value.toInt();
        if (userId == userDao->getGroup(groupIdToQuery)->getOwnerId()) continue;

        GroupLzy* group=userDao->getGroup(groupIdToQuery);
        userDao->removeMember(group, userId);
        QString type;
        if(group->getType()==GroupType::QQ) type="QQ";
        else type="WECHAT";

        removedUsers.append(userDao->getAccountByUserId(userId,type));
    }

    QTcpSocket* clientSocket = TcpConnectionManager::getInstance();

    if (clientSocket && clientSocket->isOpen() && !removedUsers.isEmpty()) {
        QJsonObject obj;
        obj["type"] = "remove_group_member";
        obj["group_id"] = groupIdToQuery;
        obj["data"] = removedUsers;

        QJsonDocument doc(obj);
        QByteArray jsonData = doc.toJson();

        clientSocket->write(jsonData);
        clientSocket->flush();
    }

    QMessageBox::information(this, "提示", "踢出群员成功");
}


