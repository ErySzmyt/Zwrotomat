/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "codeDisplay.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUstawienia;
    QAction *actionTheme;
    QAction *actionZ_Folderu;
    QAction *actionPusty;
    QAction *actionGit;
    QAction *actionZapisz;
    QAction *actionEksportuj;
    QAction *actionImportuj;
    QAction *actionGenerowanie;
    QAction *actionPliki;
    QAction *actionKomentarze;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    CodeEditor *textBrowser;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QTreeView *treeFileExplorer;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuProjekt;
    QMenu *menuNowy;
    QMenu *menuUstawienia;
    QMenu *menuOkna;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 661);
        actionUstawienia = new QAction(MainWindow);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        actionTheme = new QAction(MainWindow);
        actionTheme->setObjectName(QString::fromUtf8("actionTheme"));
        actionZ_Folderu = new QAction(MainWindow);
        actionZ_Folderu->setObjectName(QString::fromUtf8("actionZ_Folderu"));
        actionPusty = new QAction(MainWindow);
        actionPusty->setObjectName(QString::fromUtf8("actionPusty"));
        actionGit = new QAction(MainWindow);
        actionGit->setObjectName(QString::fromUtf8("actionGit"));
        actionZapisz = new QAction(MainWindow);
        actionZapisz->setObjectName(QString::fromUtf8("actionZapisz"));
        actionEksportuj = new QAction(MainWindow);
        actionEksportuj->setObjectName(QString::fromUtf8("actionEksportuj"));
        actionImportuj = new QAction(MainWindow);
        actionImportuj->setObjectName(QString::fromUtf8("actionImportuj"));
        actionGenerowanie = new QAction(MainWindow);
        actionGenerowanie->setObjectName(QString::fromUtf8("actionGenerowanie"));
        actionPliki = new QAction(MainWindow);
        actionPliki->setObjectName(QString::fromUtf8("actionPliki"));
        actionKomentarze = new QAction(MainWindow);
        actionKomentarze->setObjectName(QString::fromUtf8("actionKomentarze"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        textBrowser = new CodeEditor(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setProperty("overwriteMode", QVariant(false));

        horizontalLayout->addWidget(textBrowser);

        dockWidget_2 = new QDockWidget(centralwidget);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy1);
        dockWidget_2->setMinimumSize(QSize(95, 128));
        dockWidget_2->setFloating(false);
        dockWidget_2->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        treeFileExplorer = new QTreeView(dockWidgetContents_5);
        treeFileExplorer->setObjectName(QString::fromUtf8("treeFileExplorer"));
        treeFileExplorer->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(treeFileExplorer->sizePolicy().hasHeightForWidth());
        treeFileExplorer->setSizePolicy(sizePolicy2);
        treeFileExplorer->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(treeFileExplorer, 0, 0, 1, 1);

        gridGroupBox = new QGroupBox(dockWidgetContents_5);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(gridGroupBox->sizePolicy().hasHeightForWidth());
        gridGroupBox->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_4->addWidget(gridGroupBox, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_5);

        horizontalLayout->addWidget(dockWidget_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 21));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy4);
        menuProjekt = new QMenu(menubar);
        menuProjekt->setObjectName(QString::fromUtf8("menuProjekt"));
        menuNowy = new QMenu(menuProjekt);
        menuNowy->setObjectName(QString::fromUtf8("menuNowy"));
        menuUstawienia = new QMenu(menubar);
        menuUstawienia->setObjectName(QString::fromUtf8("menuUstawienia"));
        menuOkna = new QMenu(menubar);
        menuOkna->setObjectName(QString::fromUtf8("menuOkna"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuProjekt->menuAction());
        menubar->addAction(menuUstawienia->menuAction());
        menubar->addAction(menuOkna->menuAction());
        menuProjekt->addAction(menuNowy->menuAction());
        menuProjekt->addAction(actionZapisz);
        menuProjekt->addAction(actionEksportuj);
        menuProjekt->addAction(actionImportuj);
        menuNowy->addAction(actionZ_Folderu);
        menuNowy->addAction(actionPusty);
        menuNowy->addAction(actionGit);
        menuUstawienia->addAction(actionTheme);
        menuUstawienia->addAction(actionGenerowanie);
        menuOkna->addAction(actionPliki);
        menuOkna->addAction(actionKomentarze);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionUstawienia->setText(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
        actionTheme->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        actionZ_Folderu->setText(QCoreApplication::translate("MainWindow", "Z Folderu", nullptr));
        actionPusty->setText(QCoreApplication::translate("MainWindow", "Pusty", nullptr));
        actionGit->setText(QCoreApplication::translate("MainWindow", "Git", nullptr));
        actionZapisz->setText(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        actionEksportuj->setText(QCoreApplication::translate("MainWindow", "Eksportuj", nullptr));
        actionImportuj->setText(QCoreApplication::translate("MainWindow", "Importuj", nullptr));
        actionGenerowanie->setText(QCoreApplication::translate("MainWindow", "Generowanie", nullptr));
        actionPliki->setText(QCoreApplication::translate("MainWindow", "Pliki", nullptr));
        actionKomentarze->setText(QCoreApplication::translate("MainWindow", "Komentarze", nullptr));
        menuProjekt->setTitle(QCoreApplication::translate("MainWindow", "Projekt", nullptr));
        menuNowy->setTitle(QCoreApplication::translate("MainWindow", "Nowy", nullptr));
        menuUstawienia->setTitle(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
        menuOkna->setTitle(QCoreApplication::translate("MainWindow", "Okna", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
