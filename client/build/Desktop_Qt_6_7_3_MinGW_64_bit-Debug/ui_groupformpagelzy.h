/********************************************************************************
** Form generated from reading UI file 'groupformpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPFORMPAGELZY_H
#define UI_GROUPFORMPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupFormPageLzy
{
public:
    QWidget *container;
    QLineEdit *groupNameEdit;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLineEdit *groupIdEdit;
    QPushButton *sendMessageButton;
    QPushButton *exitButton;
    QPushButton *dissolveButton;
    QPushButton *tackleAdminButton;
    QPushButton *searchMemberButton;
    QPushButton *tackleMemberButton;
    QPushButton *joinGroupButton;

    void setupUi(QWidget *GroupFormPageLzy)
    {
        if (GroupFormPageLzy->objectName().isEmpty())
            GroupFormPageLzy->setObjectName("GroupFormPageLzy");
        GroupFormPageLzy->resize(408, 374);
        container = new QWidget(GroupFormPageLzy);
        container->setObjectName("container");
        container->setGeometry(QRect(50, 20, 271, 101));
        groupNameEdit = new QLineEdit(GroupFormPageLzy);
        groupNameEdit->setObjectName("groupNameEdit");
        groupNameEdit->setGeometry(QRect(130, 150, 131, 20));
        label = new QLabel(GroupFormPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 160, 40, 12));
        line = new QFrame(GroupFormPageLzy);
        line->setObjectName("line");
        line->setGeometry(QRect(30, 230, 341, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(GroupFormPageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 200, 40, 12));
        groupIdEdit = new QLineEdit(GroupFormPageLzy);
        groupIdEdit->setObjectName("groupIdEdit");
        groupIdEdit->setGeometry(QRect(130, 200, 131, 20));
        sendMessageButton = new QPushButton(GroupFormPageLzy);
        sendMessageButton->setObjectName("sendMessageButton");
        sendMessageButton->setGeometry(QRect(160, 270, 56, 18));
        exitButton = new QPushButton(GroupFormPageLzy);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(160, 300, 56, 18));
        dissolveButton = new QPushButton(GroupFormPageLzy);
        dissolveButton->setObjectName("dissolveButton");
        dissolveButton->setGeometry(QRect(160, 300, 56, 18));
        tackleAdminButton = new QPushButton(GroupFormPageLzy);
        tackleAdminButton->setObjectName("tackleAdminButton");
        tackleAdminButton->setGeometry(QRect(305, 297, 61, 21));
        searchMemberButton = new QPushButton(GroupFormPageLzy);
        searchMemberButton->setObjectName("searchMemberButton");
        searchMemberButton->setGeometry(QRect(300, 337, 71, 21));
        tackleMemberButton = new QPushButton(GroupFormPageLzy);
        tackleMemberButton->setObjectName("tackleMemberButton");
        tackleMemberButton->setGeometry(QRect(300, 260, 61, 21));
        joinGroupButton = new QPushButton(GroupFormPageLzy);
        joinGroupButton->setObjectName("joinGroupButton");
        joinGroupButton->setGeometry(QRect(160, 270, 56, 21));

        retranslateUi(GroupFormPageLzy);

        QMetaObject::connectSlotsByName(GroupFormPageLzy);
    } // setupUi

    void retranslateUi(QWidget *GroupFormPageLzy)
    {
        GroupFormPageLzy->setWindowTitle(QCoreApplication::translate("GroupFormPageLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("GroupFormPageLzy", "\347\276\244\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("GroupFormPageLzy", "\347\276\244\345\217\267\357\274\232", nullptr));
        sendMessageButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\345\217\221\344\277\241\346\201\257", nullptr));
        exitButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\351\200\200\345\207\272\347\276\244\350\201\212", nullptr));
        dissolveButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\350\247\243\346\225\243\347\276\244\350\201\212", nullptr));
        tackleAdminButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\345\244\204\347\220\206\347\256\241\347\220\206\345\221\230", nullptr));
        searchMemberButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\346\237\245\347\234\213\347\276\244\346\210\220\345\221\230", nullptr));
        tackleMemberButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\347\256\241\347\220\206\347\276\244\346\210\220\345\221\230", nullptr));
        joinGroupButton->setText(QCoreApplication::translate("GroupFormPageLzy", "\345\212\240\345\205\245\347\276\244\350\201\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupFormPageLzy: public Ui_GroupFormPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPFORMPAGELZY_H
