#ifndef INFOITEMFRAMELZY_H
#define INFOITEMFRAMELZY_H

#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include<QMouseEvent>
#include<AccountLzy.h>

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
    AccountLzy* account;
    QString accountId;


    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked(AccountLzy* account,const QString& accountId);
};

#endif // INFOITEMFRAMELZY_H
