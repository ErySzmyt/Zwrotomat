#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include "QFileDialog.h"

#include "highlighter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
\
    highlighter = new Highlighter(ui->textBrowser->document());
    fileModel = new QFileSystemModel(this);
    ui->textBrowser->lineWrapColumnOrWidth();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_cursorPositionChanged()
{
    QTextCursor cur = ui->textBrowser->textCursor();
    QTextBlockFormat f;
    f.setBackground(Qt::gray);
    cur.select(QTextCursor::LineUnderCursor);
    cur.setBlockFormat(f);
    ui->textBrowser->setTextCursor(cur);
}

void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = fileModel->fileInfo(index).absoluteFilePath();
    QFile file(sPath); // path from on_treeFileExplorer_clicked
    this->selectedFile = &file;

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file.errorString()); // if unable to open throw error in msg box

    QTextStream in(&file); // else open file and put it in browser

    qDebug() << "Reding File " << sPath;

    QString text = in.readAll();

    if(sPath.endsWith(".cpp", Qt::CaseInsensitive) || sPath.endsWith(".h", Qt::CaseInsensitive)){
        text.replace("\t", "    ");
    }

    ui->textBrowser->setText(text);
    // ui->textBrowser->setStyleSheet("outline: 0px; outline: none; outline-style: none;"); not working :(
}

void MainWindow::on_actionZ_Folderu_triggered()
{
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->selectedDir = &dir;

    qDebug() << "Initilizing TreeView with " << dir;

    //fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    //set root path
    fileModel->setRootPath(dir.path());

    ui->treeFileExplorer->setModel(fileModel);

    QModelIndex indx = fileModel->index(dir.path());
    ui->treeFileExplorer->setRootIndex(indx);
}
