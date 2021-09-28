#include "itemdisplay.h"
#include "ui_itemdisplay.h"

ItemDisplay::ItemDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemDisplay)
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeComment(const QString &)));
    connect(this, SIGNAL(sendCommentClicked(const QString &)), parent, SLOT(selectComment(const QString &)));
    connect(this, SIGNAL(sendPositiveCheckChanged(const QString &,const bool &)), parent, SLOT(changePositivityOfComment(const QString &,const bool &)));
}

ItemDisplay::~ItemDisplay()
{
    delete ui;
}

/*
* Action on clicking remove Button
* emiting sendRemoveItem(...)
*/
void ItemDisplay::on_removeButton_clicked()
{
    emit sendRemoveItem(ui->label->text());
}

/*
* Setting text displayed on label in widget
*/
void ItemDisplay::setText(const QString &text)
{
    ui->label->setText(text);
}

/*
* Getting text displayed on label in widget
*/
QString ItemDisplay::getText()
{
    return ui->label->text();
}

/*
* Action on mouse release on whole widget
* @note mousePressed dosent work, because it colides with QWidgetLayout methods
*/
void ItemDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    emit sendCommentClicked(ui->label->text());
}

/*
* Action on mouse click on radio button in the widget
*/
void ItemDisplay::on_wskaznikPozytyw_clicked()
{
    emit sendPositiveCheckChanged(ui->label->text(), ui->wskaznikPozytyw->isChecked());
}
