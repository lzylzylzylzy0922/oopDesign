#include "infoformpagelzy.h"
#include "ui_infoformpagelzy.h"

InfoFormPageLzy::InfoFormPageLzy(AccountLzy* account,QString acid,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoFormPageLzy)
{
    ui->setupUi(this);

    AccountLzy* searchAccount=userDao->returnAccount(acid);

    QVBoxLayout* layout=new QVBoxLayout(ui->container);
    ui->container->setLayout(layout);
    infoItemFrameLzy* infoItem=new infoItemFrameLzy(account,searchAccount->getAccountName(),searchAccount->getAccountId(),searchAccount->getAvatar());
    ui->container->layout()->addWidget(infoItem);

    UserLzy* user=userDao->returnUser(acid);


    ui->birthdayEdit->setReadOnly(true);
    ui->birthdayEdit->setText(user->getBirthday().toString());

    ui->locationEdit->setReadOnly(true);
    ui->locationEdit->setText(user->getLocation());




}

InfoFormPageLzy::~InfoFormPageLzy()
{
    delete ui;
}


