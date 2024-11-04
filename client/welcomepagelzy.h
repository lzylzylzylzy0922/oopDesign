#ifndef WELCOMEPAGELZY_H
#define WELCOMEPAGELZY_H

#include <QWidget>
#include <QDebug>
#include<QMessageBox>
#include <utilsLzy.h>
#include<userdaolzy.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class welcomePageLzy;
}
QT_END_NAMESPACE

class welcomePageLzy : public QWidget
{
    Q_OBJECT

public:
    welcomePageLzy(QWidget *parent = nullptr);
    ~welcomePageLzy();
    friend class utilsLzy;
    friend class userDaoLzy;

signals:
    void showRegisterPageLzy();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void updateEchoMode();


    void on_passwordEdit_editingFinished();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::welcomePageLzy *ui;
};
#endif // WELCOMEPAGELZY_H
