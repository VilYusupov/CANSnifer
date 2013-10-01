/********************************************************************************
** Form generated from reading UI file 'cansnifer.ui'
**
** Created: Wed 28. Aug 20:17:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANSNIFER_H
#define UI_CANSNIFER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CANSniferClass
{
public:

    void setupUi(QWidget *CANSniferClass)
    {
        if (CANSniferClass->objectName().isEmpty())
            CANSniferClass->setObjectName(QString::fromUtf8("CANSniferClass"));
        CANSniferClass->resize(400, 300);

        retranslateUi(CANSniferClass);

        QMetaObject::connectSlotsByName(CANSniferClass);
    } // setupUi

    void retranslateUi(QWidget *CANSniferClass)
    {
        CANSniferClass->setWindowTitle(QApplication::translate("CANSniferClass", "CANSnifer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CANSniferClass: public Ui_CANSniferClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANSNIFER_H
