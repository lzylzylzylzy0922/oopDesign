#include "welcomepagelzy.h"
#include"registerpagelzy.h"
#include<mainpagelzy.h>
#include<searchpagelzy.h>
#include<infoformpagelzy.h>
#include<creategrouppagelzy.h>
#include<searchforcontactslzy.h>
#include<groupformpagelzy.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomePageLzy w;
    RegisterPageLzy r;
    MainPageLzy m;
    SearchPageLzy s;
    CreateGroupPageLzy c;
    SearchForContactsLzy sfc;


    QObject::connect(&w,&welcomePageLzy::showRegisterPageLzy,&r,&RegisterPageLzy::recvSignal);
    QObject::connect(&r,&RegisterPageLzy::showWelcomePage,&w,&welcomePageLzy::recvSignal);
    QObject::connect(&w,&welcomePageLzy::showMainPageLzy,&m,&MainPageLzy::recvSignal);
    QObject::connect(&m,&MainPageLzy::showSearchPageLzy,&s,&SearchPageLzy::recvSignal);
    QObject::connect(&m,&MainPageLzy::showCreateGroupPageLzy,&c,&CreateGroupPageLzy::recvSignal);
    QObject::connect(&c,&CreateGroupPageLzy::showSearchForContactsLzy,&sfc,&SearchForContactsLzy::recvSignal);
    QObject::connect(&c,&CreateGroupPageLzy::updateMainPageLzy,&m,&MainPageLzy::updateByCreateGroupPageLzy);

    w.show();


    return a.exec();
}
