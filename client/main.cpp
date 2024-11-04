#include "welcomepagelzy.h"
#include"registerpagelzy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomePageLzy w;
    RegisterPageLzy r;

    QObject::connect(&w,&welcomePageLzy::showRegisterPageLzy,&r,&RegisterPageLzy::recvSignal);

    w.show();
    return a.exec();
}
