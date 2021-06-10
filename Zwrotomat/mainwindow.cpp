#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include "QFileDialog.h"

#include "highlighter.h"


#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>

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
    setAcceptDrops(true);

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
    int i =1; // debug
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) //If the data contains Url
    {
        event->acceptProposedAction(); //Receive action
    }
    else
    {
        event->ignore();          //Otherwise ignore the event
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData(); //Get MIME data
    if (mimeData->hasUrls())    //If the data contains Url
    {
        QList<QUrl> urlList = mimeData->urls();   //Get Url list
        QString fileName = urlList.at(0).toLocalFile();//Express the first URL as a local file path
       /* if (!fileName.isEmpty())   //File name is not empty
        {
            QFile file(fileName);   //Create QFile object
            if(!file.open(QIODevice::ReadOnly)) //Open the file in read-only mode
            {
                return;
            }
            QTextStream fileIn(&file);    //Create a text flow object
            */
            fileModel->setRootPath(fileName);

            ui->treeFileExplorer->setModel(fileModel);

            QModelIndex indx = fileModel->index(fileName);
            ui->treeFileExplorer->setRootIndex(indx);   //Display the text content in the Text Browser
        }
    }
