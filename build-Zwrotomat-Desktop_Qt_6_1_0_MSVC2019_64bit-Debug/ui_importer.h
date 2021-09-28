/********************************************************************************
** Form generated from reading UI file 'importer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTER_H
#define UI_IMPORTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Importer
{
public:
    QWidget *centralwidget;
    QLabel *f_path;
    QPushButton *import_2;
    QPushButton *chooseButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Importer)
    {
        if (Importer->objectName().isEmpty())
            Importer->setObjectName(QString::fromUtf8("Importer"));
        Importer->resize(536, 225);
        centralwidget = new QWidget(Importer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        f_path = new QLabel(centralwidget);
        f_path->setObjectName(QString::fromUtf8("f_path"));
        f_path->setGeometry(QRect(130, 60, 251, 16));
        import_2 = new QPushButton(centralwidget);
        import_2->setObjectName(QString::fromUtf8("import_2"));
        import_2->setGeometry(QRect(30, 120, 80, 21));
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(30, 60, 80, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 81, 16));
        Importer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Importer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 536, 20));
        Importer->setMenuBar(menubar);
        statusbar = new QStatusBar(Importer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Importer->setStatusBar(statusbar);

        retranslateUi(Importer);

        QMetaObject::connectSlotsByName(Importer);
    } // setupUi

    void retranslateUi(QMainWindow *Importer)
    {
        Importer->setWindowTitle(QCoreApplication::translate("Importer", "MainWindow", nullptr));
        f_path->setText(QCoreApplication::translate("Importer", "Folder", nullptr));
        import_2->setText(QCoreApplication::translate("Importer", "Importuj", nullptr));
        chooseButton->setText(QCoreApplication::translate("Importer", "Wybierz", nullptr));
        label->setText(QCoreApplication::translate("Importer", "Wybierz Folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Importer: public Ui_Importer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTER_H
