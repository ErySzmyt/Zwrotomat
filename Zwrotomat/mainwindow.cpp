#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>

#include <QLineEdit>

#include "codedisplay.h"


#include "highlighter.h"

#include "multifilecomment.h"

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

    ui->textBrowser->processCurrentLine(*this->multiFileComment, this->selectedFile);
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

    if(sPath.endsWith(".cpp", Qt::CaseInsensitive) || sPath.endsWith(".h", Qt::CaseInsensitive) || sPath.endsWith(".c", Qt::CaseInsensitive))
        text.replace("\t", "    ");

    ui->textBrowser->document()->setPlainText(text.toUtf8());

    if(multiFileComment->containFile(this->selectedFile))
        ui->textBrowser->loadSelectedLines(*this->multiFileComment, this->selectedFile);

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
void on_pushButton_clicked();
void MainWindow::on_addingCommentButton_clicked()
{
    /*
    // Func to add comment ( name + content)
    bool ok;
    //var to handle comment name
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Nazwa komentarza:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    //var to handle comment content
    QString textContent = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Treść komentarza:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    int positive = ui->radioButton->isChecked();

    QString allComment = "nazwa:"+text + " tresc:"+textContent + " pos:"+ QString::number(positive);
    ui->listWidget->addItem(allComment);
    if(ok && !text.isEmpty())
        qDebug() << text;
*/
    // Function to Add comment to listWidget
    MultiFileComment* comment = new MultiFileComment;
    bool ok;
    //var to handle comment name
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Nazwa komentarza:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    //var to handle comment content
    QString textContent = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Treść komentarza:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    // comment.addNewFile(); // adding fiel name
    int positive = ui->radioButton->isChecked();
    if (positive){
        comment->setPositive();
    }
    else{
        comment->setNegative();
    }
    QString allComment = "nazwa:"+text + " tresc:"+textContent;
    comment->setComment(allComment);
    ui->listWidget->addItem(allComment);

}
