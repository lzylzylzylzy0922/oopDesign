#ifndef SERVERPAGELZY_H
#define SERVERPAGELZY_H

#include <QWidget>
#include<QTcpSocket>
#include<QTcpServer>
#include<QMap>
#include<QDebug>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

#define PORT 8000

QT_BEGIN_NAMESPACE
namespace Ui {
class serverPageLzy;
}
QT_END_NAMESPACE

class serverPageLzy : public QWidget
{
    Q_OBJECT

public:
    serverPageLzy(QWidget *parent = nullptr);
    ~serverPageLzy();

private:
    Ui::serverPageLzy *ui;
    QTcpServer* server;
    QString accountId;//临时存储要连接的accountId
    QMap<QString,QTcpSocket*> users;//记录在线用户

    void addUser(QTcpSocket *socket,QString accountId);
    void removeUser(QTcpSocket *socket);
    void forwardFriendRequest(QString type,QString fromId,QString toId);
    void forwardGroupJson(QString type,int groupId,QString toId);
    QTcpSocket* getSocketById(QString accountId);

};
#endif // SERVERPAGELZY_H
