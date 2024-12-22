/********************************************************************************
** Form generated from reading UI file 'accountbindingpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTBINDINGPAGELZY_H
#define UI_ACCOUNTBINDINGPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountBindingPageLzy
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *unBindButton;

    void setupUi(QWidget *AccountBindingPageLzy)
    {
        if (AccountBindingPageLzy->objectName().isEmpty())
            AccountBindingPageLzy->setObjectName("AccountBindingPageLzy");
        AccountBindingPageLzy->resize(409, 341);
        label = new QLabel(AccountBindingPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 20, 71, 20));
        tableWidget = new QTableWidget(AccountBindingPageLzy);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 60, 361, 191));
        pushButton = new QPushButton(AccountBindingPageLzy);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 280, 56, 18));
        unBindButton = new QPushButton(AccountBindingPageLzy);
        unBindButton->setObjectName("unBindButton");
        unBindButton->setGeometry(QRect(210, 280, 56, 18));

        retranslateUi(AccountBindingPageLzy);

        QMetaObject::connectSlotsByName(AccountBindingPageLzy);
    } // setupUi

    void retranslateUi(QWidget *AccountBindingPageLzy)
    {
        AccountBindingPageLzy->setWindowTitle(QCoreApplication::translate("AccountBindingPageLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("AccountBindingPageLzy", "\345\267\262\345\274\200\351\200\232\344\270\232\345\212\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AccountBindingPageLzy", "\344\270\232\345\212\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AccountBindingPageLzy", "\350\264\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AccountBindingPageLzy", "\347\273\221\345\256\232\346\203\205\345\206\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AccountBindingPageLzy", "\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("AccountBindingPageLzy", "\347\273\221\345\256\232", nullptr));
        unBindButton->setText(QCoreApplication::translate("AccountBindingPageLzy", "\350\247\243\347\273\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountBindingPageLzy: public Ui_AccountBindingPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTBINDINGPAGELZY_H
