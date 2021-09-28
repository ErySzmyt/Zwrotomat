/********************************************************************************
** Form generated from reading UI file 'eksporter.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EKSPORTER_H
#define UI_EKSPORTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Eksporter
{
public:
    QWidget *centralwidget;
    QLabel *f_path;
    QPushButton *export_2;
    QPushButton *chooseButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Eksporter)
    {
        if (Eksporter->objectName().isEmpty())
            Eksporter->setObjectName(QString::fromUtf8("Eksporter"));
        Eksporter->resize(546, 250);
        centralwidget = new QWidget(Eksporter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        f_path = new QLabel(centralwidget);
        f_path->setObjectName(QString::fromUtf8("f_path"));
        f_path->setGeometry(QRect(120, 60, 251, 16));
        export_2 = new QPushButton(centralwidget);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setGeometry(QRect(20, 120, 80, 21));
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(20, 60, 80, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 81, 16));
        Eksporter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Eksporter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 546, 20));
        Eksporter->setMenuBar(menubar);
        statusbar = new QStatusBar(Eksporter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Eksporter->setStatusBar(statusbar);

        retranslateUi(Eksporter);

        QMetaObject::connectSlotsByName(Eksporter);
    } // setupUi

    void retranslateUi(QMainWindow *Eksporter)
    {
        Eksporter->setWindowTitle(QCoreApplication::translate("Eksporter", "MainWindow", nullptr));
        f_path->setText(QCoreApplication::translate("Eksporter", "Folder", nullptr));
        export_2->setText(QCoreApplication::translate("Eksporter", "Eksportuj", nullptr));
        chooseButton->setText(QCoreApplication::translate("Eksporter", "Wybierz", nullptr));
        label->setText(QCoreApplication::translate("Eksporter", "Wybierz Folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Eksporter: public Ui_Eksporter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EKSPORTER_H
