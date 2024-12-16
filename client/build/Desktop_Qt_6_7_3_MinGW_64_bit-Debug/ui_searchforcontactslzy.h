/********************************************************************************
** Form generated from reading UI file 'searchforcontactslzy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORCONTACTSLZY_H
#define UI_SEARCHFORCONTACTSLZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForContactsLzy
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *SearchForContactsLzy)
    {
        if (SearchForContactsLzy->objectName().isEmpty())
            SearchForContactsLzy->setObjectName("SearchForContactsLzy");
        SearchForContactsLzy->resize(362, 413);
        label = new QLabel(SearchForContactsLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 51, 20));
        tableWidget = new QTableWidget(SearchForContactsLzy);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 60, 331, 291));
        pushButton = new QPushButton(SearchForContactsLzy);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 370, 56, 18));

        retranslateUi(SearchForContactsLzy);

        QMetaObject::connectSlotsByName(SearchForContactsLzy);
    } // setupUi

    void retranslateUi(QWidget *SearchForContactsLzy)
    {
        SearchForContactsLzy->setWindowTitle(QCoreApplication::translate("SearchForContactsLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("SearchForContactsLzy", "\345\245\275\345\217\213\345\210\227\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("SearchForContactsLzy", "\351\202\200\350\257\267\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchForContactsLzy: public Ui_SearchForContactsLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORCONTACTSLZY_H
