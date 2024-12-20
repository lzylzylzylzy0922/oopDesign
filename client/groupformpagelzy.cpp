#include "groupformpagelzy.h"
#include "ui_groupformpagelzy.h"

GroupFormPageLzy::GroupFormPageLzy(GroupLzy* grp,AccountLzy* acc,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroupFormPageLzy)
{
    ui->setupUi(this);

    this->group=grp;
    this->account=acc;

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

    if(userDao->getRole(grp,acc)=="MEMBER"||userDao->getRole(grp,acc)=="ADMIN"){
        ui->dissolveButton->hide();
        ui->tackleAdminButton->hide();
        if(userDao->getRole(grp,acc)!="ADMIN"){
            ui->tackleMemberButton->hide();
        }
    }else if(grp->getOwnerId()==userId){
        ui->exitButton->hide();
    }

    //ui->groupIdEdit->text(QString::number(grp->getGroupId()));
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
    bool status=userDao->removeMember(this->group,userDao->returnUser(account->getAccountId())->getUserId());
    if(status){
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
}

