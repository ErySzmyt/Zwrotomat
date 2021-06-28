#include "itemdisplay.h"
#include "ui_itemdisplay.h"

ItemDisplay::ItemDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemDisplay)
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeItem(const QString &)));
}

ItemDisplay::~ItemDisplay()
{
    delete ui;
}

void ItemDisplay::on_removeButton_clicked()
{
    emit sendRemoveItem(ui->pushButton->text());
}

void ItemDisplay::setText(const QString &text) {
    ui->pushButton->setText(text);
}

QString ItemDisplay::getText() {
    return ui->pushButton->text();
}

void ItemDisplay::on_pushButton_clicked()
{
    //TODO połączyć z podmianą komentarza
}
