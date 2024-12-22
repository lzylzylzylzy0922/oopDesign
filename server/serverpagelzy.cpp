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
            qDebug()<<"----------------"<<obj;
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
            }

            else if(type=="friend_request_agreed"){
                QString fromId = obj["account_id"].toString();
                QString toId = obj["friend_account_id"].toString();

                qDebug() << "好友申请通过: 从" << fromId << "到" << toId;

                forwardFriendRequest(type,fromId, toId);
            }

            else if(type=="friend_request_rejected"){
                QString fromId = obj["account_id"].toString();
                QString toId = obj["friend_account_id"].toString();

                qDebug() << "好友申请拒绝: 从" << fromId << "到" << toId;

                forwardFriendRequest(type,fromId, toId);
            }

            else if(type=="invit_friends"){
                int groupId=obj["group_id"].toInt();
                QJsonArray dataArray = obj["data"].toArray();

                for (const QJsonValue &value : dataArray) {
                    if (value.isString()) {
                        QString accountId = value.toString();
                        forwardGroupJson(type,groupId,accountId);
                    }
                }
            }

            else if(type=="remove_friend"){
                QString fromId = obj["account_id"].toString();
                QString toId = obj["friend_account_id"].toString();

                qDebug()<< fromId << "删除了" << toId<< "好友";

                forwardFriendRequest(type,fromId, toId);
            }

            else if(type=="remove_member"){
                QString toId=obj["to_id"].toString();
                int groupId=obj["group_id"].toInt();

                qDebug()<<toId<<"被移除"<<QString::number(groupId)<<"群聊";

                forwardGroupJson(type,groupId,toId);
            }

            else if(type=="join_group_request"){
                //---------------- QJsonObject({"from_id":"q190981","group_id":123456,"to_id":"q150883","type":"join_group_request"})
                QString fromId = obj["from_id"].toString();
                QString toId=obj["to_id"].toString();
                int groupId=obj["group_id"].toInt();

                qDebug()<<fromId<<"申请加入"<<groupId;
                QTcpSocket* clientSocket=this->getSocketById(toId);
                if(clientSocket==nullptr){
                    qDebug()<<"用户不在列表中，未查找到socket";
                    return;
                }

                QJsonDocument doc(obj);

                clientSocket->write(doc.toJson());
                clientSocket->flush();

            }

            else if(type=="tackle_group_request"){
                qDebug()<<obj;
                QString toId=obj["to_id"].toString();
                QTcpSocket* clientSocket=this->getSocketById(toId);
                if(clientSocket==nullptr){
                    qDebug()<<"用户不在列表中，未查找到socket";
                    return;
                }

                clientSocket->write(doc.toJson());
                clientSocket->flush();
            }
            else {
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
        qDebug()<<"用户不在列表中，未查找到socket";
        return;
    }

    QJsonObject obj;
    obj["type"]=type;
    obj["from_id"]=fromId;
    QJsonDocument doc(obj);

    clientSocket->write(doc.toJson());
    clientSocket->flush();
    qDebug()<<"将"<<fromId<<"的<<type<<转发给"<<toId;
}

void serverPageLzy::forwardGroupJson(QString type,int groupId,QString toId){
    QTcpSocket* clientSocket=this->getSocketById(toId);
    if(clientSocket==nullptr){
        qDebug()<<"用户不在列表中，未查找到socket";
        return;
    }

    QJsonObject obj;
    obj["type"]=type;
    obj["group_id"]=groupId;
    QJsonDocument doc(obj);

    clientSocket->write(doc.toJson());
    clientSocket->flush();
    qDebug()<<"将群"<<groupId<<"的"<<type<<"转发给"<<toId;
}
