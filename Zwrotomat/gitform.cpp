#include "gitform.h"
#include "ui_gitform.h"

#include <QMainWindow>

#include <QDir>
#include <QDialog>
#include <QFileDialog>
#include <QtCore>
#include <QMessageBox>

GitForm::GitForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GitForm)
{
    ui->setupUi(this);
    this->gitWrapper = new GitWrapper();


    connect(this, SIGNAL(sendDoneClonning(const QDir &)), parent, SLOT(doneClonning(const QDir &)));

    ui->GitUsername->setText(gitWrapper->getUsername());
    ui->GitEmail->setText(gitWrapper->getEmail());
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
        emit sendDoneClonning(this->gitWrapper->clone(ui->LinkToRepo->toPlainText(), s_last_selectedDir));
        this->close();
    }
    else
    {
       QMessageBox errorBox;
       errorBox.critical(0,"Error","Prosze wprowadzic wartosci, link oraz folder !");
       errorBox.setFixedSize(500,200);
       qDebug() << "error";
    }
}
