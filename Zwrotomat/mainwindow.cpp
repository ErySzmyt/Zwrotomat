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
    ui->dockWidget_2->setAllowedAreas(Qt::AllDockWidgetAreas);

    this->multiFileComment = new MultiFileComment();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_cursorPositionChanged()
{
    const QString fileName = this->selectedFile;

    if(fileJustOpen)
        multiFileComment->addNewFile(fileName);
    else {

        qDebug() << ui->textBrowser->textCursor().blockNumber();

        QTextCursor cur = ui->textBrowser->textCursor();
        QTextBlockFormat f;

        qDebug() << fileName;

        if(multiFileComment->getLinesByName(fileName)->contains(ui->textBrowser->textCursor().blockNumber()))
        {
            multiFileComment->
                    getLinesByName(this->selectedFile)->
                    removeAt(multiFileComment->getLinesByName(this->selectedFile)->
                             indexOf(ui->textBrowser->textCursor().blockNumber())
                             );

            f.setBackground(Qt::white);
        }else{

            multiFileComment->getLinesByName(fileName)->append(ui->textBrowser->textCursor().blockNumber());

            f.setBackground(Qt::gray);
        }

        ui->textBrowser->setTextCursor(cur);
        cur.select(QTextCursor::LineUnderCursor);
        cur.setBlockFormat(f);
    }
    fileJustOpen = false;
}


//TODO loading cooments while lodaing new file
void MainWindow::loadSelectedLines()
{
    if(multiFileComment->containFile(this->selectedFile)){

    }
}

void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = fileModel->fileInfo(index).absoluteFilePath();
    QFile file(sPath); // path from on_treeFileExplorer_clicked
    this->selectedFile = sPath;

    qDebug() << sPath;

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file.errorString()); // if unable to open throw error in msg box

    QTextStream in(&file); // else open file and put it in browser

    qDebug() << "Reding File " << sPath;

    QString text = in.readAll();

    if(sPath.endsWith(".cpp", Qt::CaseInsensitive) || sPath.endsWith(".h", Qt::CaseInsensitive)){
        text.replace("\t", "    ");
    }

    ui->textBrowser->document()->setPlainText(text);
    // ui->textBrowser->setStyleSheet("outline: 0px; outline: none; outline-style: none;"); not working :(

    fileJustOpen = true;
}

void MainWindow::on_actionZ_Folderu_triggered()
{
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->selectedDir = dir;

    qDebug() << "Initilizing TreeView with " << dir;

    //fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    //set root path
    fileModel->setRootPath(dir.path());

    ui->treeFileExplorer->setModel(fileModel);

    QModelIndex indx = fileModel->index(dir.path());
    ui->treeFileExplorer->setRootIndex(indx);
}

void MainWindow::on_actionPliki_triggered()
{

}
