/********************************************************************************
** Form generated from reading UI file 'userinfowidgetlzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWIDGETLZY_H
#define UI_USERINFOWIDGETLZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_UserInfoWidgetLzy
{
public:
    QLabel *avatorLabel;
    QLabel *nicknameLabel;
    QLabel *accountIdLabel;

    void setupUi(QFrame *UserInfoWidgetLzy)
    {
        if (UserInfoWidgetLzy->objectName().isEmpty())
            UserInfoWidgetLzy->setObjectName("UserInfoWidgetLzy");
        UserInfoWidgetLzy->resize(294, 37);
        avatorLabel = new QLabel(UserInfoWidgetLzy);
        avatorLabel->setObjectName("avatorLabel");
        avatorLabel->setGeometry(QRect(20, 10, 40, 12));
        nicknameLabel = new QLabel(UserInfoWidgetLzy);
        nicknameLabel->setObjectName("nicknameLabel");
        nicknameLabel->setGeometry(QRect(90, 0, 40, 12));
        accountIdLabel = new QLabel(UserInfoWidgetLzy);
        accountIdLabel->setObjectName("accountIdLabel");
        accountIdLabel->setGeometry(QRect(90, 20, 40, 12));

        retranslateUi(UserInfoWidgetLzy);

        QMetaObject::connectSlotsByName(UserInfoWidgetLzy);
    } // setupUi

    void retranslateUi(QFrame *UserInfoWidgetLzy)
    {
        UserInfoWidgetLzy->setWindowTitle(QCoreApplication::translate("UserInfoWidgetLzy", "Frame", nullptr));
        avatorLabel->setText(QCoreApplication::translate("UserInfoWidgetLzy", "TextLabel", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("UserInfoWidgetLzy", "TextLabel", nullptr));
        accountIdLabel->setText(QCoreApplication::translate("UserInfoWidgetLzy", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWidgetLzy: public Ui_UserInfoWidgetLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWIDGETLZY_H
