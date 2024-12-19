#include "groupformpagelzy.h"
#include "ui_groupformpagelzy.h"

GroupFormPageLzy::GroupFormPageLzy(GroupLzy* grp,AccountLzy* acc,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroupFormPageLzy)
{
    ui->setupUi(this);

    this->group=grp;
    this->account=acc;

}

GroupFormPageLzy::~GroupFormPageLzy()
{
    delete ui;
}
