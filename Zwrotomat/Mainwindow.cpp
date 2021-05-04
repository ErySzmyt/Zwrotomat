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
    // PATH FOR TEST
    QFile file(this->selectedPath); // path
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString());
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}
