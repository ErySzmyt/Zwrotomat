/********************************************************************************
** Form generated from reading UI file 'eksport.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EKSPORT_H
#define UI_EKSPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eksport
{
public:
    QLabel *label;
    QPushButton *chooseButton;
    QLabel *f_path;
    QPushButton *export_2;

    void setupUi(QWidget *eksport)
    {
        if (eksport->objectName().isEmpty())
            eksport->setObjectName(QString::fromUtf8("eksport"));
        eksport->resize(400, 300);
        label = new QLabel(eksport);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 81, 16));
        chooseButton = new QPushButton(eksport);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(30, 60, 80, 21));
        f_path = new QLabel(eksport);
        f_path->setObjectName(QString::fromUtf8("f_path"));
        f_path->setGeometry(QRect(130, 60, 251, 16));
        export_2 = new QPushButton(eksport);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setGeometry(QRect(30, 110, 80, 21));

        retranslateUi(eksport);

        QMetaObject::connectSlotsByName(eksport);
    } // setupUi

    void retranslateUi(QWidget *eksport)
    {
        eksport->setWindowTitle(QCoreApplication::translate("eksport", "Form", nullptr));
        label->setText(QCoreApplication::translate("eksport", "Wybierz Folder", nullptr));
        chooseButton->setText(QCoreApplication::translate("eksport", "Wybierz", nullptr));
        f_path->setText(QCoreApplication::translate("eksport", "Folder", nullptr));
        export_2->setText(QCoreApplication::translate("eksport", "Eksportuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eksport: public Ui_eksport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EKSPORT_H
