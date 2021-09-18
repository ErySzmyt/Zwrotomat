#include "eksport.h"
#include "ui_eksport.h"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "multifilecomment.h"
#include "filereadingutils.h"
eksport::eksport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::eksport)
{
    ui->setupUi(this);
}

eksport::~eksport()
{
    delete ui;
}

void eksport::setComments(QHash<QString, MultiFileComment *> *commentMap)
{
    //set comments for export
    this->m_Comments = commentMap;
}

void eksport::on_chooseButton_clicked()
{
    // choose output folder
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    s_last_selectedDir = dir;
    ui->f_path->setText(dir.path());
}

void eksport::on_export_2_clicked()
{
    // export comments
    QFile myFile;
    QDataStream out (&myFile);
    out<<this->m_Comments;

}
