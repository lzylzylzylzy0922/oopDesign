/********************************************************************************
** Form generated from reading UI file 'welcomepagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEPAGELZY_H
#define UI_WELCOMEPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcomePageLzy
{
public:
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *loginButton;
    QLineEdit *qqAccount;
    QLineEdit *wechatAccount;
    QLineEdit *weiboAccount;
    QPushButton *registerButton;
    QLineEdit *passwordEdit;
    QLabel *label_3;
    QCheckBox *pwdVisual;
    QLabel *reminderLabel;

    void setupUi(QWidget *welcomePageLzy)
    {
        if (welcomePageLzy->objectName().isEmpty())
            welcomePageLzy->setObjectName("welcomePageLzy");
        welcomePageLzy->resize(600, 600);
        welcomePageLzy->setMaximumSize(QSize(600, 600));
        label = new QLabel(welcomePageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 80, 40, 12));
        label_2 = new QLabel(welcomePageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 130, 141, 20));
        radioButton = new QRadioButton(welcomePageLzy);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(170, 180, 72, 16));
        radioButton_2 = new QRadioButton(welcomePageLzy);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(170, 210, 72, 16));
        radioButton_3 = new QRadioButton(welcomePageLzy);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(170, 240, 72, 16));
        loginButton = new QPushButton(welcomePageLzy);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(270, 370, 71, 21));
        qqAccount = new QLineEdit(welcomePageLzy);
        qqAccount->setObjectName("qqAccount");
        qqAccount->setGeometry(QRect(250, 180, 113, 20));
        wechatAccount = new QLineEdit(welcomePageLzy);
        wechatAccount->setObjectName("wechatAccount");
        wechatAccount->setGeometry(QRect(250, 210, 113, 20));
        weiboAccount = new QLineEdit(welcomePageLzy);
        weiboAccount->setObjectName("weiboAccount");
        weiboAccount->setGeometry(QRect(250, 240, 113, 20));
        registerButton = new QPushButton(welcomePageLzy);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(450, 460, 81, 21));
        passwordEdit = new QLineEdit(welcomePageLzy);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(250, 300, 113, 20));
        label_3 = new QLabel(welcomePageLzy);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 300, 61, 21));
        pwdVisual = new QCheckBox(welcomePageLzy);
        pwdVisual->setObjectName("pwdVisual");
        pwdVisual->setGeometry(QRect(390, 290, 91, 41));
        reminderLabel = new QLabel(welcomePageLzy);
        reminderLabel->setObjectName("reminderLabel");
        reminderLabel->setGeometry(QRect(250, 330, 141, 16));

        retranslateUi(welcomePageLzy);

        QMetaObject::connectSlotsByName(welcomePageLzy);
    } // setupUi

    void retranslateUi(QWidget *welcomePageLzy)
    {
        welcomePageLzy->setWindowTitle(QCoreApplication::translate("welcomePageLzy", "welcomePageLzy", nullptr));
        label->setText(QCoreApplication::translate("welcomePageLzy", "Qchat", nullptr));
        label_2->setText(QCoreApplication::translate("welcomePageLzy", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\347\231\273\345\275\225\347\232\204\345\272\224\347\224\250", nullptr));
        radioButton->setText(QCoreApplication::translate("welcomePageLzy", "QID", nullptr));
        radioButton_2->setText(QCoreApplication::translate("welcomePageLzy", "WeChatID", nullptr));
        radioButton_3->setText(QCoreApplication::translate("welcomePageLzy", "WeiBoID", nullptr));
        loginButton->setText(QCoreApplication::translate("welcomePageLzy", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("welcomePageLzy", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("welcomePageLzy", "\345\257\206\347\240\201", nullptr));
        pwdVisual->setText(QCoreApplication::translate("welcomePageLzy", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        reminderLabel->setText(QCoreApplication::translate("welcomePageLzy", "<html><head/><body><p><span style=\" color:#ff0000;\">\345\257\206\347\240\201\350\207\263\345\260\221\345\205\255\344\275\215\344\270\224\345\214\205\345\220\253\346\225\260\345\255\227\345\222\214\345\255\227\346\257\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomePageLzy: public Ui_welcomePageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEPAGELZY_H
