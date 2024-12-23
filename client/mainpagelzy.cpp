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
    //初始化groupTab
    initGroupTab(account->getAccountId());

}

void MainPageLzy::on_comboBox_activated(int index)
{
    //userDaoLzy* userDao=userDaoLzy::getInstance();
    switch (index) {
    case 0:
        //创建群聊 TODO
        //打开创建群聊界面
        emit showCreateGroupPageLzy(account);
        qDebug()<<"打开创建群聊界面";
        break;
    case 1:
        //添加好友/群聊
        //打开搜索界面
        emit showSearchPageLzy(account);
        qDebug()<<"打开搜索界面";
        break;
    case 2:
        //绑定账户 TODO
        //打开绑定界面
        emit showBindingPage(account);
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

void MainPageLzy::onGroupItemClicked(GroupLzy* group){
    GroupFormPageLzy* infoForm=new GroupFormPageLzy(group,account);

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
    }else if(obj["type"].toString()=="friend_request_agreed"){
        AccountLzy* fromAccount=userDao->returnAccount(obj["from_id"].toString());
        if(fromAccount){
            infoItemFrameLzy* newContact=new infoItemFrameLzy(fromAccount,fromAccount->getAccountName(),fromAccount->getAccountId(),fromAccount->getAvatar());
            newContact->setFixedSize(300,88);
            connect(newContact, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);

            ui->contactsArea->widget()->layout()->addWidget(newContact);
        }
    }else if(obj["type"].toString()=="friend_request_rejected"){
        AccountLzy* fromAccount=userDao->returnAccount(obj["from_id"].toString());
        AccountLzy* searchAccount=userDao->returnAccount(obj["to_id"].toString());

        QMessageBox::warning(this,"好友申请提示",fromAccount->getAccountId()+"拒绝了你的好友申请");

        QLayout* layout = ui->requestArea->widget()->layout();
        infoItemFrameLzy* itemToRemove = nullptr;

        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget)
                qDebug()<<widget->property("accountId");

            if (widget && widget->property("accountId").toString() == searchAccount->getAccountId()) {
                itemToRemove = qobject_cast<infoItemFrameLzy*>(widget);
                layout->removeWidget(itemToRemove);
                itemToRemove->deleteLater();
            }
        }
    }else if(obj["type"].toString()=="invit_friends"){
        int groupId=obj["group_id"].toInt();
        GroupLzy* group=userDao->getGroup(groupId);
        if(userDao->isMember(group,userDao->returnUser(account->getAccountId())))
            return;

        GroupItemFrameLzy* newItem=new GroupItemFrameLzy(group);
        newItem->setFixedSize(300,110);

        connect(newItem, &GroupItemFrameLzy::clicked, this, &MainPageLzy::onGroupItemClicked);
        ui->groupArea->widget()->layout()->addWidget(newItem);

        //提示
        QMessageBox::information(this,"提示","你被邀请加入群聊"+QString::number(groupId));
    }else if(obj["type"].toString()=="remove_friend"){
        AccountLzy* fromAccount=userDao->returnAccount(obj["from_id"].toString());

        QLayout* layout = ui->contactsArea->widget()->layout();
        infoItemFrameLzy* itemToRemove = nullptr;
        // 遍历布局，查找并移除对应的组件

        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget)
                qDebug()<<widget->property("accountId");

            if (widget && widget->property("accountId").toString() == fromAccount->getAccountId()) {
                itemToRemove = qobject_cast<infoItemFrameLzy*>(widget);
                layout->removeWidget(itemToRemove);
                itemToRemove->deleteLater();
            }
        }
        QMessageBox::information(this,"提示","你被"+obj["from_id"].toString()+"删除了好友");
    }else if(obj["type"].toString()=="remove_member"){
        AccountLzy* account=userDao->returnAccount(obj["to_id"].toString());
        GroupLzy* group=userDao->getGroup(obj["group_id"].toInt());

        QLayout* layout = ui->groupArea->widget()->layout();
        GroupItemFrameLzy* itemToRemove = nullptr;
        // 遍历布局，查找并移除对应的组件

        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget)
                qDebug()<<widget->property("groupId");

            if (widget && widget->property("groupId").toInt() == group->getGroupId()) {
                itemToRemove = qobject_cast<GroupItemFrameLzy*>(widget);
                layout->removeWidget(itemToRemove);
                itemToRemove->deleteLater();
            }
        }
    }else if(obj["type"].toString()=="join_group_request"){
        int groupId=obj["group_id"].toInt();
        qDebug()<<"------"<<obj;
        QJsonObject returnObj;
        returnObj["type"]="tackle_group_request";
        returnObj["to_id"]=obj["from_id"];
        returnObj["group_id"]=groupId;
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,
                                      "加入请求",
                                      obj["from_id"].toString()+"申请加入"+QString::number(groupId)+",你同意吗？",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            qDebug() << "用户选择了Yes";
            userDao->addGroupMember(userDao->getGroup(groupId),userDao->returnUser(obj["from_id"].toString()),2);
            returnObj["dicision"]="AGREE";
        } else {
            qDebug() << "用户选择了No";
            returnObj["dicision"]="REJECT";
        }
        QJsonDocument doc(returnObj);
        clientSocket->write(doc.toJson());
        clientSocket->flush();
    }else if(obj["type"].toString()=="tackle_group_request"){
        if(obj["dicision"].toString()=="AGREE"){
            int groupId=obj["group_id"].toInt();
            GroupLzy* group=userDao->getGroup(groupId);
            GroupItemFrameLzy* newItem=new GroupItemFrameLzy(group);
            newItem->setFixedSize(300,110);

            connect(newItem, &GroupItemFrameLzy::clicked, this, &MainPageLzy::onGroupItemClicked);
            ui->groupArea->widget()->layout()->addWidget(newItem);
            QMessageBox::information(this,"提示","入群申请通过");
        }else{
            QMessageBox::information(this,"提示","入群申请被拒绝");
        }
    }else if(obj["type"].toString()=="remove_group_member"||obj["type"].toString()=="dissolve_group"){
        QLayout* layout = ui->groupArea->widget()->layout();
        GroupItemFrameLzy* itemToRemove = nullptr;

        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget)
                qDebug()<<widget->property("groupId");

            if (widget && widget->property("groupId").toInt() == obj["group_id"].toInt()) {
                itemToRemove = qobject_cast<GroupItemFrameLzy*>(widget);
                layout->removeWidget(itemToRemove);
                itemToRemove->deleteLater();
            }
        }
        if(obj["type"].toString()=="remove_group_member") QMessageBox::information(this,"提示","你被踢出群了");
        else QMessageBox::information(this,"提示",QString::number(obj["group_id"].toInt())+"群已经解散");
    }
}



void MainPageLzy::updateByInfoFormPageLzy(AccountLzy* searchAccount,TackleFriendRequest tfs){
    utilsLzy* utils=utilsLzy::getInstance();
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
    //移除联系人
    layout = ui->contactsArea->widget()->layout();

    itemToRemove = nullptr;
    // 遍历布局，查找并移除对应的组件

    for (int i = 0; i < layout->count(); ++i) {
        QWidget* widget = layout->itemAt(i)->widget();
        if(widget)
            qDebug()<<widget->property("accountId");

        if (widget && widget->property("accountId").toString() == searchAccount->getAccountId()) {
            itemToRemove = qobject_cast<infoItemFrameLzy*>(widget);
        }
    }

    if (itemToRemove) {
        layout->removeWidget(itemToRemove);
        itemToRemove->deleteLater();
    }

    if (tfs == TackleFriendRequest::AGREE) {
        //在联系人界面加入该用户
        infoItemFrameLzy* newContact=new infoItemFrameLzy(searchAccount,searchAccount->getAccountName(),searchAccount->getAccountId(),searchAccount->getAvatar());
        newContact->setFixedSize(300,88);
        connect(newContact, &infoItemFrameLzy::clicked, this, &MainPageLzy::onInfoItemClicked);

        ui->contactsArea->widget()->layout()->addWidget(newContact);
    }
    else if(tfs==TackleFriendRequest::REJECT){
        QJsonDocument doc=utils->toJsonDoc("friend_request_rejected",this->account->getAccountId(),searchAccount->getAccountId());

        clientSocket->write(doc.toJson());
        clientSocket->flush();
    }
    else if(tfs==TackleFriendRequest::REMOVE){
        //改变对方mainpage
        QJsonDocument doc=utils->toJsonDoc("remove_friend",this->account->getAccountId(),searchAccount->getAccountId());
        QTcpSocket* clientSocket=TcpConnectionManager::getInstance();
        clientSocket->write(doc.toJson());
        clientSocket->flush();
    }

}

void MainPageLzy::initGroupTab(const QString& accountId){
    QVBoxLayout* layout=new QVBoxLayout;
    QWidget* container=new QWidget;
    container->setLayout(layout);

    ui->groupArea->setWidget(container);
    ui->groupArea->setWidgetResizable(true);
    ui->groupArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QSqlQuery query=userDao->searchGroups(accountId);

    while(query.next()){
        int groupId=query.value(0).toInt();
        GroupLzy* group=userDao->getGroup(groupId);
        GroupItemFrameLzy* newItem=new GroupItemFrameLzy(group);
        newItem->setFixedSize(300,110);

        connect(newItem, &GroupItemFrameLzy::clicked, this, &MainPageLzy::onGroupItemClicked);
        ui->groupArea->widget()->layout()->addWidget(newItem);
    }
}

void MainPageLzy::updateByCreateGroupPageLzy(GroupLzy* group,int type){
    if(type==0){
        GroupItemFrameLzy* newItem=new GroupItemFrameLzy(group);
        newItem->setFixedSize(300,110);

        connect(newItem, &GroupItemFrameLzy::clicked, this, &MainPageLzy::onGroupItemClicked);
        ui->groupArea->widget()->layout()->addWidget(newItem);
    }
}
