/********************************************************************************
** Form generated from reading UI file 'registerpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGELZY_H
#define UI_REGISTERPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterPageLzy
{
public:
    QRadioButton *radioButton;
    QLineEdit *wechatAccount;
    QRadioButton *radioButton_3;
    QLabel *label_2;
    QLineEdit *qqAccount;
    QLineEdit *weiboAccount;
    QRadioButton *radioButton_2;
    QLabel *label;

    void setupUi(QWidget *RegisterPageLzy)
    {
        if (RegisterPageLzy->objectName().isEmpty())
            RegisterPageLzy->setObjectName("RegisterPageLzy");
        RegisterPageLzy->resize(560, 427);
        radioButton = new QRadioButton(RegisterPageLzy);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(50, 60, 72, 16));
        wechatAccount = new QLineEdit(RegisterPageLzy);
        wechatAccount->setObjectName("wechatAccount");
        wechatAccount->setGeometry(QRect(130, 90, 113, 20));
        radioButton_3 = new QRadioButton(RegisterPageLzy);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(50, 120, 72, 16));
        label_2 = new QLabel(RegisterPageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 30, 141, 20));
        qqAccount = new QLineEdit(RegisterPageLzy);
        qqAccount->setObjectName("qqAccount");
        qqAccount->setGeometry(QRect(130, 60, 113, 20));
        weiboAccount = new QLineEdit(RegisterPageLzy);
        weiboAccount->setObjectName("weiboAccount");
        weiboAccount->setGeometry(QRect(130, 120, 113, 20));
        radioButton_2 = new QRadioButton(RegisterPageLzy);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(50, 90, 72, 16));
        label = new QLabel(RegisterPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 10, 40, 12));

        retranslateUi(RegisterPageLzy);

        QMetaObject::connectSlotsByName(RegisterPageLzy);
    } // setupUi

    void retranslateUi(QWidget *RegisterPageLzy)
    {
        RegisterPageLzy->setWindowTitle(QCoreApplication::translate("RegisterPageLzy", "Form", nullptr));
        radioButton->setText(QCoreApplication::translate("RegisterPageLzy", "QID", nullptr));
        radioButton_3->setText(QCoreApplication::translate("RegisterPageLzy", "WeiBoID", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterPageLzy", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\346\263\250\345\206\214\347\232\204\345\272\224\347\224\250", nullptr));
        radioButton_2->setText(QCoreApplication::translate("RegisterPageLzy", "WeChatID", nullptr));
        label->setText(QCoreApplication::translate("RegisterPageLzy", "Qchat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterPageLzy: public Ui_RegisterPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGELZY_H
