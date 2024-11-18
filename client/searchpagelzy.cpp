#include "searchpagelzy.h"
#include "ui_searchpagelzy.h"

AccountLzy* SearchPageLzy::account=nullptr;

SearchPageLzy::SearchPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchPageLzy)
{
    ui->setupUi(this);

    initUserScrollArea();
    initGroupScrollArea();

}

SearchPageLzy::~SearchPageLzy()
{
    delete ui;
}


void SearchPageLzy::initUserScrollArea(){
    QVBoxLayout* layout=new QVBoxLayout(ui->userScrollArea);
    QWidget* container=new QWidget;
    container->setLayout(layout);

    ui->userScrollArea->setWidget(container);
    ui->userScrollArea->setWidgetResizable(true);

    ui->userScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);// 确保显示垂直滚动条
}

void SearchPageLzy::initGroupScrollArea(){
    QVBoxLayout* layout=new QVBoxLayout(ui->groupScrollArea);
    QWidget* container=new QWidget;
    container->setLayout(layout);

    ui->groupScrollArea->setWidget(container);
    ui->groupScrollArea->setWidgetResizable(true);

    ui->groupScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

void SearchPageLzy::searchUsers(QString text){
    QString accountId;
    userDaoLzy* userDao=userDaoLzy::getInstance();
    QSqlQuery query=userDao->searchUsersById(text);

    while(query.next()){
        accountId=query.value(0).toString();

        AccountLzy* account=userDao->returnAccount(accountId);
        if(this->account->getAccountId()==account->getAccountId()) continue;//跳过自己

        qDebug()<<"搜索到用户："<<account->getAccountName();
        infoItemFrameLzy* infoItem=new infoItemFrameLzy(account,account->getAccountName(),account->getAccountId(),account->getAvatar());

        connect(infoItem, &infoItemFrameLzy::clicked, this, &SearchPageLzy::onInfoItemClicked);

        if(!users.contains(account->getAccountId())){
            users.append(account->getAccountId());
            ui->userScrollArea->widget()->layout()->addWidget(infoItem);//这里尤其注意！！！
        }

    }

}

void SearchPageLzy::searchGroups(QString text){

}
void SearchPageLzy::on_searchButton_clicked()
{
    //再次点击时先清空
    QLayout* layout = ui->userScrollArea->widget()->layout();
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    users.clear();


    QString text=ui->idEdit->text();
    this->searchUsers(text);
    this->searchGroups(text);
}


void SearchPageLzy::recvSignal(AccountLzy* account){
    this->account=account;
    this->show();
}

void SearchPageLzy::onInfoItemClicked(AccountLzy* account,AccountLzy* friendAccount){
    account=this->account;
    AccountLzy* searchAccount=friendAccount;
    InfoFormPageLzy* infoForm=new InfoFormPageLzy(account,searchAccount);
    infoForm->show();
}
