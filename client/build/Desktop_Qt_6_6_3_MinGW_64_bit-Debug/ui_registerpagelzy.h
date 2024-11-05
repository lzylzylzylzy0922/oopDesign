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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterPageLzy
{
public:
    QLabel *label_2;
    QLabel *label;
    QComboBox *locationBox;
    QPushButton *registerButton;
    QPushButton *openWelcomePageButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *qqRadioButton;
    QRadioButton *wechatRadioButton;
    QRadioButton *weiboRadioButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *phoneNumberEdit;
    QLineEdit *nicknameEdit;
    QLineEdit *birthEdit;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *passwordEdit;
    QLineEdit *verifyPasswordEdit;
    QLabel *reminderLabel;
    QCheckBox *pwdVisual;
    QLabel *reminderPasswordLabel;

    void setupUi(QWidget *RegisterPageLzy)
    {
        if (RegisterPageLzy->objectName().isEmpty())
            RegisterPageLzy->setObjectName("RegisterPageLzy");
        RegisterPageLzy->resize(581, 461);
        label_2 = new QLabel(RegisterPageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 40, 141, 20));
        label = new QLabel(RegisterPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 20, 40, 12));
        locationBox = new QComboBox(RegisterPageLzy);
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->addItem(QString());
        locationBox->setObjectName("locationBox");
        locationBox->setGeometry(QRect(260, 230, 121, 21));
        registerButton = new QPushButton(RegisterPageLzy);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(280, 380, 56, 18));
        openWelcomePageButton = new QPushButton(RegisterPageLzy);
        openWelcomePageButton->setObjectName("openWelcomePageButton");
        openWelcomePageButton->setGeometry(QRect(420, 410, 91, 21));
        layoutWidget = new QWidget(RegisterPageLzy);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 80, 451, 18));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        qqRadioButton = new QRadioButton(layoutWidget);
        qqRadioButton->setObjectName("qqRadioButton");

        horizontalLayout->addWidget(qqRadioButton);

        wechatRadioButton = new QRadioButton(layoutWidget);
        wechatRadioButton->setObjectName("wechatRadioButton");

        horizontalLayout->addWidget(wechatRadioButton);

        weiboRadioButton = new QRadioButton(layoutWidget);
        weiboRadioButton->setObjectName("weiboRadioButton");

        horizontalLayout->addWidget(weiboRadioButton);

        layoutWidget1 = new QWidget(RegisterPageLzy);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(190, 110, 38, 231));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        layoutWidget2 = new QWidget(RegisterPageLzy);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(260, 110, 128, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        phoneNumberEdit = new QLineEdit(layoutWidget2);
        phoneNumberEdit->setObjectName("phoneNumberEdit");

        verticalLayout_2->addWidget(phoneNumberEdit);

        nicknameEdit = new QLineEdit(layoutWidget2);
        nicknameEdit->setObjectName("nicknameEdit");

        verticalLayout_2->addWidget(nicknameEdit);

        birthEdit = new QLineEdit(layoutWidget2);
        birthEdit->setObjectName("birthEdit");

        verticalLayout_2->addWidget(birthEdit);

        layoutWidget3 = new QWidget(RegisterPageLzy);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(260, 270, 116, 71));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        passwordEdit = new QLineEdit(layoutWidget3);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout_3->addWidget(passwordEdit);

        verifyPasswordEdit = new QLineEdit(layoutWidget3);
        verifyPasswordEdit->setObjectName("verifyPasswordEdit");

        verticalLayout_3->addWidget(verifyPasswordEdit);

        reminderLabel = new QLabel(RegisterPageLzy);
        reminderLabel->setObjectName("reminderLabel");
        reminderLabel->setGeometry(QRect(400, 110, 126, 40));
        pwdVisual = new QCheckBox(RegisterPageLzy);
        pwdVisual->setObjectName("pwdVisual");
        pwdVisual->setGeometry(QRect(410, 280, 91, 41));
        reminderPasswordLabel = new QLabel(RegisterPageLzy);
        reminderPasswordLabel->setObjectName("reminderPasswordLabel");
        reminderPasswordLabel->setGeometry(QRect(260, 350, 141, 16));

        retranslateUi(RegisterPageLzy);

        QMetaObject::connectSlotsByName(RegisterPageLzy);
    } // setupUi

    void retranslateUi(QWidget *RegisterPageLzy)
    {
        RegisterPageLzy->setWindowTitle(QCoreApplication::translate("RegisterPageLzy", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterPageLzy", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\346\263\250\345\206\214\347\232\204\345\272\224\347\224\250", nullptr));
        label->setText(QCoreApplication::translate("RegisterPageLzy", "Qchat", nullptr));
        locationBox->setItemText(0, QCoreApplication::translate("RegisterPageLzy", "\351\273\221\351\276\231\346\261\237\347\234\201", nullptr));
        locationBox->setItemText(1, QCoreApplication::translate("RegisterPageLzy", "\350\276\275\345\256\201\347\234\201", nullptr));
        locationBox->setItemText(2, QCoreApplication::translate("RegisterPageLzy", "\345\220\211\346\236\227\347\234\201", nullptr));
        locationBox->setItemText(3, QCoreApplication::translate("RegisterPageLzy", "\346\262\263\345\214\227\347\234\201", nullptr));
        locationBox->setItemText(4, QCoreApplication::translate("RegisterPageLzy", "\346\262\263\345\215\227\347\234\201", nullptr));
        locationBox->setItemText(5, QCoreApplication::translate("RegisterPageLzy", "\346\271\226\345\214\227\347\234\201", nullptr));
        locationBox->setItemText(6, QCoreApplication::translate("RegisterPageLzy", "\346\271\226\345\215\227\347\234\201", nullptr));
        locationBox->setItemText(7, QCoreApplication::translate("RegisterPageLzy", "\345\261\261\344\270\234\347\234\201", nullptr));
        locationBox->setItemText(8, QCoreApplication::translate("RegisterPageLzy", "\345\261\261\350\245\277\347\234\201", nullptr));
        locationBox->setItemText(9, QCoreApplication::translate("RegisterPageLzy", "\351\231\225\350\245\277\347\234\201", nullptr));
        locationBox->setItemText(10, QCoreApplication::translate("RegisterPageLzy", "\345\256\211\345\276\275\347\234\201", nullptr));
        locationBox->setItemText(11, QCoreApplication::translate("RegisterPageLzy", "\346\265\231\346\261\237\347\234\201", nullptr));
        locationBox->setItemText(12, QCoreApplication::translate("RegisterPageLzy", "\346\261\237\350\213\217\347\234\201", nullptr));
        locationBox->setItemText(13, QCoreApplication::translate("RegisterPageLzy", "\347\246\217\345\273\272\347\234\201", nullptr));
        locationBox->setItemText(14, QCoreApplication::translate("RegisterPageLzy", "\345\271\277\344\270\234\347\234\201", nullptr));
        locationBox->setItemText(15, QCoreApplication::translate("RegisterPageLzy", "\346\265\267\345\215\227\347\234\201", nullptr));
        locationBox->setItemText(16, QCoreApplication::translate("RegisterPageLzy", "\345\233\233\345\267\235\347\234\201", nullptr));
        locationBox->setItemText(17, QCoreApplication::translate("RegisterPageLzy", "\344\272\221\345\215\227\347\234\201", nullptr));
        locationBox->setItemText(18, QCoreApplication::translate("RegisterPageLzy", "\350\264\265\345\267\236\347\234\201", nullptr));
        locationBox->setItemText(19, QCoreApplication::translate("RegisterPageLzy", "\351\235\222\346\265\267\347\234\201", nullptr));
        locationBox->setItemText(20, QCoreApplication::translate("RegisterPageLzy", "\347\224\230\350\202\203\347\234\201", nullptr));
        locationBox->setItemText(21, QCoreApplication::translate("RegisterPageLzy", "\346\261\237\350\245\277\347\234\201", nullptr));
        locationBox->setItemText(22, QCoreApplication::translate("RegisterPageLzy", "\345\217\260\346\271\276\347\234\201", nullptr));
        locationBox->setItemText(23, QCoreApplication::translate("RegisterPageLzy", "\345\206\205\350\222\231\345\217\244", nullptr));
        locationBox->setItemText(24, QCoreApplication::translate("RegisterPageLzy", "\345\256\201\345\244\217\345\233\236\346\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        locationBox->setItemText(25, QCoreApplication::translate("RegisterPageLzy", "\346\226\260\345\273\272\347\273\264\345\220\276\345\260\224\350\207\252\346\262\273\345\214\272", nullptr));
        locationBox->setItemText(26, QCoreApplication::translate("RegisterPageLzy", "\350\245\277\350\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        locationBox->setItemText(27, QCoreApplication::translate("RegisterPageLzy", "\345\271\277\350\245\277\345\243\256\346\227\217\350\207\252\346\262\273\345\214\272", nullptr));
        locationBox->setItemText(28, QCoreApplication::translate("RegisterPageLzy", "\345\214\227\344\272\254\345\270\202", nullptr));
        locationBox->setItemText(29, QCoreApplication::translate("RegisterPageLzy", "\344\270\212\346\265\267\345\270\202", nullptr));
        locationBox->setItemText(30, QCoreApplication::translate("RegisterPageLzy", "\345\244\251\346\264\245\345\270\202", nullptr));
        locationBox->setItemText(31, QCoreApplication::translate("RegisterPageLzy", "\351\207\215\345\272\206\345\270\202", nullptr));
        locationBox->setItemText(32, QCoreApplication::translate("RegisterPageLzy", "\351\246\231\346\270\257\347\211\271\345\210\253\350\241\214\346\224\277\345\214\272", nullptr));
        locationBox->setItemText(33, QCoreApplication::translate("RegisterPageLzy", "\346\276\263\351\227\250\347\211\271\345\210\253\350\241\214\346\224\277\345\214\272", nullptr));

        registerButton->setText(QCoreApplication::translate("RegisterPageLzy", "\346\263\250\345\206\214", nullptr));
        openWelcomePageButton->setText(QCoreApplication::translate("RegisterPageLzy", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        qqRadioButton->setText(QCoreApplication::translate("RegisterPageLzy", "QQ", nullptr));
        wechatRadioButton->setText(QCoreApplication::translate("RegisterPageLzy", "WeChat", nullptr));
        weiboRadioButton->setText(QCoreApplication::translate("RegisterPageLzy", "WeiBo", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterPageLzy", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterPageLzy", "\346\230\265\347\247\260", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterPageLzy", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterPageLzy", "\346\211\200\345\234\250\345\234\260", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterPageLzy", "\350\256\276\347\275\256\345\257\206\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterPageLzy", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        reminderLabel->setText(QCoreApplication::translate("RegisterPageLzy", "<html><head/><body><p><span style=\" color:#ff0000;\">\346\211\213\346\234\272\345\217\267\346\240\274\345\274\217\351\224\231\350\257\257</span></p></body></html>", nullptr));
        pwdVisual->setText(QCoreApplication::translate("RegisterPageLzy", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        reminderPasswordLabel->setText(QCoreApplication::translate("RegisterPageLzy", "<html><head/><body><p><span style=\" color:#ff0000;\">\345\257\206\347\240\201\350\207\263\345\260\221\345\205\255\344\275\215\344\270\224\345\214\205\345\220\253\346\225\260\345\255\227\345\222\214\345\255\227\346\257\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterPageLzy: public Ui_RegisterPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGELZY_H
