#ifndef INFOITEMFRAMELZY_H
#define INFOITEMFRAMELZY_H

#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include<QMouseEvent>
#include<AccountLzy.h>
#include<userdaolzy.h>

namespace Ui {
class infoItemFrameLzy;
}

class infoItemFrameLzy : public QFrame {
    Q_OBJECT

public:
    explicit infoItemFrameLzy(AccountLzy* account,QString name, QString id, QString avatarPath, QWidget *parent = nullptr);
    ~infoItemFrameLzy();

private:
    Ui::infoItemFrameLzy *ui;
    AccountLzy* account;//资料卡上的人
    QString accountId;

    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked(AccountLzy* account,AccountLzy* friendAccount);
};

#endif // INFOITEMFRAMELZY_H
