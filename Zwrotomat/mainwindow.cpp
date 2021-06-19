#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include "QFileDialog.h"

#include "highlighter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->centralwidget);

    ui->textBrowser->setMouseTracking(true);

    highlighter = new Highlighter(ui->textBrowser->document());
    fileModel = new QFileSystemModel(this);

    this->multiFileComment = new MultiFileComment();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_cursorPositionChanged()
{
    const QString fileName = this->selectedFile;
    Qt::KeyboardModifiers key = QGuiApplication::queryKeyboardModifiers();

    if(fileJustOpen)
        multiFileComment->addNewFile(fileName);
    else if(ui->textBrowser->isMouseOver()) {

        QTextCursor cur = ui->textBrowser->textCursor();
        QTextBlockFormat f;

        if(multiFileComment->getLinesByName(fileName)->contains(ui->textBrowser->textCursor().blockNumber())) {
            if(key == Qt::ShiftModifier){

                multiFileComment->
                        getLinesByName(this->selectedFile)->
                        removeAt(multiFileComment->getLinesByName(this->selectedFile)->
                                 indexOf(ui->textBrowser->textCursor().blockNumber())
                                 );

                f.setBackground(Qt::white);
            }else{
                return;
            }

        }else{
             if(key != Qt::ShiftModifier){
                 multiFileComment->getLinesByName(fileName)->append(ui->textBrowser->textCursor().blockNumber());
                 f.setBackground(Qt::gray);
             }
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
    for(int i : *multiFileComment->getLinesByName(this->selectedFile)) {
        QTextCursor coursor(ui->textBrowser->document()->findBlockByLineNumber(i));
        QTextBlockFormat frmt = coursor.blockFormat();
        frmt.setBackground(QBrush(Qt::gray));
        coursor.setBlockFormat(frmt);
    }
}

void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = fileModel->fileInfo(index).absoluteFilePath();
    QFile file(sPath); // path from on_treeFileExplorer_clicked

   // qDebug() << ui->textBrowser->tex;

    this->selectedFile = sPath;

    qDebug() << sPath;

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file.errorString()); // if unable to open throw error in msg box

    QTextStream in(&file); // else open file and put it in browser

    qDebug() << "Reding File " << sPath;

    QString text = in.readAll();

    if(sPath.endsWith(".cpp", Qt::CaseInsensitive) || sPath.endsWith(".h", Qt::CaseInsensitive) || sPath.endsWith(".c", Qt::CaseInsensitive)){
        text.replace("\t", "    ");
    }

    ui->textBrowser->document()->setPlainText(text.toUtf8());



    if(multiFileComment->containFile(this->selectedFile)){
        loadSelectedLines();
    }

    fileJustOpen = true;

    // ui->textBrowser->setStyleSheet("outline: 0px; outline: none; outline-style: none;"); not working :(
}

void MainWindow::on_actionZ_Folderu_triggered()
{
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->selectedDir = dir;

    qDebug() << "Initilizing TreeView with " << dir;

    //set root path
    fileModel->setRootPath(dir.path());

    ui->treeFileExplorer->setModel(fileModel);
    ui->treeFileExplorer->setRootIndex(fileModel->index(dir.path()));
}

void MainWindow::on_actionPliki_triggered()
{

}
