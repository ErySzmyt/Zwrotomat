#include "gitform.h"
#include "ui_gitform.h"

GitForm::GitForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GitForm)
{
    ui->setupUi(this);
}

GitForm::~GitForm()
{
    delete ui;
}
