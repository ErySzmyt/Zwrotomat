#include "gitform.h"
#include "ui_gitform.h"


#include <QDir>
#include <QDialog>
#include <QFileDialog>
#include<QtCore>
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

void GitForm::on_pushButton_clicked()
{
      QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
      s_last_selectedDir = dir;
      ui->outputDirDisplay->setText(dir.path());

}
