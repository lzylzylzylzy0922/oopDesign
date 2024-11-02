#include "welcomepagelzy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcomePageLzy w;
    w.show();
    return a.exec();
}
