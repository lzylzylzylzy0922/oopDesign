#include "serverpagelzy.h"
#include "ui_serverpagelzy.h"

serverPageLzy::serverPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverPageLzy)
{
    ui->setupUi(this);

    //服务器
    server=new QTcpServer;
    //监听8000端口
    server->listen(QHostAddress::AnyIPv4,PORT);


    connect(server, &QTcpServer::newConnection, this, [this]() {
        QTcpSocket* clientSocket = server->nextPendingConnection();

        connect(clientSocket, &QTcpSocket::readyRead, [clientSocket, this]() {
            QByteArray data = clientSocket->readAll();

            // 解析 Json
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (!doc.isObject()) {
                qDebug() << "非JSON格式数据，忽略";
                return;
            }

            QJsonObject obj = doc.object();
            QString type = obj["type"].toString();
            qDebug()<<"客户端向服务器发送了"<<type<<"请求";

            if(type=="add_user"){
                accountId=obj["account_id"].toString();
                addUser(clientSocket,accountId);
            }

            else if (type == "friend_request") {
                QString fromId = obj["account_id"].toString();
                QString toId = obj["friend_account_id"].toString();

                qDebug() << "收到好友申请: 从" << fromId << "到" << toId;

                forwardFriendRequest(type,fromId, toId);
            } else {
                qDebug() << "未知消息类型:" << type;
            }
        });

        connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
            removeUser(clientSocket);
            clientSocket->deleteLater();
        });
    });
}

serverPageLzy::~serverPageLzy()
{
    delete ui;
}


void serverPageLzy::addUser(QTcpSocket *socket,QString accountId){
    int row = ui->userTable->rowCount();
    ui->userTable->insertRow(row);

    // 获取客户端的 IP 地址和端口
    QString ipAddress = socket->peerAddress().toString();
    int port = socket->peerPort();

    ui->userTable->setItem(row, 0, new QTableWidgetItem(ipAddress));
    ui->userTable->setItem(row, 1, new QTableWidgetItem(QString::number(port)));
    ui->userTable->setItem(row,2,new QTableWidgetItem(accountId));

    users.insert(accountId,socket);
}


void serverPageLzy::removeUser(QTcpSocket* socket){

    for(int row=0;row<ui->userTable->rowCount();row++){
        QTableWidgetItem* item=ui->userTable->item(row,2);

        if(ui->userTable->item(row,0)->text()==socket->peerAddress().toString()&&
            ui->userTable->item(row,1)->text()==QString::number(socket->peerPort())){
            QString accountId=ui->userTable->item(row,2)->text();
            users.remove(accountId);
            ui->userTable->removeRow(row);
            break;
        }
        QString accountId=item->text();


    }
}

QTcpSocket* serverPageLzy::getSocketById(QString accountId){
    for(auto item:users.keys()){
        if(item==accountId)
            return users[item];
    }
    return nullptr;
}

void serverPageLzy::forwardFriendRequest(QString type,QString fromId,QString toId){
    QTcpSocket* clientSocket=this->getSocketById(toId);
    if(clientSocket==nullptr){
        return;
    }

    QJsonObject obj;
    obj["type"]=type;
    obj["from_id"]=fromId;
    QJsonDocument doc(obj);

    clientSocket->write(doc.toJson());
}
