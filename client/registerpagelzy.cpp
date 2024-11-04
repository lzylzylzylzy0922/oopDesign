#include "registerpagelzy.h"
#include "ui_registerpagelzy.h"

RegisterPageLzy::RegisterPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterPageLzy)
{
    ui->setupUi(this);
}

RegisterPageLzy::~RegisterPageLzy()
{
    delete ui;
}

void RegisterPageLzy::recvSignal(){
    this->show();
}
