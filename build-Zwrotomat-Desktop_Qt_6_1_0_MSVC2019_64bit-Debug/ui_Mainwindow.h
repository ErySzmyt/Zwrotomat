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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUstawienia;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_5;
    QGridLayout *gridLayout_3;
    QTreeView *treeFileExplorer;
    QMenuBar *menubar;
    QMenu *menuNowy;
    QMenu *menuEdytuj;
    QMenu *menuZapisz;
    QMenu *menuUstawienia;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 661);
        actionUstawienia = new QAction(MainWindow);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(textBrowser);

        dockWidget_2 = new QDockWidget(centralwidget);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy1);
        dockWidget_2->setMinimumSize(QSize(80, 93));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        treeFileExplorer = new QTreeView(dockWidgetContents_5);
        treeFileExplorer->setObjectName(QString::fromUtf8("treeFileExplorer"));
        treeFileExplorer->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeFileExplorer->sizePolicy().hasHeightForWidth());
        treeFileExplorer->setSizePolicy(sizePolicy2);
        treeFileExplorer->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(treeFileExplorer, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_5);

        horizontalLayout->addWidget(dockWidget_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 21));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy3);
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
