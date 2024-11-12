/********************************************************************************
** Form generated from reading UI file 'searchpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPAGELZY_H
#define UI_SEARCHPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchPageLzy
{
public:
    QLineEdit *idEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *searchButton;
    QLabel *label_3;
    QScrollArea *userScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_4;
    QScrollArea *groupScrollArea;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *SearchPageLzy)
    {
        if (SearchPageLzy->objectName().isEmpty())
            SearchPageLzy->setObjectName("SearchPageLzy");
        SearchPageLzy->resize(400, 556);
        idEdit = new QLineEdit(SearchPageLzy);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(110, 60, 201, 21));
        label = new QLabel(SearchPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 30, 91, 21));
        label_2 = new QLabel(SearchPageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 60, 51, 20));
        searchButton = new QPushButton(SearchPageLzy);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(320, 60, 56, 18));
        label_3 = new QLabel(SearchPageLzy);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 100, 40, 12));
        userScrollArea = new QScrollArea(SearchPageLzy);
        userScrollArea->setObjectName("userScrollArea");
        userScrollArea->setGeometry(QRect(110, 100, 231, 271));
        userScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 269));
        userScrollArea->setWidget(scrollAreaWidgetContents);
        label_4 = new QLabel(SearchPageLzy);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 400, 40, 12));
        groupScrollArea = new QScrollArea(SearchPageLzy);
        groupScrollArea->setObjectName("groupScrollArea");
        groupScrollArea->setGeometry(QRect(110, 400, 231, 80));
        groupScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 229, 78));
        groupScrollArea->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(SearchPageLzy);

        QMetaObject::connectSlotsByName(SearchPageLzy);
    } // setupUi

    void retranslateUi(QWidget *SearchPageLzy)
    {
        SearchPageLzy->setWindowTitle(QCoreApplication::translate("SearchPageLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("SearchPageLzy", "<html><head/><body><p align=\"center\">\346\237\245\346\211\276\347\224\250\346\210\267\345\222\214\347\276\244\350\201\212</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SearchPageLzy", "ID\345\217\267/\347\276\244\345\217\267\357\274\232", nullptr));
        searchButton->setText(QCoreApplication::translate("SearchPageLzy", "\346\237\245\346\211\276", nullptr));
        label_3->setText(QCoreApplication::translate("SearchPageLzy", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SearchPageLzy", "\347\276\244\350\201\212\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchPageLzy: public Ui_SearchPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPAGELZY_H
