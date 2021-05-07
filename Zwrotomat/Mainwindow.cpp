#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString rootPath = "C:/";               // root path for file browser
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(rootPath);           // set rooth path for C drive
    //below, filePath example for specific extensions only
    //QString filePath = QFileDialog::getOpenFileName(this, "select CSV file",".",'Comma Separated Values (*.csv)");
    ui->treeFileExplorer->setModel(dirmodel);

    filemodel =new QFileSystemModel(this);
    filemodel->setRootPath(rootPath);           // set rooth path for C drive
    ui->treeFileExplorer->setModel(filemodel);
    ui->textBrowser->lineWrapColumnOrWidth();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    this->selectedPath = sPath;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(this->selectedPath); // path from on_treeFileExplorer_clicked
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString()); // if unable to open throw error in msg box
    }
    QTextStream in(&file);// else open file and put it in browser
    ui->textBrowser->setText(in.readAll());

}

void MainWindow::on_actionZ_Folderu_triggered()
{
    /* choosing file from folder and opening */
    QFile file(this->selectedPath); // path from on_treeFileExplorer_clicked
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString()); // if unable to open throw error in msg box
    }
    QTextStream in(&file);// else open file and put it in browser
    ui->textBrowser->setText(in.readAll());
}
