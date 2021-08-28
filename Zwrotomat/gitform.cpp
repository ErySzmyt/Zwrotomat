#include "gitform.h"
#include "ui_gitform.h"


#include <QDir>
#include <QDialog>
#include <QFileDialog>
#include<QtCore>
#include <QMessageBox>
GitForm::GitForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GitForm)
{
    ui->setupUi(this);
    this->gitWrapper = new GitWrapper();
}

GitForm::~GitForm()
{
    delete this->gitWrapper;
    delete ui;
}

void GitForm::on_pushButton_clicked()
{
      QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
      s_last_selectedDir = dir;
      ui->outputDirDisplay->setText(dir.path());

}

void GitForm::on_pushButton_2_clicked()
{
    if(!ui->LinkToRepo->toPlainText().isEmpty() && !s_last_selectedDir.path().isEmpty()){
        this->gitWrapper->clone(ui->LinkToRepo->toPlainText(),s_last_selectedDir);
    }
    else
    {
       QMessageBox errorBox;
       errorBox.critical(0,"Error","Prosze wprowadzic wartosci, link oraz folder !");
       errorBox.setFixedSize(500,200);
       qDebug() << "error";
    }
}
