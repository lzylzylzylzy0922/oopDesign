/********************************************************************************
** Form generated from reading UI file 'groupitemframelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPITEMFRAMELZY_H
#define UI_GROUPITEMFRAMELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GroupItemFrameLzy
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *avatar;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *id;

    void setupUi(QFrame *GroupItemFrameLzy)
    {
        if (GroupItemFrameLzy->objectName().isEmpty())
            GroupItemFrameLzy->setObjectName("GroupItemFrameLzy");
        GroupItemFrameLzy->resize(220, 100);
        horizontalLayout = new QHBoxLayout(GroupItemFrameLzy);
        horizontalLayout->setObjectName("horizontalLayout");
        avatar = new QLabel(GroupItemFrameLzy);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(50, 50));
        avatar->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(avatar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        name = new QLabel(GroupItemFrameLzy);
        name->setObjectName("name");

        verticalLayout->addWidget(name);

        id = new QLabel(GroupItemFrameLzy);
        id->setObjectName("id");

        verticalLayout->addWidget(id);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(GroupItemFrameLzy);

        QMetaObject::connectSlotsByName(GroupItemFrameLzy);
    } // setupUi

    void retranslateUi(QFrame *GroupItemFrameLzy)
    {
        GroupItemFrameLzy->setStyleSheet(QCoreApplication::translate("GroupItemFrameLzy", "\n"
"      QFrame {\n"
"          background-color: #ffffff;\n"
"          border-radius: 12px;\n"
"          border: 1px solid #e0e0e0;\n"
"          padding: 8px;\n"
"          box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);\n"
"      }\n"
"   ", nullptr));
        avatar->setStyleSheet(QCoreApplication::translate("GroupItemFrameLzy", "\n"
"         QLabel {\n"
"             border-radius: 25px;\n"
"             border: 2px solid #cccccc;\n"
"             background-color: #f5f5f5;\n"
"         }\n"
"      ", nullptr));
        avatar->setText(QString());
        name->setStyleSheet(QCoreApplication::translate("GroupItemFrameLzy", "\n"
"           QLabel {\n"
"               font-size: 16px;\n"
"               color: #333333;\n"
"               font-weight: bold;\n"
"           }\n"
"        ", nullptr));
        name->setText(QCoreApplication::translate("GroupItemFrameLzy", "Group Name", nullptr));
        id->setStyleSheet(QCoreApplication::translate("GroupItemFrameLzy", "\n"
"           QLabel {\n"
"               font-size: 12px;\n"
"               color: #888888;\n"
"           }\n"
"        ", nullptr));
        id->setText(QCoreApplication::translate("GroupItemFrameLzy", "Group ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupItemFrameLzy: public Ui_GroupItemFrameLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPITEMFRAMELZY_H
