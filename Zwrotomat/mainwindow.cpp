#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include "highlighter.h"
#include "itemdisplay.h"
#include "multifilecomment.h"
#include <iostream>
#include <fstream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->centralwidget);

    ui->textBrowser->setMouseTracking(true);

    m_highlighter = new Highlighter(ui->textBrowser->document());
    m_fileModel = new QFileSystemModel(this);

    this->m_currentComment = new MultiFileComment();
    this->m_Comments = new QHash<QString, MultiFileComment*>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_cursorPositionChanged()
{
    ui->textBrowser->processCurrentLine(*this->m_currentComment, this->m_selectedFile);
}

void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = m_fileModel->fileInfo(index).absoluteFilePath();
    this->m_selectedFile = sPath;

    qDebug() << sPath;

    loadCurrentFile();
}

void MainWindow::on_actionZ_Folderu_triggered()
{
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->m_selectedDir = dir;

    qDebug() << "Initilizing TreeView with " << dir;

    //set root path
    m_fileModel->setRootPath(dir.path());

    ui->treeFileExplorer->setModel(m_fileModel);
    ui->treeFileExplorer->setRootIndex(m_fileModel->index(dir.path()));
}

void MainWindow::on_actionPliki_triggered()
{

}
/*
 *  Add new comment
 */
void MainWindow::on_addingCommentButton_clicked()
{
    bool ok;

    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Nazwa kom:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);

    if(ok && !text.isEmpty()){
        qDebug() << text;

        QListWidgetItem* item = new QListWidgetItem();

        //QPushButton* pushButton = new QPushButton(text);
        ItemDisplay* buttons = new ItemDisplay(this);
        buttons->setText(text);


        if(m_Comments->size() > 0){
            MultiFileComment* comment = new MultiFileComment();

            this->m_Comments->insert(text, comment);
        }else{

            this->m_Comments->insert(text, this->m_currentComment);
        }


        item->setSizeHint(buttons->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, buttons);
    }
}

/*
 * Removes the item from the comment list
 */
void MainWindow::removeComment(const QString &text) {
    if(m_Comments->size() == 1){
        this->m_currentComment = new MultiFileComment();
        loadCurrentFile();
    }

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = ui->listWidget->item(i);
        auto itemWidget = dynamic_cast<ItemDisplay*>(ui->listWidget->itemWidget(item));
        if (itemWidget->getText() == text){

            if(m_Comments->value(text) == this->m_currentComment){
                ui->textBrowser->document()->setPlainText("");
            }

            //TODO free memory of removed comment, and remove it from HashMap
            m_Comments->remove(text);

            delete item;
            break;
        }
    }
}

/*
 * Change selected comment
 */
void MainWindow::selectComment(const QString &text)
{
    this->m_currentComment = m_Comments->value(text);
    //reloading lines
    this->loadCurrentFile();
    ui->textBrowser->loadSelectedLines(*this->m_currentComment, this->m_selectedFile);
    ui->commentEdit->setText(m_currentComment->getComment());
    /*// open comment edit window
    QWidget *wdg = new QWidget; // 2nd window for comment editor
    QTextEdit *textEditor = new QTextEdit(QApplication::);    // text editor widget

    wdg->adjustSize();
    wdg->show();*/
}
/*
 * Change if comment is positive or not
 */
void MainWindow::changePoitivityOfComment(const QString &text, const bool &isChecked)
{

      MultiFileComment* com = m_Comments->value(text);
      (isChecked)? com->setPositive() : com->setNegative();
      qDebug()<<"Positivity changed"<< com<<" "<<com->isPositive();
}

void MainWindow::loadCurrentFile()
{
    QFile file(this->m_selectedFile);

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file.errorString()); // if unable to open throw error in msg box

    QTextStream in(&file); // else open file and put it in browser

    qDebug() << "Reding File " << this->m_selectedFile;

    QString text = in.readAll();

    if(this->m_selectedFile.endsWith(".cpp", Qt::CaseInsensitive) || this->m_selectedFile.endsWith(".h", Qt::CaseInsensitive) || this->m_selectedFile.endsWith(".c", Qt::CaseInsensitive))
        text.replace("\t", "    ");

    ui->textBrowser->document()->setPlainText(text.toUtf8());

    if(m_currentComment->containFile(this->m_selectedFile))
        ui->textBrowser->loadSelectedLines(*this->m_currentComment, this->m_selectedFile);
}
/*
 *  Updates comment data every time it is changed
 */
void MainWindow::on_commentEdit_textChanged()
{
    m_currentComment->setComment(ui->commentEdit->toPlainText());
}
void MainWindow::on_pushButton_clicked(bool){};
/*
 *  Generate Raport with all entered comments
 *  Creates .txt file named Comment_studentName on desktop
 */
void MainWindow::on_pushButton_clicked()
{

    bool ok, ok2;

    QString studentName = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Imie i Nazwisko:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    QString grade = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Ocena"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok2);
    if (ok && !studentName.isEmpty()){
        std::ofstream myfile;
        std::string fileName = "Comment"+studentName.toStdString()+".txt";
        myfile.open (fileName);
        qDebug() << studentName;
        for (auto const& x : *m_Comments)
        {

            myfile <<"Komentarz:"<<x->getComment().toStdString()<< "Pozytywnosc:"<< x->isPositive()<< "Plik:"  << x->getFile().toStdString();
        }

        if (ok2 && !studentName.isEmpty()){
            myfile << "ocena:"+grade.toStdString();
        }
        else{
             myfile << "ocena: nie wprowadzono";
        }
         myfile.close();
    }


}
