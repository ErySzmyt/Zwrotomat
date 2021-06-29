/********************************************************************************
** Form generated from reading UI file 'itemdisplay.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMDISPLAY_H
#define UI_ITEMDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemDisplay
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *removeButton;

    void setupUi(QWidget *ItemDisplay)
    {
        if (ItemDisplay->objectName().isEmpty())
            ItemDisplay->setObjectName(QString::fromUtf8("ItemDisplay"));
        ItemDisplay->resize(250, 60);
        horizontalLayout = new QHBoxLayout(ItemDisplay);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ItemDisplay);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        removeButton = new QToolButton(ItemDisplay);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);


        retranslateUi(ItemDisplay);

        QMetaObject::connectSlotsByName(ItemDisplay);
    } // setupUi

    void retranslateUi(QWidget *ItemDisplay)
    {
        ItemDisplay->setWindowTitle(QCoreApplication::translate("ItemDisplay", "Form", nullptr));
        label->setText(QCoreApplication::translate("ItemDisplay", "TextLabel", nullptr));
        removeButton->setText(QCoreApplication::translate("ItemDisplay", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemDisplay: public Ui_ItemDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMDISPLAY_H
