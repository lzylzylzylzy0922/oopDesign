#include "infoformpagelzy.h"
#include "ui_infoformpagelzy.h"

InfoFormPageLzy::InfoFormPageLzy(AccountLzy* account,AccountLzy* searchAccount,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoFormPageLzy)
{
    ui->setupUi(this);

    this->account=account;
    this->searchAccount=searchAccount;

    QVBoxLayout* layout=new QVBoxLayout(ui->container);
    ui->container->setLayout(layout);
    infoItemFrameLzy* infoItem=new infoItemFrameLzy(searchAccount,searchAccount->getAccountName(),searchAccount->getAccountId(),searchAccount->getAvatar());
    ui->container->layout()->addWidget(infoItem);

    UserLzy* user=userDao->returnUser(this->searchAccount->getAccountId());


    ui->birthdayEdit->setReadOnly(true);
    ui->birthdayEdit->setText(user->getBirthday().toString());

    ui->locationEdit->setReadOnly(true);
    ui->locationEdit->setText(user->getLocation());
    qDebug()<<account->getUserId();

    bool hasSentRequest = userDao->ifSentAddFriendRequest(searchAccount, account);
    bool isFriend = userDao->checkIfFriend(account->getUserId(), searchAccount->getUserId(), account->getType());

    if (hasSentRequest) {
        ui->addFriendButton->hide();
        ui->sendMessageButton->hide();
    } else if (isFriend) {
        ui->addFriendButton->hide();
        ui->agreeButton->hide();
        ui->rejectButton->hide();
    } else {
        ui->agreeButton->hide();
        ui->rejectButton->hide();
        ui->sendMessageButton->hide();
    }


}

InfoFormPageLzy::~InfoFormPageLzy()
{
    delete ui;
}



void InfoFormPageLzy::on_addFriendButton_clicked()
{
    if(userDao->ifSentAddFriendRequest(this->account,this->searchAccount)) return;
    userDao->addFriend(this->account,this->searchAccount);

    QJsonDocument doc=utils->toJsonDoc("friend_request",this->account->getAccountId(),this->searchAccount->getAccountId());
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    clientSocket->write(doc.toJson());
    clientSocket->flush();

    qDebug()<<this->account->getAccountId()<<"向"<<this->searchAccount->getAccountId()<<"发送了好友申请";
    QMessageBox::information(this,"提示","已向用户提交用户申请");

}



void InfoFormPageLzy::on_agreeButton_clicked()
{
    userDao->agreeFriendRequest(this->account,this->searchAccount);

    QJsonDocument doc=utils->toJsonDoc("friend_request_agreed",this->account->getAccountId(),this->searchAccount->getAccountId());
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    clientSocket->write(doc.toJson());
    clientSocket->flush();

    qDebug()<<this->account->getAccountId()<<"同意了"<<this->searchAccount->getAccountId()<<"的好友申请";

    TackleFriendRequest tfs=TackleFriendRequest::AGREE;
    emit updateMainPageLzy(this->searchAccount,tfs);

    this->hide();
}


void InfoFormPageLzy::on_rejectButton_clicked()
{
    userDao->rejectFriendRequest(this->account,this->searchAccount);

    QJsonDocument doc=utils->toJsonDoc("friend_request_rejected",this->account->getAccountId(),this->searchAccount->getAccountId());
    QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
    clientSocket->write(doc.toJson());
    clientSocket->flush();

    qDebug()<<this->account->getAccountId()<<"拒绝了"<<this->searchAccount->getAccountId()<<"的好友申请";

    TackleFriendRequest tfs=TackleFriendRequest::REJECT;
    emit updateMainPageLzy(this->searchAccount,tfs);

    this->hide();
}

