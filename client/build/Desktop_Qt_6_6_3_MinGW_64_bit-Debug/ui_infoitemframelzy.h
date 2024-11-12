/********************************************************************************
** Form generated from reading UI file 'infoitemframelzy.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOITEMFRAMELZY_H
#define UI_INFOITEMFRAMELZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_infoItemFrameLzy
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *avatar;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *id;

    void setupUi(QFrame *infoItemFrameLzy)
    {
        if (infoItemFrameLzy->objectName().isEmpty())
            infoItemFrameLzy->setObjectName("infoItemFrameLzy");
        infoItemFrameLzy->resize(200, 60);
        horizontalLayout = new QHBoxLayout(infoItemFrameLzy);
        horizontalLayout->setObjectName("horizontalLayout");
        avatar = new QLabel(infoItemFrameLzy);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(40, 40));
        avatar->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(avatar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        name = new QLabel(infoItemFrameLzy);
        name->setObjectName("name");

        verticalLayout->addWidget(name);

        id = new QLabel(infoItemFrameLzy);
        id->setObjectName("id");

        verticalLayout->addWidget(id);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(infoItemFrameLzy);

        QMetaObject::connectSlotsByName(infoItemFrameLzy);
    } // setupUi

    void retranslateUi(QFrame *infoItemFrameLzy)
    {
        infoItemFrameLzy->setStyleSheet(QCoreApplication::translate("infoItemFrameLzy", "\n"
"      QFrame {\n"
"          background-color: #f0f0f0;\n"
"          border-radius: 10px;\n"
"          border: 1px solid #dcdcdc;\n"
"          padding: 5px;\n"
"      }\n"
"   ", nullptr));
        avatar->setStyleSheet(QCoreApplication::translate("infoItemFrameLzy", "\n"
"         QLabel {\n"
"             border-radius: 20px;\n"
"             border: 2px solid #cccccc;\n"
"             background-color: #ffffff;\n"
"         }\n"
"      ", nullptr));
        avatar->setText(QString());
        name->setStyleSheet(QCoreApplication::translate("infoItemFrameLzy", "\n"
"           QLabel {\n"
"               font-size: 14px;\n"
"               color: #333333;\n"
"               font-weight: bold;\n"
"           }\n"
"        ", nullptr));
        name->setText(QCoreApplication::translate("infoItemFrameLzy", "Username", nullptr));
        id->setStyleSheet(QCoreApplication::translate("infoItemFrameLzy", "\n"
"           QLabel {\n"
"               font-size: 12px;\n"
"               color: #666666;\n"
"           }\n"
"        ", nullptr));
        id->setText(QCoreApplication::translate("infoItemFrameLzy", "UserID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoItemFrameLzy: public Ui_infoItemFrameLzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOITEMFRAMELZY_H
