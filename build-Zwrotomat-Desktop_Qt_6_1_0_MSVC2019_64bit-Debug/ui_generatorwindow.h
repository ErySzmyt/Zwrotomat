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
    QLabel *label;
    QPlainTextEdit *subjectTextEdit;
    QLabel *label_2;
    QPlainTextEdit *topicTextEdit;
    QLabel *label_3;
    QPlainTextEdit *checkerTextEdit;
    QLabel *label_4;
    QPlainTextEdit *scoreTextEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *outputDirPicker;
    QLabel *outputDirDisplay;
    QLabel *label_5;
    QPlainTextEdit *fileNameTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *generateButton;
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
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        subjectTextEdit = new QPlainTextEdit(centralwidget);
        subjectTextEdit->setObjectName(QString::fromUtf8("subjectTextEdit"));
        subjectTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, subjectTextEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        topicTextEdit = new QPlainTextEdit(centralwidget);
        topicTextEdit->setObjectName(QString::fromUtf8("topicTextEdit"));
        topicTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(1, QFormLayout::FieldRole, topicTextEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_3);

        checkerTextEdit = new QPlainTextEdit(centralwidget);
        checkerTextEdit->setObjectName(QString::fromUtf8("checkerTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkerTextEdit->sizePolicy().hasHeightForWidth());
        checkerTextEdit->setSizePolicy(sizePolicy);
        checkerTextEdit->setMinimumSize(QSize(0, 20));
        checkerTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkerTextEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_4);

        scoreTextEdit = new QPlainTextEdit(centralwidget);
        scoreTextEdit->setObjectName(QString::fromUtf8("scoreTextEdit"));
        scoreTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(5, QFormLayout::FieldRole, scoreTextEdit);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(7, QFormLayout::FieldRole, label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        outputDirPicker = new QPushButton(centralwidget);
        outputDirPicker->setObjectName(QString::fromUtf8("outputDirPicker"));
        outputDirPicker->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(outputDirPicker);

        outputDirDisplay = new QLabel(centralwidget);
        outputDirDisplay->setObjectName(QString::fromUtf8("outputDirDisplay"));

        horizontalLayout->addWidget(outputDirDisplay);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(9, QFormLayout::FieldRole, label_5);

        fileNameTextEdit = new QPlainTextEdit(centralwidget);
        fileNameTextEdit->setObjectName(QString::fromUtf8("fileNameTextEdit"));
        fileNameTextEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(10, QFormLayout::FieldRole, fileNameTextEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy1);
        generateButton->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(generateButton);


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
        label_2->setText(QCoreApplication::translate("GeneratorWindow", "Temat", nullptr));
        label_3->setText(QCoreApplication::translate("GeneratorWindow", "Sprawdzaj\304\205cy", nullptr));
        label_4->setText(QCoreApplication::translate("GeneratorWindow", "Ocena", nullptr));
        label_6->setText(QCoreApplication::translate("GeneratorWindow", "Wyj\305\233ciowy Folder", nullptr));
        outputDirPicker->setText(QCoreApplication::translate("GeneratorWindow", "Wybierz", nullptr));
        outputDirDisplay->setText(QCoreApplication::translate("GeneratorWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("GeneratorWindow", "Nazwa pliku", nullptr));
        generateButton->setText(QCoreApplication::translate("GeneratorWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneratorWindow: public Ui_GeneratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATORWINDOW_H
