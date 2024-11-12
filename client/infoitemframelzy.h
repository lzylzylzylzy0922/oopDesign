#ifndef INFOITEMFRAMELZY_H
#define INFOITEMFRAMELZY_H

#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>

namespace Ui {
class infoItemFrameLzy;
}

class infoItemFrameLzy : public QFrame {
    Q_OBJECT

public:
    explicit infoItemFrameLzy(QString name, QString id, QString avatarPath, QWidget *parent = nullptr);
    ~infoItemFrameLzy();

private:
    Ui::infoItemFrameLzy *ui;
};

#endif // INFOITEMFRAMELZY_H
