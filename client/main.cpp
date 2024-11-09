#include "welcomepagelzy.h"
#include"registerpagelzy.h"
#include<mainpagelzy.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomePageLzy w;
    RegisterPageLzy r;
    MainPageLzy m;

    QObject::connect(&w,&welcomePageLzy::showRegisterPageLzy,&r,&RegisterPageLzy::recvSignal);
    QObject::connect(&r,&RegisterPageLzy::showWelcomePage,&w,&welcomePageLzy::recvSignal);
    QObject::connect(&w,&welcomePageLzy::showMainPageLzy,&m,&MainPageLzy::recvSignal);

    w.show();
    return a.exec();
}
