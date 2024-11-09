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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPageLzy
{
public:
    QFrame *personalInfoframe;
    QLabel *avatarLabel;
    QLabel *nicknameLabel;
    QFrame *line;
    QLabel *accountIdLabel;
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
        personalInfoframe = new QFrame(MainPageLzy);
        personalInfoframe->setObjectName("personalInfoframe");
        personalInfoframe->setGeometry(QRect(10, 10, 381, 71));
        personalInfoframe->setFrameShape(QFrame::Shape::StyledPanel);
        personalInfoframe->setFrameShadow(QFrame::Shadow::Raised);
        avatarLabel = new QLabel(personalInfoframe);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setGeometry(QRect(20, 20, 40, 12));
        nicknameLabel = new QLabel(personalInfoframe);
        nicknameLabel->setObjectName("nicknameLabel");
        nicknameLabel->setGeometry(QRect(100, 10, 40, 12));
        line = new QFrame(personalInfoframe);
        line->setObjectName("line");
        line->setGeometry(QRect(100, 30, 101, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        accountIdLabel = new QLabel(personalInfoframe);
        accountIdLabel->setObjectName("accountIdLabel");
        accountIdLabel->setGeometry(QRect(100, 50, 40, 12));
        tabWidget = new QTabWidget(MainPageLzy);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 90, 351, 501));
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
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 600, 60, 22));

        retranslateUi(MainPageLzy);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainPageLzy);
    } // setupUi

    void retranslateUi(QWidget *MainPageLzy)
    {
        MainPageLzy->setWindowTitle(QCoreApplication::translate("MainPageLzy", "Form", nullptr));
        avatarLabel->setText(QCoreApplication::translate("MainPageLzy", "avatarLabel", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("MainPageLzy", "nicknameLabel", nullptr));
        accountIdLabel->setText(QCoreApplication::translate("MainPageLzy", "accountIdLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(messageTab), QCoreApplication::translate("MainPageLzy", "\346\266\210\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(contactsTab), QCoreApplication::translate("MainPageLzy", "\350\201\224\347\263\273\344\272\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainPageLzy", "\345\217\221\350\265\267\347\276\244\350\201\212", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainPageLzy", "\346\267\273\345\212\240\347\276\244\350\201\212", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainPageLzy", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainPageLzy", "\347\273\221\345\256\232\350\264\246\346\210\267", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainPageLzy", "\346\263\250\351\224\200\350\264\246\345\217\267", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainPageLzy: public Ui_MainPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGELZY_H
