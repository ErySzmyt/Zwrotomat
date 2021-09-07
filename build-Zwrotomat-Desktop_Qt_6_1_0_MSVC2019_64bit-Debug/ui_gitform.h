/********************************************************************************
** Form generated from reading UI file 'gitform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GITFORM_H
#define UI_GITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GitForm
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *outputDirDisplay;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_3;
    QTextEdit *GitEmail;
    QLabel *label_2;
    QTextEdit *GitUsername;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTextEdit *LinkToRepo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GitForm)
    {
        if (GitForm->objectName().isEmpty())
            GitForm->setObjectName(QString::fromUtf8("GitForm"));
        GitForm->resize(800, 266);
        centralwidget = new QWidget(GitForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout_2 = new QFormLayout(centralwidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButton);

        outputDirDisplay = new QLabel(centralwidget);
        outputDirDisplay->setObjectName(QString::fromUtf8("outputDirDisplay"));

        horizontalLayout->addWidget(outputDirDisplay);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        GitEmail = new QTextEdit(centralwidget);
        GitEmail->setObjectName(QString::fromUtf8("GitEmail"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GitEmail->sizePolicy().hasHeightForWidth());
        GitEmail->setSizePolicy(sizePolicy);
        GitEmail->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(GitEmail);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        GitUsername = new QTextEdit(centralwidget);
        GitUsername->setObjectName(QString::fromUtf8("GitUsername"));
        sizePolicy.setHeightForWidth(GitUsername->sizePolicy().hasHeightForWidth());
        GitUsername->setSizePolicy(sizePolicy);
        GitUsername->setMaximumSize(QSize(16777215, 30));

        verticalLayout_4->addWidget(GitUsername);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        LinkToRepo = new QTextEdit(centralwidget);
        LinkToRepo->setObjectName(QString::fromUtf8("LinkToRepo"));
        LinkToRepo->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(LinkToRepo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);


        formLayout_2->setLayout(1, QFormLayout::SpanningRole, verticalLayout_3);

        GitForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GitForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        GitForm->setMenuBar(menubar);
        statusbar = new QStatusBar(GitForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GitForm->setStatusBar(statusbar);

        retranslateUi(GitForm);

        QMetaObject::connectSlotsByName(GitForm);
    } // setupUi

    void retranslateUi(QMainWindow *GitForm)
    {
        GitForm->setWindowTitle(QCoreApplication::translate("GitForm", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("GitForm", "Wybierz folder docelowy", nullptr));
        pushButton->setText(QCoreApplication::translate("GitForm", "Wybierz Folder", nullptr));
        outputDirDisplay->setText(QCoreApplication::translate("GitForm", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("GitForm", "Dane u\305\274ytkownika", nullptr));
        label_3->setText(QCoreApplication::translate("GitForm", "E-mail", nullptr));
        label_2->setText(QCoreApplication::translate("GitForm", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("GitForm", "HTTP do klonowanego repozytorium", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GitForm", "Klonuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GitForm: public Ui_GitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GITFORM_H
