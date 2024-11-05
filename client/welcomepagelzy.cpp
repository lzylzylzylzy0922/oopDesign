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
    ui->wechatAccount->clear();
    ui->weiboAccount->clear();

    ui->qqAccount->setEnabled(true);
    ui->wechatAccount->setEnabled(false);
    ui->weiboAccount->setEnabled(false);

}


void welcomePageLzy::on_radioButton_2_clicked()
{
    ui->qqAccount->clear();
    ui->weiboAccount->clear();

    ui->qqAccount->setEnabled(false);
    ui->wechatAccount->setEnabled(true);
    ui->weiboAccount->setEnabled(false);
}


void welcomePageLzy::on_radioButton_3_clicked()
{
    ui->qqAccount->clear();
    ui->wechatAccount->clear();

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

    QString accountId;
    QString type;
    QString password=ui->passwordEdit->text();

    //校验用户是否存在
    if(!ui->qqAccount->text().isEmpty()){
        type="QQ";
        accountId=ui->qqAccount->text();

    }else if(!ui->wechatAccount->text().isEmpty()){
        type="WECHAT";
        accountId=ui->wechatAccount->text();

    }else if(!ui->weiboAccount->text().isEmpty()){
        type="WEIBO";
        accountId=ui->weiboAccount->text();
    }else{
        QMessageBox::warning(this,"警告","ID不能为空");
        return;
    }

    qDebug()<<"accountID:"<<accountId;

    userDaoLzy* userDao=userDaoLzy::getInstance();
    if(!userDao->isUserExistsByAccountAndType(accountId,type)){
        QMessageBox::warning(this,"警告","ID不存在");
    }else{
        //校验密码
        if(!userDao->isPasswordCorrect(accountId,password))
            QMessageBox::warning(this,"警告","密码错误");
        else{
            //跳转不同页面主界面 TODO
        }

    }



}


void welcomePageLzy::on_registerButton_clicked()
{
    this->hide();
    emit showRegisterPageLzy();
}

