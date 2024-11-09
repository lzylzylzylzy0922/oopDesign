#include "mainpagelzy.h"
#include "ui_mainpagelzy.h"

AccountLzy* MainPageLzy::account;

MainPageLzy::MainPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPageLzy)
{
    ui->setupUi(this);
}


MainPageLzy::~MainPageLzy()
{

    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);
    delete ui;
}

void MainPageLzy::recvSignal(QString accountId){


    AccountLzy* account = userDao->returnAccount(accountId);

    MainPageLzy::account=account;
    if (account) {
        ui->avatarLabel->setPixmap(account->getAvatar());
        ui->nicknameLabel->setText(account->getAccountName());
        ui->accountIdLabel->setText(account->getAccountId());

        // 更新在线状态
        loginStatus status = loginStatus::ONLINE;
        userDao->updateOnlineStatus(account, status);
        this->show();
    } else {
        qDebug() << "无法获取账号信息";
    }

}

void MainPageLzy::on_comboBox_activated(int index)
{
    //userDaoLzy* userDao=userDaoLzy::getInstance();
    switch (index) {
    case 0:
        //创建群聊 TODO
        //打开创建群聊界面
        qDebug()<<"打开创建群聊界面";
        break;
    case 1:
        //添加群聊 TODO
        //打开搜索界面
        qDebug()<<"打开搜索界面";
        break;
    case 2:
        //添加好友 TODO
        //打开搜索界面
        qDebug()<<"打开搜索界面";
        break;
    case 3:
        //绑定账户 TODO
        //打开绑定界面
        qDebug()<<"打开绑定界面";
        break;
    case 4:
        //注销 TODO
        qDebug()<<"注销";
        break;
    default:
        break;
    }
}

void MainPageLzy::closeEvent(QCloseEvent* event){
    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);
    event->accept();

}
