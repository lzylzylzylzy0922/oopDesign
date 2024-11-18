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
        ui->rejectButton->hide();
        ui->agreeButton->hide();
    } else {
        ui->rejectButton->hide();
        ui->agreeButton->hide();
        ui->sendMessageButton->hide();
    }


}

InfoFormPageLzy::~InfoFormPageLzy()
{
    delete ui;
}



void InfoFormPageLzy::on_addFriendButton_clicked()
{
    userDao->addFriend(this->account,this->searchAccount);
    qDebug()<<this->account->getAccountId()<<"向"<<this->searchAccount->getAccountId()<<"发送了好友申请";
    QMessageBox::information(this,"提示","已向用户提交用户申请");

}

