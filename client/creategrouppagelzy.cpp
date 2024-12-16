#include "creategrouppagelzy.h"
#include "ui_creategrouppagelzy.h"

AccountLzy* CreateGroupPageLzy::account=nullptr;

CreateGroupPageLzy::CreateGroupPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateGroupPageLzy)
{
    ui->setupUi(this);

    ui->invitFriendButton->hide();

    //处理头像（默认头像）
    QPixmap avatarPixmap("E:/oopDesign/images/default_avatar.png");

    if (!avatarPixmap.isNull()) {
        // 缩放图片
        avatarPixmap = avatarPixmap.scaled(40, 40, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        ui->avatarLabel->setPixmap(avatarPixmap);
    } else {
        qDebug() << "图像没有被加载出来";
    }

    ui->avatarLabel->setAlignment(Qt::AlignCenter);
    ui->avatarLabel->setFixedSize(40, 40);
    ui->avatarLabel->setStyleSheet("border: 1px solid black;");
}

CreateGroupPageLzy::~CreateGroupPageLzy()
{
    delete ui;
}

void CreateGroupPageLzy::recvSignal(AccountLzy* account){
    this->account=account;

    this->show();
}

void CreateGroupPageLzy::on_uploadAvatarButton_clicked()
{
    QString avatarPath=QFileDialog::getOpenFileName(this,"选择头像","","Image Files (*.png *.jpg *.bmp *.jpeg)");

    QPixmap avatarPixmap(avatarPath);
    if (!avatarPixmap.isNull()) {
        // 缩放图片
        avatarPixmap = avatarPixmap.scaled(40, 40, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        ui->avatarLabel->setPixmap(avatarPixmap);
    } else {
        qDebug() << "图像没有被加载出来";
    }
}


void CreateGroupPageLzy::on_invitFriendButton_clicked()
{
    emit showSearchForContactsLzy(this->account,groupId);
}


void CreateGroupPageLzy::on_createGroupButton_clicked()
{
    this->groupId = ui->groupId->text().toInt();
    QString groupName = ui->groupName->text();

    if (groupName.isEmpty()) {
        QMessageBox::warning(this, "警告", "群名不能为空！");
        return;
    }

    QString groupIdStr = QString::number(this->groupId);
    QRegularExpression regex("^\\d{6}$");
    QRegularExpressionMatch match = regex.match(groupIdStr);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "警告", "群号必须是6位数字！");
        return;
    }

    utilsLzy* utils = utilsLzy::getInstance();
    QString type = utils->getType(account);


    UserLzy* user=userDao->returnUser(account->getAccountId());
    int ownerId = user->getUserId();
    QDateTime currentTime = QDateTime::currentDateTime();

    userDaoLzy* userDao = userDaoLzy::getInstance();

    if (userDao->createGroup(this->groupId, groupName, type, ownerId, currentTime)) {
        //把群主插入group_member表中
        userDao->addGroupMember(userDao->getGroup(groupId),userDao->returnUser(account->getAccountId()),0);
        //更新界面
        emit updateMainPageLzy(userDao->getGroup(groupId),0);
        QMessageBox::information(this, "提醒", "创建群聊成功");
        ui->createGroupButton->hide();
        ui->invitFriendButton->show();
    } else {
        QMessageBox::information(this, "提醒", "创建群聊失败");
    }
}



