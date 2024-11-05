#include "registerpagelzy.h"
#include "ui_registerpagelzy.h"

RegisterPageLzy::RegisterPageLzy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterPageLzy)
{
    ui->setupUi(this);

    //ui->phoneNumberEdit->setInputMask("000-0000-0000");
    ui->reminderLabel->hide();
    ui->birthEdit->setInputMask("0000-00-00");
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->verifyPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->reminderPasswordLabel->hide();

    connect(ui->pwdVisual,SIGNAL(stateChanged(int)),this,SLOT(updateEchoMode()));
}

RegisterPageLzy::~RegisterPageLzy()
{
    delete ui;
}

void RegisterPageLzy::recvSignal(){
    this->show();
}

void RegisterPageLzy::on_registerButton_clicked()
{
    AccountType type;
    QString telephone;
    QString nickname;
    QDate birth;
    QString location;
    QString inputPassword;
    QString secondInputPassword;

    if(ui->qqRadioButton->isChecked()){
        type=AccountType::QQ;
    }else if(ui->wechatRadioButton->isChecked()){
        type=AccountType::WECHAT;
    }else if(ui->weiboRadioButton->isChecked()){
        type=AccountType::WEIBO;
    }else{
        QMessageBox::warning(this,"警告","未选择应用");
        return;
    }

    //校验手机号
    utilsLzy* utils=utilsLzy::getInstance();
    if(utils->validatePhoneNumber(ui->phoneNumberEdit->text())){
        telephone=ui->phoneNumberEdit->text();
    }else{
        ui->reminderLabel->show();
        return;
    }

    //校验nickname
    if(ui->nicknameEdit->text().isEmpty()){
        QMessageBox::warning(this,"警告","昵称不能为空");
        return;
    }else{
        nickname=ui->nicknameEdit->text();
    }

    //校验生日
    QDate date=QDate::fromString(ui->birthEdit->text(),"yyyy-MM-dd");
    if(date.isValid()&&date<QDate::currentDate()){
        birth=date;
    }else{
        QMessageBox::warning(this,"警告","日期不正确");
        return;
    }

    //获取所在地
    location=ui->locationBox->currentText();

    //校验密码
    if(!utils->validatePassword(ui->passwordEdit->text())){
        ui->reminderPasswordLabel->show();
        return;
    }

    inputPassword=ui->passwordEdit->text();
    secondInputPassword=ui->verifyPasswordEdit->text();
    if(inputPassword!=secondInputPassword){
        ui->reminderPasswordLabel->setText("两次输入密码不一致");
        ui->reminderPasswordLabel->show();
        return;
    }

    //检验用户是否已经存在
    userDaoLzy* userDao=userDaoLzy::getInstance();
    if(userDao->isUserExistsByPhoneAndType(telephone,type)){
        QMessageBox::warning(this,"警告","用户已存在");
        return;
    }


    QString accountId=utils->createAccountId(type);
    qDebug()<<accountId;
    AccountLzy* account=new AccountLzy(accountId,type,nickname,inputPassword);

    //创建用户
    if(!userDao->createAccount(account,birth,location,telephone)){
        QMessageBox::warning(this,"警告","用户已存在");
        return;
    }

    QMessageBox::information(this,"提醒","你的账户ID是:"+accountId+"\n请务必记住");
}

void RegisterPageLzy::updateEchoMode(){
    if(ui->pwdVisual->isChecked()){
        ui->verifyPasswordEdit->setEchoMode(QLineEdit::Normal);
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
        ui->verifyPasswordEdit->setEchoMode(QLineEdit::Password);
    }
    //if((ui->qqAccount->text().isEmpty()||))
    }

