#include "groupitemframelzy.h"
#include "ui_groupitemframelzy.h"

GroupItemFrameLzy::GroupItemFrameLzy(GroupLzy* group, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::GroupItemFrameLzy)
{
    this->group = group;
    ui->setupUi(this);

    ui->name->setText(group->getName());
    ui->id->setText(QString::number(group->getGroupId()));

    QPixmap groupAvatar(":/images/default_group_avatar.png");
    if (!groupAvatar.isNull()) {
        groupAvatar = groupAvatar.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPixmap roundedAvatar(50, 50);
        roundedAvatar.fill(Qt::transparent);

        QPainter painter(&roundedAvatar);
        painter.setRenderHint(QPainter::Antialiasing);
        QPainterPath path;
        path.addEllipse(0, 0, 50, 50);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, groupAvatar);

        ui->avatar->setPixmap(roundedAvatar);
    }

    this->setStyleSheet("QFrame {"
                        "border-radius: 12px;"
                        "background-color: #ffffff;"
                        "border: 1px solid #e0e0e0;"
                        "padding: 8px;"
                        "box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);"
                        "}");

    this->setProperty("groupId",group->getGroupId());
}

GroupItemFrameLzy::~GroupItemFrameLzy() {
    delete ui;
}

void GroupItemFrameLzy::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked(group);
        qDebug() << "群组信息栏被点击";
    }
    QFrame::mousePressEvent(event);
}
