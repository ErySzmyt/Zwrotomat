/********************************************************************************
** Form generated from reading UI file 'gitform.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GITFORM_H
#define UI_GITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GitForm
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *outputDirDisplay;
    QTextEdit *GitUsername;
    QTextEdit *GitEmail;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QTextEdit *LinkToRepo;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *GitForm)
    {
        if (GitForm->objectName().isEmpty())
            GitForm->setObjectName(QString::fromUtf8("GitForm"));
        GitForm->resize(858, 316);
        pushButton = new QPushButton(GitForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 90, 80, 21));
        label = new QLabel(GitForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 131, 16));
        outputDirDisplay = new QLabel(GitForm);
        outputDirDisplay->setObjectName(QString::fromUtf8("outputDirDisplay"));
        outputDirDisplay->setGeometry(QRect(160, 90, 381, 21));
        GitUsername = new QTextEdit(GitForm);
        GitUsername->setObjectName(QString::fromUtf8("GitUsername"));
        GitUsername->setGeometry(QRect(660, 110, 151, 31));
        GitEmail = new QTextEdit(GitForm);
        GitEmail->setObjectName(QString::fromUtf8("GitEmail"));
        GitEmail->setGeometry(QRect(660, 160, 151, 31));
        label_2 = new QLabel(GitForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 80, 71, 16));
        label_3 = new QLabel(GitForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 140, 47, 13));
        pushButton_2 = new QPushButton(GitForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 240, 80, 21));
        LinkToRepo = new QTextEdit(GitForm);
        LinkToRepo->setObjectName(QString::fromUtf8("LinkToRepo"));
        LinkToRepo->setGeometry(QRect(60, 200, 751, 31));
        label_4 = new QLabel(GitForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 170, 201, 16));
        label_5 = new QLabel(GitForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 40, 151, 16));

        retranslateUi(GitForm);

        QMetaObject::connectSlotsByName(GitForm);
    } // setupUi

    void retranslateUi(QWidget *GitForm)
    {
        GitForm->setWindowTitle(QCoreApplication::translate("GitForm", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("GitForm", "Wybierz Folder", nullptr));
        label->setText(QCoreApplication::translate("GitForm", "Wybierz folder docelowy", nullptr));
        outputDirDisplay->setText(QCoreApplication::translate("GitForm", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("GitForm", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("GitForm", "E-mail", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GitForm", "Klonuj", nullptr));
        label_4->setText(QCoreApplication::translate("GitForm", "HTTP do klonowanego repozytorium", nullptr));
        label_5->setText(QCoreApplication::translate("GitForm", "Dane u\305\274ytkownika", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GitForm: public Ui_GitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GITFORM_H
