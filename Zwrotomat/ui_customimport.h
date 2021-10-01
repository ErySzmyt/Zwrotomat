/********************************************************************************
** Form generated from reading UI file 'customimport.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMIMPORT_H
#define UI_CUSTOMIMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomImport
{
public:
    QWidget *centralwidget;
    QPushButton *chooseButton;
    QPushButton *export_2;
    QLabel *label;
    QLabel *f_path;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CustomImport)
    {
        if (CustomImport->objectName().isEmpty())
            CustomImport->setObjectName(QString::fromUtf8("CustomImport"));
        CustomImport->resize(800, 600);
        centralwidget = new QWidget(CustomImport);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(50, 60, 80, 21));
        export_2 = new QPushButton(centralwidget);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setGeometry(QRect(50, 120, 80, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 81, 16));
        f_path = new QLabel(centralwidget);
        f_path->setObjectName(QString::fromUtf8("f_path"));
        f_path->setGeometry(QRect(150, 60, 251, 16));
        CustomImport->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CustomImport);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        CustomImport->setMenuBar(menubar);
        statusbar = new QStatusBar(CustomImport);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CustomImport->setStatusBar(statusbar);

        retranslateUi(CustomImport);

        QMetaObject::connectSlotsByName(CustomImport);
    } // setupUi

    void retranslateUi(QMainWindow *CustomImport)
    {
        CustomImport->setWindowTitle(QCoreApplication::translate("CustomImport", "MainWindow", nullptr));
        chooseButton->setText(QCoreApplication::translate("CustomImport", "Wybierz", nullptr));
        export_2->setText(QCoreApplication::translate("CustomImport", "Eksportuj", nullptr));
        label->setText(QCoreApplication::translate("CustomImport", "Wybierz Folder", nullptr));
        f_path->setText(QCoreApplication::translate("CustomImport", "Folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomImport: public Ui_CustomImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMIMPORT_H
