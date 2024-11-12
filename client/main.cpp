#include "welcomepagelzy.h"
#include"registerpagelzy.h"
#include<mainpagelzy.h>
#include<searchpagelzy.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomePageLzy w;
    RegisterPageLzy r;
    MainPageLzy m;
    SearchPageLzy s;

    QObject::connect(&w,&welcomePageLzy::showRegisterPageLzy,&r,&RegisterPageLzy::recvSignal);
    QObject::connect(&r,&RegisterPageLzy::showWelcomePage,&w,&welcomePageLzy::recvSignal);
    QObject::connect(&w,&welcomePageLzy::showMainPageLzy,&m,&MainPageLzy::recvSignal);
    QObject::connect(&m,&MainPageLzy::showSearchPageLzy,&s,&SearchPageLzy::recvSignal);
    w.show();


    return a.exec();
}
