#ifndef WELCOMEPAGELZY_H
#define WELCOMEPAGELZY_H

#include <QWidget>
#include <QDebug>
#include <utilsLzy.h>
#include<databaseconnectionlzy.h>

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
    friend class databaseConnectionLzy;
private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void updateEchoMode();


    void on_passwordEdit_editingFinished();

    void on_loginButton_clicked();

private:
    Ui::welcomePageLzy *ui;
};
#endif // WELCOMEPAGELZY_H
