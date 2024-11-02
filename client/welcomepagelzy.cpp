#include "welcomepagelzy.h"
#include "ui_welcomepagelzy.h"

welcomePageLzy::welcomePageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcomePageLzy)
{
    ui->setupUi(this);
    ui->qqAccount->setEnabled(false);
    ui->wechatAccount->setEnabled(false);
    ui->weiboAccount->setEnabled(false);

    ui->loginButton->setEnabled(false);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->reminderLabel->hide();
    connect(ui->pwdVisual,SIGNAL(stateChanged(int)),this,SLOT(updateEchoMode()));

}

welcomePageLzy::~welcomePageLzy()
{
    delete ui;
}

void welcomePageLzy::on_radioButton_clicked()
{
    ui->qqAccount->setEnabled(true);
    ui->wechatAccount->setEnabled(false);
    ui->weiboAccount->setEnabled(false);

}


void welcomePageLzy::on_radioButton_2_clicked()
{
    ui->qqAccount->setEnabled(false);
    ui->wechatAccount->setEnabled(true);
    ui->weiboAccount->setEnabled(false);
}


void welcomePageLzy::on_radioButton_3_clicked()
{
    ui->qqAccount->setEnabled(false);
    ui->wechatAccount->setEnabled(false);
    ui->weiboAccount->setEnabled(true);
}

void welcomePageLzy::updateEchoMode(){
    if(ui->pwdVisual->isChecked())
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
    else
        ui->passwordEdit->setEchoMode(QLineEdit::Password);

    //if((ui->qqAccount->text().isEmpty()||))
}


void welcomePageLzy::on_passwordEdit_editingFinished()
{
    utilsLzy* utils=utilsLzy::getInstance();
    QString password=ui->passwordEdit->text();

    if(utils->validatePassword(password)){
        ui->reminderLabel->hide();
        ui->loginButton->setEnabled(true);
    }
    else
        ui->reminderLabel->show();
}


void welcomePageLzy::on_loginButton_clicked()
{
    QSqlDatabase database=databaseConnectionLzy::getInstance();

}

