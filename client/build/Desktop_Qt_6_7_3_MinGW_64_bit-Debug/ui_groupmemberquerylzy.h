/********************************************************************************
** Form generated from reading UI file 'groupmemberquerylzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMEMBERQUERYLZY_H
#define UI_GROUPMEMBERQUERYLZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupMemberQueryLzy
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *queryButton;

    void setupUi(QWidget *GroupMemberQueryLzy)
    {
        if (GroupMemberQueryLzy->objectName().isEmpty())
            GroupMemberQueryLzy->setObjectName("GroupMemberQueryLzy");
        GroupMemberQueryLzy->resize(268, 226);
        verticalLayout = new QVBoxLayout(GroupMemberQueryLzy);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(GroupMemberQueryLzy);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        queryButton = new QPushButton(GroupMemberQueryLzy);
        queryButton->setObjectName("queryButton");

        verticalLayout->addWidget(queryButton);


        retranslateUi(GroupMemberQueryLzy);

        QMetaObject::connectSlotsByName(GroupMemberQueryLzy);
    } // setupUi

    void retranslateUi(QWidget *GroupMemberQueryLzy)
    {
        GroupMemberQueryLzy->setWindowTitle(QCoreApplication::translate("GroupMemberQueryLzy", "Group Member Query", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GroupMemberQueryLzy", "Group ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GroupMemberQueryLzy", "User ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GroupMemberQueryLzy", "Role", nullptr));
        queryButton->setText(QCoreApplication::translate("GroupMemberQueryLzy", "\346\237\245\350\257\242\347\276\244\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupMemberQueryLzy: public Ui_GroupMemberQueryLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMEMBERQUERYLZY_H
