#ifndef TCPCONNECTIONMANAGER_H
#define TCPCONNECTIONMANAGER_H

#include <QObject>
#include<QTcpSocket>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8000

class TcpConnectionManager : public QObject
{
    Q_OBJECT
public:
    static QTcpSocket* getInstance();

private:
    explicit TcpConnectionManager(QObject *parent = nullptr);
    static QTcpSocket* clientSocket;

signals:
};

#endif // TCPCONNECTIONMANAGER_H
