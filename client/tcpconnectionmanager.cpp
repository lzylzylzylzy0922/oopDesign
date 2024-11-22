#include "tcpconnectionmanager.h"

QTcpSocket* TcpConnectionManager::clientSocket;

TcpConnectionManager::TcpConnectionManager(QObject *parent)
    : QObject{parent}
{

}

QTcpSocket* TcpConnectionManager::getInstance(){
    if(clientSocket==nullptr){
        clientSocket=new QTcpSocket();
        clientSocket->connectToHost(QHostAddress(SERVER_ADDRESS),SERVER_PORT);
    }

    return clientSocket;
}
