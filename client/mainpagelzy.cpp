#include "mainpagelzy.h"
#include "ui_mainpagelzy.h"

AccountLzy* MainPageLzy::account=nullptr;

MainPageLzy::MainPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPageLzy)
{
    ui->setupUi(this);

    socket=new QTcpSocket;

    QVBoxLayout* layout=new QVBoxLayout(ui->personalInfowidget);
    ui->personalInfowidget->setLayout(layout);
}


MainPageLzy::~MainPageLzy()
{

    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);
    delete ui;
}

void MainPageLzy::recvSignal(QString accountId){
    socket->connectToHost(QHostAddress(SERVER_ADDRESS),SERVER_PORT);

    connect(socket,&QTcpSocket::errorOccurred,[this](){
        qDebug()<<"连接服务器失败";
        QMessageBox::warning(this,"连接提示","连接异常，请检查网络");
    });

    //如果连接成功
    connect(socket,&QTcpSocket::connected,[this,accountId](){
        qDebug()<<account->getAccountId()<<"连接服务器成功";
        QByteArray accountIdData=accountId.toUtf8();

        socket->write(accountIdData);
        socket->flush();
        qDebug()<<accountIdData;
    });

    //如果连接断开
    connect(socket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"连接提示","连接断开");
    });


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
    ui->personalInfowidget->layout()->addWidget(new infoItemFrameLzy(account->getAccountName(),account->getAccountId(),account->getAvatar()));

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

void MainPageLzy::closeEvent(QCloseEvent* event){
    userDao->updateOnlineStatus(account,loginStatus::OFFLINE);
    event->accept();

}
