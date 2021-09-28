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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "codedisplay.h"

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
    QAction *actionGenerowanie;
    QAction *actionPliki;
    QAction *actionKomentarze;
    QAction *actionGeneruj;
    QAction *actionImport;
    QAction *actionEksport;

    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    CodeDisplay *textBrowser;
    QDockWidget *dockWidget_1;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_1;
    QTextEdit *commentEdit;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QTreeView *treeFileExplorer;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addingCommentButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuProjekt;
    QMenu *menuNowy;
    QMenu *menuUstawienia;
    QMenu *menuOkna;
    QMenu *menuGeneruj;
    QMenu *menuKomentarze;

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
        actionGenerowanie = new QAction(MainWindow);
        actionGenerowanie->setObjectName(QString::fromUtf8("actionGenerowanie"));
        actionPliki = new QAction(MainWindow);
        actionPliki->setObjectName(QString::fromUtf8("actionPliki"));
        actionKomentarze = new QAction(MainWindow);
        actionKomentarze->setObjectName(QString::fromUtf8("actionKomentarze"));
        actionGeneruj = new QAction(MainWindow);
        actionGeneruj->setObjectName(QString::fromUtf8("actionGeneruj"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionImport->setCheckable(true);
        actionEksport = new QAction(MainWindow);
        actionEksport->setObjectName(QString::fromUtf8("actionEksport"));

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        textBrowser = new CodeDisplay(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(5);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setFocusPolicy(Qt::NoFocus);
        textBrowser->setProperty("overwriteMode", QVariant(false));

        verticalLayout_3->addWidget(textBrowser);

        dockWidget_1 = new QDockWidget(centralwidget);
        dockWidget_1->setObjectName(QString::fromUtf8("dockWidget_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(dockWidget_1->sizePolicy().hasHeightForWidth());
        dockWidget_1->setSizePolicy(sizePolicy1);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_1 = new QGridLayout(dockWidgetContents);
        gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
        gridLayout_1->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_1->setContentsMargins(0, 0, 0, 0);
        commentEdit = new QTextEdit(dockWidgetContents);
        commentEdit->setObjectName(QString::fromUtf8("commentEdit"));

        gridLayout_1->addWidget(commentEdit, 1, 0, 1, 1);

        dockWidget_1->setWidget(dockWidgetContents);

        verticalLayout_3->addWidget(dockWidget_1);


        horizontalLayout->addLayout(verticalLayout_3);

        dockWidget_2 = new QDockWidget(centralwidget);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy2);
        dockWidget_2->setMinimumSize(QSize(180, 215));
        dockWidget_2->setMaximumSize(QSize(260, 524287));
        dockWidget_2->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        treeFileExplorer = new QTreeView(dockWidgetContents_2);
        treeFileExplorer->setObjectName(QString::fromUtf8("treeFileExplorer"));
        treeFileExplorer->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(5);
        sizePolicy3.setHeightForWidth(treeFileExplorer->sizePolicy().hasHeightForWidth());
        treeFileExplorer->setSizePolicy(sizePolicy3);
        treeFileExplorer->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(treeFileExplorer, 0, 0, 1, 1);

        gridGroupBox = new QGroupBox(dockWidgetContents_2);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(gridGroupBox->sizePolicy().hasHeightForWidth());
        gridGroupBox->setSizePolicy(sizePolicy4);
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(gridGroupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        addingCommentButton = new QPushButton(gridGroupBox);
        addingCommentButton->setObjectName(QString::fromUtf8("addingCommentButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(addingCommentButton->sizePolicy().hasHeightForWidth());
        addingCommentButton->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(addingCommentButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(gridGroupBox, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);

        horizontalLayout->addWidget(dockWidget_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 20));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy6);
        menuProjekt = new QMenu(menubar);
        menuProjekt->setObjectName(QString::fromUtf8("menuProjekt"));
        menuNowy = new QMenu(menuProjekt);
        menuNowy->setObjectName(QString::fromUtf8("menuNowy"));
        menuUstawienia = new QMenu(menubar);
        menuUstawienia->setObjectName(QString::fromUtf8("menuUstawienia"));
        menuOkna = new QMenu(menubar);
        menuOkna->setObjectName(QString::fromUtf8("menuOkna"));
        menuGeneruj = new QMenu(menubar);
        menuGeneruj->setObjectName(QString::fromUtf8("menuGeneruj"));
        menuKomentarze = new QMenu(menubar);
        menuKomentarze->setObjectName(QString::fromUtf8("menuKomentarze"));
        menuKomentarze->setToolTipsVisible(true);

        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuProjekt->menuAction());
        menubar->addAction(menuUstawienia->menuAction());
        menubar->addAction(menuOkna->menuAction());
        menubar->addAction(menuGeneruj->menuAction());
        menubar->addAction(menuKomentarze->menuAction());
        menuProjekt->addAction(menuNowy->menuAction());
        menuProjekt->addAction(actionZapisz);
        menuNowy->addAction(actionZ_Folderu);
        menuNowy->addAction(actionPusty);
        menuNowy->addAction(actionGit);
        menuUstawienia->addAction(actionTheme);
        menuUstawienia->addAction(actionGenerowanie);
        menuOkna->addAction(actionPliki);
        menuOkna->addAction(actionKomentarze);
        menuGeneruj->addAction(actionGeneruj);
        menuKomentarze->addAction(actionImport);
        menuKomentarze->addAction(actionEksport);


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
        actionGenerowanie->setText(QCoreApplication::translate("MainWindow", "Generowanie", nullptr));
        actionPliki->setText(QCoreApplication::translate("MainWindow", "Pliki", nullptr));
        actionKomentarze->setText(QCoreApplication::translate("MainWindow", "Komentarze", nullptr));
        actionGeneruj->setText(QCoreApplication::translate("MainWindow", "Generuj", nullptr));
        actionImport->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        actionEksport->setText(QCoreApplication::translate("MainWindow", "Eksport", nullptr));

        dockWidget_1->setWindowTitle(QCoreApplication::translate("MainWindow", "Tre\305\233\304\207 Komentarza", nullptr));
        dockWidget_2->setWindowTitle(QCoreApplication::translate("MainWindow", "Drzewo Projektu", nullptr));
        addingCommentButton->setText(QCoreApplication::translate("MainWindow", "Dodaj komentarz", nullptr));
        menuProjekt->setTitle(QCoreApplication::translate("MainWindow", "Projekt", nullptr));
        menuNowy->setTitle(QCoreApplication::translate("MainWindow", "Nowy", nullptr));
        menuUstawienia->setTitle(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
        menuOkna->setTitle(QCoreApplication::translate("MainWindow", "Okna", nullptr));
        menuGeneruj->setTitle(QCoreApplication::translate("MainWindow", "Raport", nullptr));
        menuKomentarze->setTitle(QCoreApplication::translate("MainWindow", "Komentarze", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
