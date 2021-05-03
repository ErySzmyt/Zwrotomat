/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUstawienia;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuNowy;
    QMenu *menuEdytuj;
    QMenu *menuZapisz;
    QMenu *menuUstawienia;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QTreeView *treeFileExplorer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 661);
        actionUstawienia = new QAction(MainWindow);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 100, 781, 431));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 20));
        menuNowy = new QMenu(menubar);
        menuNowy->setObjectName(QString::fromUtf8("menuNowy"));
        menuEdytuj = new QMenu(menubar);
        menuEdytuj->setObjectName(QString::fromUtf8("menuEdytuj"));
        menuZapisz = new QMenu(menubar);
        menuZapisz->setObjectName(QString::fromUtf8("menuZapisz"));
        menuUstawienia = new QMenu(menubar);
        menuUstawienia->setObjectName(QString::fromUtf8("menuUstawienia"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        treeFileExplorer = new QTreeView(dockWidgetContents_2);
        treeFileExplorer->setObjectName(QString::fromUtf8("treeFileExplorer"));
        treeFileExplorer->setGeometry(QRect(10, 40, 351, 521));
        dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget);

        menubar->addAction(menuNowy->menuAction());
        menubar->addAction(menuEdytuj->menuAction());
        menubar->addAction(menuZapisz->menuAction());
        menubar->addAction(menuUstawienia->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionUstawienia->setText(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
        menuNowy->setTitle(QCoreApplication::translate("MainWindow", "Nowy", nullptr));
        menuEdytuj->setTitle(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        menuZapisz->setTitle(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        menuUstawienia->setTitle(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
