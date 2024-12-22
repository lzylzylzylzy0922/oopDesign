#include "groupformpagelzy.h"
#include "ui_groupformpagelzy.h"

GroupFormPageLzy::GroupFormPageLzy(GroupLzy* grp,AccountLzy* acc,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroupFormPageLzy)
{
    ui->setupUi(this);

    this->group=grp;
    this->account=acc;
    s=new SearchForContactsLzy;

    QVBoxLayout* layout=new QVBoxLayout(ui->container);
    ui->container->setLayout(layout);
    GroupItemFrameLzy* infoItem=new GroupItemFrameLzy(group);
    infoItem->setFixedSize(300,110);
    ui->container->layout()->addWidget(infoItem);

    userDaoLzy* userDao=userDaoLzy::getInstance();
    int userId=userDao->returnUser(acc->getAccountId())->getUserId();


    if(acc->getType()==AccountType::WECHAT){
        ui->tackleAdminButton->hide();
    }

    //先查看该用户是否在群里
    if(userDao->ifMemberExists(grp,acc)){
        ui->joinGroupButton->hide();

        if(userDao->getRole(grp,acc)=="MEMBER"||userDao->getRole(grp,acc)=="ADMIN"){
            ui->dissolveButton->hide();
            ui->tackleAdminButton->hide();
            if(userDao->getRole(grp,acc)!="ADMIN"){
                ui->tackleMemberButton->hide();
            }
        }else if(grp->getOwnerId()==userId){
            ui->exitButton->hide();
        }
    }else{
        ui->sendMessageButton->hide();
        ui->searchMemberButton->hide();
        ui->dissolveButton->hide();
        ui->tackleAdminButton->hide();
        ui->tackleMemberButton->hide();
        ui->exitButton->hide();
    }

    ui->groupIdEdit->setText(QString::number(grp->getGroupId()));
    ui->groupNameEdit->setText(grp->getName());
    ui->groupIdEdit->setReadOnly(true);
    ui->groupNameEdit->setReadOnly(true);

    connect(this,&GroupFormPageLzy::showSearchForContactsLzy,s,&SearchForContactsLzy::recvSignal);
}

GroupFormPageLzy::~GroupFormPageLzy()
{
    delete ui;
}

void GroupFormPageLzy::on_searchMemberButton_clicked()
{
    GroupMemberQueryLzy* gm = new GroupMemberQueryLzy;
    connect(this, &GroupFormPageLzy::showGroupMemberQuery, gm, &GroupMemberQueryLzy::recvSignal);

    emit showGroupMemberQuery(this->group->getGroupId());
}



void GroupFormPageLzy::on_tackleAdminButton_clicked()
{
    GroupMemberQueryLzy* gm = new GroupMemberQueryLzy;
    connect(this, &GroupFormPageLzy::showGroupMemberQuery, gm, &GroupMemberQueryLzy::recvSignal);

    emit showGroupMemberQuery(this->group->getGroupId());
    gm->addCheckBox();
}


void GroupFormPageLzy::on_exitButton_clicked()
{
    userDaoLzy* userDao=userDaoLzy::getInstance();
    userDao->removeMember(this->group,userDao->returnUser(account->getAccountId())->getUserId());

    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    QJsonObject obj;
    obj["type"]="remove_member";
    obj["group_id"]=group->getGroupId();
    obj["to_id"]=account->getAccountId();
    QJsonDocument doc(obj);

    clientSocket->write(doc.toJson());
    clientSocket->flush();
    QMessageBox::information(this,"提示","退出群聊成功");

}


void GroupFormPageLzy::on_joinGroupButton_clicked()
{
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    QJsonObject obj;
    obj["type"]="join_group_request";
    obj["group_id"]=group->getGroupId();
    obj["from_id"]=account->getAccountId();

    userDaoLzy* userDao=userDaoLzy::getInstance();
    QString type;
    if(group->getType()==GroupType::QQ) type="QQ";
    else type="WECHAT";
    QString toId=userDao->getAccountByUserId(group->getOwnerId(),type);
    obj["to_id"]=toId;

    QJsonDocument doc(obj);


    clientSocket->write(doc.toJson());
    clientSocket->flush();
    QMessageBox::information(this,"提示","申请入群成功");
}


void GroupFormPageLzy::on_tackleMemberButton_clicked()
{
    GroupMemberQueryLzy* gm = new GroupMemberQueryLzy;
    connect(this, &GroupFormPageLzy::showGroupMemberQuery, gm, &GroupMemberQueryLzy::recvSignal);

    emit showGroupMemberQuery(this->group->getGroupId());
    gm->addCheckBox();
    gm->tackleMember();
}


void GroupFormPageLzy::on_invitFriendButton_clicked()
{
    emit showSearchForContactsLzy(this->account,this->group->getGroupId());
}


void GroupFormPageLzy::on_dissolveButton_clicked()
{
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    QJsonObject obj;
    obj["type"]="dissolve_group";
    obj["group_id"]=group->getGroupId();


    userDaoLzy* userDao=userDaoLzy::getInstance();

    QString type;
    if(group->getType()==GroupType::QQ) type="QQ";
    else type="WECHAT";

    QSqlQuery query=userDao->getMembers(group->getGroupId());
    QJsonArray array;
    while(query.next()){
        int userId=query.value(1).toInt();
        userDao->removeMember(group,userId);
        QString toId=userDao->getAccountByUserId(userId,type);
        array.append(toId);
    }

    obj["data"]=array;

    QJsonDocument doc(obj);

    clientSocket->write(doc.toJson());
    clientSocket->flush();

    //删除群聊
    userDao->dissolveGroup(group->getGroupId());
}

