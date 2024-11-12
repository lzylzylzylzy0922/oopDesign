/********************************************************************************
** Form generated from reading UI file 'mainpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGELZY_H
#define UI_MAINPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPageLzy
{
public:
    QWidget *personalInfowidget;
    QTabWidget *tabWidget;
    QWidget *messageTab;
    QScrollArea *messageArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *contactsTab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QComboBox *comboBox;

    void setupUi(QWidget *MainPageLzy)
    {
        if (MainPageLzy->objectName().isEmpty())
            MainPageLzy->setObjectName("MainPageLzy");
        MainPageLzy->resize(400, 630);
        MainPageLzy->setMinimumSize(QSize(400, 630));
        MainPageLzy->setMaximumSize(QSize(400, 630));
        personalInfowidget = new QWidget(MainPageLzy);
        personalInfowidget->setObjectName("personalInfowidget");
        personalInfowidget->setGeometry(QRect(10, 10, 381, 111));
        tabWidget = new QTabWidget(MainPageLzy);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 140, 351, 451));
        messageTab = new QWidget();
        messageTab->setObjectName("messageTab");
        messageArea = new QScrollArea(messageTab);
        messageArea->setObjectName("messageArea");
        messageArea->setGeometry(QRect(0, 0, 341, 471));
        messageArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 469));
        messageArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(messageTab, QString());
        contactsTab = new QWidget();
        contactsTab->setObjectName("contactsTab");
        scrollArea = new QScrollArea(contactsTab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 341, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 339, 469));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(contactsTab, QString());
        comboBox = new QComboBox(MainPageLzy);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 600, 101, 22));

        retranslateUi(MainPageLzy);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainPageLzy);
    } // setupUi

    void retranslateUi(QWidget *MainPageLzy)
    {
        MainPageLzy->setWindowTitle(QCoreApplication::translate("MainPageLzy", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(messageTab), QCoreApplication::translate("MainPageLzy", "\346\266\210\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(contactsTab), QCoreApplication::translate("MainPageLzy", "\350\201\224\347\263\273\344\272\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainPageLzy", "\345\217\221\350\265\267\347\276\244\350\201\212", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainPageLzy", "\346\267\273\345\212\240\345\245\275\345\217\213/\347\276\244\350\201\212", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainPageLzy", "\347\273\221\345\256\232\350\264\246\346\210\267", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainPageLzy", "\346\263\250\351\224\200\350\264\246\345\217\267", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainPageLzy: public Ui_MainPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGELZY_H
