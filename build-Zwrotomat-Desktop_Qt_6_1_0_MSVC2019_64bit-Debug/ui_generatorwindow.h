/********************************************************************************
** Form generated from reading UI file 'generatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATORWINDOW_H
#define UI_GENERATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneratorWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GeneratorWindow)
    {
        if (GeneratorWindow->objectName().isEmpty())
            GeneratorWindow->setObjectName(QString::fromUtf8("GeneratorWindow"));
        GeneratorWindow->resize(270, 514);
        centralwidget = new QWidget(GeneratorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 10, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, plainTextEdit);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(1, QFormLayout::FieldRole, plainTextEdit_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_3);

        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_3->sizePolicy().hasHeightForWidth());
        plainTextEdit_3->setSizePolicy(sizePolicy);
        plainTextEdit_3->setMinimumSize(QSize(0, 20));
        plainTextEdit_3->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(3, QFormLayout::FieldRole, plainTextEdit_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        GeneratorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GeneratorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 270, 21));
        GeneratorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GeneratorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GeneratorWindow->setStatusBar(statusbar);

        retranslateUi(GeneratorWindow);

        QMetaObject::connectSlotsByName(GeneratorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GeneratorWindow)
    {
        GeneratorWindow->setWindowTitle(QCoreApplication::translate("GeneratorWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("GeneratorWindow", "Przedmiot", nullptr));
        label_2->setText(QCoreApplication::translate("GeneratorWindow", "Ocena", nullptr));
        label_3->setText(QCoreApplication::translate("GeneratorWindow", "Sprawdzaj\304\205cy", nullptr));
        label_4->setText(QCoreApplication::translate("GeneratorWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("GeneratorWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("GeneratorWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneratorWindow: public Ui_GeneratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATORWINDOW_H
