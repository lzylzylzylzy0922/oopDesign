#include "serverpagelzy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverPageLzy w;
    w.show();
    return a.exec();
}
