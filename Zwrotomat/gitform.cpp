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

/**
 * @brief GitForm::on_folderPickingButton_clicked
 * Action for selecting output folder
 */
void GitForm::on_folderPickingButton_clicked()
{
      QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
      s_last_selectedDir = dir;
      ui->outputDirDisplay->setText(dir.path());
}

/**
 * @brief GitForm::on_cloneButton_clicked clone action
 */
void GitForm::on_cloneButton_clicked()
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
