/********************************************************************************
** Form generated from reading UI file 'infoformpagelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOFORMPAGELZY_H
#define UI_INFOFORMPAGELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoFormPageLzy
{
public:
    QWidget *container;
    QFrame *line;
    QLineEdit *birthdayEdit;
    QLineEdit *locationEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *addFriendButton;
    QPushButton *sendMessageButton;

    void setupUi(QWidget *InfoFormPageLzy)
    {
        if (InfoFormPageLzy->objectName().isEmpty())
            InfoFormPageLzy->setObjectName("InfoFormPageLzy");
        InfoFormPageLzy->resize(400, 363);
        container = new QWidget(InfoFormPageLzy);
        container->setObjectName("container");
        container->setGeometry(QRect(50, 20, 271, 101));
        line = new QFrame(InfoFormPageLzy);
        line->setObjectName("line");
        line->setGeometry(QRect(30, 230, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        birthdayEdit = new QLineEdit(InfoFormPageLzy);
        birthdayEdit->setObjectName("birthdayEdit");
        birthdayEdit->setGeometry(QRect(130, 150, 131, 20));
        locationEdit = new QLineEdit(InfoFormPageLzy);
        locationEdit->setObjectName("locationEdit");
        locationEdit->setGeometry(QRect(130, 200, 131, 20));
        label = new QLabel(InfoFormPageLzy);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 160, 40, 12));
        label_2 = new QLabel(InfoFormPageLzy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 200, 40, 12));
        addFriendButton = new QPushButton(InfoFormPageLzy);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(170, 270, 56, 18));
        sendMessageButton = new QPushButton(InfoFormPageLzy);
        sendMessageButton->setObjectName("sendMessageButton");
        sendMessageButton->setGeometry(QRect(170, 300, 56, 18));

        retranslateUi(InfoFormPageLzy);

        QMetaObject::connectSlotsByName(InfoFormPageLzy);
    } // setupUi

    void retranslateUi(QWidget *InfoFormPageLzy)
    {
        InfoFormPageLzy->setWindowTitle(QCoreApplication::translate("InfoFormPageLzy", "Form", nullptr));
        label->setText(QCoreApplication::translate("InfoFormPageLzy", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("InfoFormPageLzy", "\346\211\200\345\234\250\345\234\260\357\274\232", nullptr));
        addFriendButton->setText(QCoreApplication::translate("InfoFormPageLzy", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        sendMessageButton->setText(QCoreApplication::translate("InfoFormPageLzy", "\345\217\221\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoFormPageLzy: public Ui_InfoFormPageLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOFORMPAGELZY_H
