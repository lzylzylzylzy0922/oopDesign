#ifndef REGISTERPAGELZY_H
#define REGISTERPAGELZY_H

#include <QWidget>

namespace Ui {
class RegisterPageLzy;
}

class RegisterPageLzy : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPageLzy(QWidget *parent = nullptr);
    ~RegisterPageLzy();

public slots:
    void recvSignal();

private:
    Ui::RegisterPageLzy *ui;


};

#endif // REGISTERPAGELZY_H
