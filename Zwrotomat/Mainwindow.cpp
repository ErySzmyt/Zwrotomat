#include "Mainwindow.h"
#include "ui_Mainwindow.h"

#include "QFileDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
\

    //ui->textBrowser->lineWrapColumnOrWidth();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = fileModel->fileInfo(index).absoluteFilePath();
    this->selectedPath = sPath;
}
/*
void MainWindow::on_pushButton_clicked()
{
    QFile file(this->selectedPath); // path from on_treeFileExplorer_clicked
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString()); // if unable to open throw error in msg box
    }
    QTextStream in(&file);// else open file and put it in browser
    ui->textBrowser->setText(in.readAll());

}
*/
void MainWindow::on_actionZ_Folderu_triggered()
{
    QString dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());

    qDebug() << dir;




    fileModel = new QFileSystemModel(this);
    //fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    //set root path
    fileModel->setRootPath(dir);


    ui->treeFileExplorer->setModel(fileModel);


    QModelIndex indx = fileModel->index(dir);
    ui->treeFileExplorer->setRootIndex(indx);


    //QTextStream in(&file);// else open file and put it in browser
    //ui->textBrowser->setText(in.readAll());
}
