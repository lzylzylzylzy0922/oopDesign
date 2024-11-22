#include "mainpagelzy.h"
#include "ui_mainpagelzy.h"

AccountLzy* MainPageLzy::account=nullptr;

MainPageLzy::MainPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPageLzy)
{
    ui->setupUi(this);

    QVBoxLayout* layout=new QVBoxLayout(ui->personalInfoWidget);
    ui->personalInfoWidget->setLayout(layout);
}


MainPageLzy::~MainPageLzy()
{

    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);
    delete ui;
}


void MainPageLzy::initRequestTab(const QString& accountId){
    QVBoxLayout* layout=new QVBoxLayout;
    QWidget* container=new QWidget;
    container->setLayout(layout);

    ui->requestArea->setWidget(container);
    ui->requestArea->setWidgetResizable(true);
    ui->requestArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);// 确保显示垂直滚动条
    QSqlQuery query=userDao->searchRequest(accountId);

    QString id;
    AccountLzy* account;
    while(query.next()){
        id=query.value(0).toString();
        account=userDao->returnAccount(id);
        infoItemFrameLzy* newItem=new infoItemFrameLzy(account,account->getAccountName(),account->getAccountId(),account->getAvatar());
        newItem->setFixedSize(300,88);

        connect(newItem, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);
        ui->requestArea->widget()->layout()->addWidget(newItem);
    }
}

void MainPageLzy::recvSignal(QString accountId){
    connect(clientSocket,&QTcpSocket::errorOccurred,[this](){
        qDebug()<<"连接服务器失败";
        QMessageBox::warning(this,"连接提示","连接异常，请检查网络");
    });

    //如果连接成功
    if (clientSocket->state() == QTcpSocket::ConnectedState) {
        QByteArray accountIdData=accountId.toUtf8();

        clientSocket->write(accountIdData);
        clientSocket->flush();

    }

    //如果连接断开
    connect(clientSocket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"连接提示","连接断开");
    });


    qDebug() << "Socket thread:" << clientSocket->thread();
    qDebug() << "Current thread:" << QThread::currentThread();

    AccountLzy* account = userDao->returnAccount(accountId);

    MainPageLzy::account=account;
    if (account) {
        // 更新在线状态
        loginStatus status = loginStatus::ONLINE;
        userDao->updateOnlineStatus(account, status);
        this->show();
    } else {
        qDebug() << "无法获取账号信息";
    }
    //构造个人信息
    ui->personalInfoWidget->layout()->addWidget(new infoItemFrameLzy(account,account->getAccountName(),account->getAccountId(),account->getAvatar()));

    //初始化requestTab
    initRequestTab(accountId);

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
        //添加好友/群聊 TODO
        //打开搜索界面
        emit showSearchPageLzy(account);
        qDebug()<<"打开搜索界面";
        break;
    case 2:
        //绑定账户 TODO
        //打开绑定界面
        qDebug()<<"打开绑定界面";
        break;
    case 3:
        //注销 TODO
        qDebug()<<"注销";
        break;
    default:
        break;
    }
}

void MainPageLzy::onInfoItemClicked(AccountLzy* account,AccountLzy* friendAccount){
    account=this->account;
    InfoFormPageLzy* infoForm=new InfoFormPageLzy(account,friendAccount);
    infoForm->show();
}

void MainPageLzy::closeEvent(QCloseEvent* event){
    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);

    event->accept();

}
