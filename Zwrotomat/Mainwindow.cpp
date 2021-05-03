#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString rootPath = "C:/";               // root path for file browser
    model = new QFileSystemModel(this);
    model->setRootPath(rootPath);           // set rooth path for C drive
    //below, filePath example for specific extensions only
    //QString filePath = QFileDialog::getOpenFileName(this, "select CSV file",".",'Comma Separated Values (*.csv)");
    ui->treeFileExplorer->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

