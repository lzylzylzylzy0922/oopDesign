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

void MainPageLzy::initContactsTab(const QString& accountId){
    QVBoxLayout* layout=new QVBoxLayout;
    QWidget* container=new QWidget;
    container->setLayout(layout);

    ui->contactsArea->setWidget(container);
    ui->contactsArea->setWidgetResizable(true);
    ui->contactsArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);// 确保显示垂直滚动条
    QSqlQuery query=userDao->searchContacts(accountId);

    int friendId;
    AccountLzy* account;
    QString type;
    while(query.next()){
        friendId=query.value(1).toInt();
        type=query.value(2).toString();


        account=userDao->returnAccountByUserId(friendId,type);
        if(account==nullptr) qDebug()<<"============";
        infoItemFrameLzy* newItem=new infoItemFrameLzy(account,account->getAccountName(),account->getAccountId(),account->getAvatar());
        newItem->setFixedSize(300,88);

        connect(newItem, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);
        ui->contactsArea->widget()->layout()->addWidget(newItem);
    }
}

void MainPageLzy::updateRequestTab(AccountLzy* account){
    infoItemFrameLzy* newItem=new infoItemFrameLzy(account,account->getAccountName(),account->getAccountId(),account->getAvatar());
    newItem->setFixedSize(300,88);

    connect(newItem, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);
    ui->requestArea->widget()->layout()->addWidget(newItem);
}

void MainPageLzy::recvSignal(QString accountId){
    connect(clientSocket,&QTcpSocket::errorOccurred,[this](){
        qDebug()<<"连接服务器失败";
        QMessageBox::warning(this,"连接提示","连接异常，请检查网络");
    });

    //如果连接成功
    if (clientSocket->state() == QTcpSocket::ConnectedState) {
        utilsLzy* utils=utilsLzy::getInstance();
        QJsonDocument doc=utils->toJsonDoc("add_user",accountId);

        clientSocket->write(doc.toJson());
        clientSocket->flush();

    }

    //如果连接断开
    connect(clientSocket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"连接提示","连接断开");
    });


    //监听server
    connect(clientSocket,&QTcpSocket::readyRead,this,&MainPageLzy::OnReadyRead);

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
    //初始化contactsTab
    initContactsTab(this->account->getAccountId());

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
    connect(infoForm,&InfoFormPageLzy::updateMainPageLzy,this,&MainPageLzy::updateByInfoFormPageLzy);

    infoForm->show();
}

void MainPageLzy::closeEvent(QCloseEvent* event){
    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);

    event->accept();

}

void MainPageLzy::OnReadyRead(){
    QByteArray data=clientSocket->readAll();
    QJsonDocument doc=QJsonDocument::fromJson(data);

    QJsonObject obj=doc.object();

    if(obj["type"].toString()=="friend_request"){
        AccountLzy* fromAccount=userDao->returnAccount(obj["from_id"].toString());
        qDebug()<<fromAccount->getAccountId();
        if (fromAccount) {
            // 更新好友申请表，添加新的申请项
            updateRequestTab(fromAccount);
        } else {
            qDebug() << "无法找到请求的账户信息";
        }
    }
}



void MainPageLzy::updateByInfoFormPageLzy(AccountLzy* searchAccount,TackleFriendRequest tfs){
    if (tfs == TackleFriendRequest::AGREE) {
        QLayout* layout = ui->requestArea->widget()->layout();


        infoItemFrameLzy* itemToRemove = nullptr;
        // 遍历布局，查找并移除对应的组件

        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget)
                qDebug()<<widget->property("accountId");

            if (widget && widget->property("accountId").toString() == searchAccount->getAccountId()) {
                itemToRemove = qobject_cast<infoItemFrameLzy*>(widget);
                break;
            }
        }

        if (itemToRemove) {
            layout->removeWidget(itemToRemove);
            itemToRemove->deleteLater();
        }

        //在联系人界面加入该用户
        infoItemFrameLzy* newContact=new infoItemFrameLzy(searchAccount,searchAccount->getAccountName(),searchAccount->getAccountId(),searchAccount->getAvatar());
        newContact->setFixedSize(300,88);
        connect(newContact, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);

        ui->contactsArea->widget()->layout()->addWidget(newContact);
    }

}
