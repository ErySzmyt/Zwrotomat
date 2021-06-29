#include "itemdisplay.h"
#include "ui_itemdisplay.h"

ItemDisplay::ItemDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemDisplay)
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeComment(const QString &)));
    connect(this, SIGNAL(sendCommentClicked(const QString &)), parent, SLOT(selectComment(const QString &)));
}

ItemDisplay::~ItemDisplay()
{
    delete ui;
}

void ItemDisplay::on_removeButton_clicked()
{
    emit sendRemoveItem(ui->label->text());
}

void ItemDisplay::setText(const QString &text) {
    ui->label->setText(text);
}

QString ItemDisplay::getText() {
    return ui->label->text();
}

void ItemDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    emit sendCommentClicked(ui->label->text());
}
