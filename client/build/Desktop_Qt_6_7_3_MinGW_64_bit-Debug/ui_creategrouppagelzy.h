/********************************************************************************
** Form generated from reading UI file 'creategrouppagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPPAGELZY_H
#define UI_CREATEGROUPPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupPageLzy
{
public:
    QLabel *label;
    QLabel *avatarLabel;
    QPushButton *uploadAvatarButton;
    QPushButton *invitFriendButton;
    QPushButton *createGroupButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *groupName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *groupId;

    void setupUi(QWidget *CreateGroupPageLzy)
    {
        if (CreateGroupPageLzy->objectName().isEmpty())
            CreateGroupPageLzy->setObjectName("CreateGroupPageLzy");
        CreateGroupPageLzy->resize(413, 280);
        label = new QLabel(CreateGroupPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 30, 61, 31));
        avatarLabel = new QLabel(CreateGroupPageLzy);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setGeometry(QRect(190, 90, 40, 12));
        uploadAvatarButton = new QPushButton(CreateGroupPageLzy);
        uploadAvatarButton->setObjectName("uploadAvatarButton");
        uploadAvatarButton->setGeometry(QRect(320, 90, 56, 18));
        invitFriendButton = new QPushButton(CreateGroupPageLzy);
        invitFriendButton->setObjectName("invitFriendButton");
        invitFriendButton->setGeometry(QRect(170, 230, 56, 18));
        createGroupButton = new QPushButton(CreateGroupPageLzy);
        createGroupButton->setObjectName("createGroupButton");
        createGroupButton->setGeometry(QRect(170, 200, 56, 18));
        widget = new QWidget(CreateGroupPageLzy);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 140, 149, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        groupName = new QLineEdit(widget);
        groupName->setObjectName("groupName");

        horizontalLayout->addWidget(groupName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        groupId = new QLineEdit(widget);
        groupId->setObjectName("groupId");

        horizontalLayout_2->addWidget(groupId);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CreateGroupPageLzy);

        QMetaObject::connectSlotsByName(CreateGroupPageLzy);
    } // setupUi

    void retranslateUi(QWidget *CreateGroupPageLzy)
    {
        CreateGroupPageLzy->setWindowTitle(QCoreApplication::translate("CreateGroupPageLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateGroupPageLzy", "\345\210\233\345\273\272\347\276\244\350\201\212\347\225\214\351\235\242", nullptr));
        avatarLabel->setText(QCoreApplication::translate("CreateGroupPageLzy", "\347\276\244\345\244\264\345\203\217", nullptr));
        uploadAvatarButton->setText(QCoreApplication::translate("CreateGroupPageLzy", "\344\270\212\344\274\240\347\276\244\345\244\264\345\203\217", nullptr));
        invitFriendButton->setText(QCoreApplication::translate("CreateGroupPageLzy", "\351\202\200\350\257\267\345\245\275\345\217\213", nullptr));
        createGroupButton->setText(QCoreApplication::translate("CreateGroupPageLzy", "\345\210\233\345\273\272\347\276\244\350\201\212", nullptr));
        label_2->setText(QCoreApplication::translate("CreateGroupPageLzy", "\347\276\244\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CreateGroupPageLzy", "\347\276\244\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupPageLzy: public Ui_CreateGroupPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPPAGELZY_H
