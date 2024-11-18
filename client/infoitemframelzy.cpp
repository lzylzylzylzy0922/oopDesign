#include "infoitemframelzy.h"
#include "ui_infoitemframelzy.h"

infoItemFrameLzy::infoItemFrameLzy(AccountLzy* account,QString name, QString id, QString avatarPath, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::infoItemFrameLzy)
{

    this->account=account;
    ui->setupUi(this);

    ui->name->setText(name);
    ui->id->setText(id);
    this->accountId=id;

    // 设置头像
    QPixmap avatarPixmap(avatarPath);
    if (!avatarPixmap.isNull()) {
        avatarPixmap = avatarPixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 保持宽高比
        QPixmap roundedAvatar(40, 40);
        roundedAvatar.fill(Qt::transparent);

        QPainter painter(&roundedAvatar);
        painter.setRenderHint(QPainter::Antialiasing);
        QPainterPath path;
        path.addEllipse(0, 0, 40, 40);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, avatarPixmap);

        ui->avatar->setPixmap(roundedAvatar);
    }

}

infoItemFrameLzy::~infoItemFrameLzy() {
    delete ui;
}

void infoItemFrameLzy::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::LeftButton){

        emit clicked(account,userDaoLzy::getInstance()->returnAccount(this->accountId));
        qDebug()<<"个人信息栏被点击";
    }
    QFrame::mousePressEvent(event);
}

