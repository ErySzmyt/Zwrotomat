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

/**
 * @brief ItemDisplay::on_removeButton_clicked Action on clicking remove Button
 * emiting sendRemoveItem(...)
 */
void ItemDisplay::on_removeButton_clicked()
{
    emit sendRemoveItem(ui->label->text());
}

/**
 * @brief ItemDisplay::setText Setting text displayed on label in widget
 * @param text displaying text
 */
void ItemDisplay::setText(const QString &text)
{
    ui->label->setText(text);
}

/**
 * @brief ItemDisplay::getText Getting text displayed on label in widget
 * @return item displayed text
 */
QString ItemDisplay::getText()
{
    return ui->label->text();
}

/**
 * @brief ItemDisplay::mouseReleaseEvent Action on mouse release on whole widget
 * @note mousePressed dosent work, because it colides with QWidgetLayout methods
 * @param event event
 */
void ItemDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    emit sendCommentClicked(ui->label->text());
}

/**
 * @brief ItemDisplay::on_wskaznikPozytyw_clicked Action on mouse click on radio button in the widget
 */
void ItemDisplay::on_wskaznikPozytyw_clicked()
{
    emit sendPositiveCheckChanged(ui->label->text(), ui->wskaznikPozytyw->isChecked());
}
