#ifndef GROUPITEMFRAMELZY_H
#define GROUPITEMFRAMELZY_H

#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include "grouplzy.h"

namespace Ui {
class GroupItemFrameLzy;
}

class GroupItemFrameLzy : public QFrame {
    Q_OBJECT

public:
    explicit GroupItemFrameLzy(GroupLzy* group, QWidget *parent = nullptr);
    ~GroupItemFrameLzy();

private:
    Ui::GroupItemFrameLzy *ui;
    GroupLzy* group;
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked(GroupLzy* group);
};

#endif // GROUPITEMFRAMELZY_H
