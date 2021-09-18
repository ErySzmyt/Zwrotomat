#include "mainwindow.h"
#include "ui_Mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>

#include "generatorwindow.h"
#include <QLineEdit>

#include "highlighter.h"

#include "itemdisplay.h"
#include "multifilecomment.h"
#include "gitform.h"
#include "gitwrapper.h"
<<<<<<< Updated upstream

=======
#include "eksport.h"
#include "eksporter.h"
>>>>>>> Stashed changes
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

    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);

    ui->dockWidget_2->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
    ui->dockWidget_1->setAllowedAreas(Qt::AllDockWidgetAreas);

    addDockWidget(Qt::BottomDockWidgetArea, ui->dockWidget_1);
    addDockWidget(Qt::RightDockWidgetArea, ui->dockWidget_2);
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
    this->m_currentComment = new MultiFileComment();

    //clere QHash and dealocate occupied memory
    qDeleteAll(this->m_Comments->begin(), this->m_Comments->end());
    this->m_Comments->clear();

    this->m_Comments = new QHash<QString, MultiFileComment*>();

    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Project"), QDir::currentPath());
    this->m_selectedDir = dir;

    qDebug() << "Initilizing TreeView with " << dir;

    //set root path
    m_fileModel->setRootPath(dir.path());

    ui->treeFileExplorer->setModel(m_fileModel);
    ui->treeFileExplorer->setRootIndex(m_fileModel->index(dir.path()));
}

void MainWindow::on_actionKomentarze_triggered()
{
    ui->dockWidget_1->show();
}


void MainWindow::on_actionPliki_triggered()
{
    ui->dockWidget_2->show();
}

/*
 *  Add new comment
 */
void MainWindow::on_addingCommentButton_clicked()
{
    bool ok;

    QString text = QInputDialog::getText(this, tr("Dodawanie Komentarza"), tr("Wyświetlana Nazwa:"), QLineEdit::Normal,"", &ok);
    if(ok && !text.isEmpty()){
        qDebug() << text;

        QListWidgetItem* item = new QListWidgetItem();

        ItemDisplay* buttons = new ItemDisplay(this);
        buttons->setText(text);

        if(m_Comments->size() > 0){
            MultiFileComment* comment = new MultiFileComment();
            this->m_Comments->insert(text, comment);
        }else
            this->m_Comments->insert(text, this->m_currentComment);

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
                ui->commentEdit->document()->setPlainText("");
            }

            delete m_Comments->value(text);
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
}

void MainWindow::doneClonning(const QDir &clonedDir)
{
    this->m_currentComment = new MultiFileComment();

    //clere QHash and dealocate occupied memory
    qDeleteAll(this->m_Comments->begin(), this->m_Comments->end());
    this->m_Comments->clear();

    this->m_Comments = new QHash<QString, MultiFileComment*>();

    this->m_selectedDir = clonedDir;

    qDebug() << "Initilizing TreeView with " << clonedDir;

    //set root path
    m_fileModel->setRootPath(clonedDir.path());

    ui->treeFileExplorer->setModel(m_fileModel);
    ui->treeFileExplorer->setRootIndex(m_fileModel->index(clonedDir.path()));

}

void MainWindow::changePositivityOfComment(const QString &text, const bool &isChecked)
{
    MultiFileComment* com = m_Comments->value(text);
    (isChecked)? com->setPositive() : com->setNegative();
    qDebug()<<"Positivity changed"<< com<<" "<<com->isPositive();
}

void MainWindow::loadCurrentFile()
{
    QFile file(this->m_selectedFile);

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "Error", file.errorString()); // if unable to open throw error in msg box

    QTextStream in(&file); // else open file and put it in browser

    qDebug() << "Reding File " << this->m_selectedFile;

    QString text = in.readAll();

    file.close();

    if(this->m_selectedFile.endsWith(".cpp", Qt::CaseInsensitive) || this->m_selectedFile.endsWith(".h", Qt::CaseInsensitive) || this->m_selectedFile.endsWith(".c", Qt::CaseInsensitive))
        text.replace("\t", "    ");

    ui->textBrowser->document()->setPlainText(text.toUtf8());

    if(m_currentComment->containFile(this->m_selectedFile))
        ui->textBrowser->loadSelectedLines(*this->m_currentComment, this->m_selectedFile);
}

void MainWindow::on_commentEdit_textChanged()
{
    m_currentComment->setComment(ui->commentEdit->toPlainText());
}

void MainWindow::on_actionGeneruj_triggered()
{
    GeneratorWindow* generatorWindow = new GeneratorWindow(this, m_Comments);
    generatorWindow->show();
}

void MainWindow::on_actionPusty_triggered()
{
    this->m_currentComment = new MultiFileComment();
    this->m_Comments = new QHash<QString, MultiFileComment*>();

    ui->textBrowser->document()->setPlainText("");
    ui->commentEdit->document()->setPlainText("");

    ui->listWidget->clear();
}

void MainWindow::on_actionGit_triggered()
{
    //otworzyc okno do wyboru folderu i wykonac dzialania
    GitForm* gitform = new GitForm(this);
    gitform->show();
}

void MainWindow::on_actionEksportuj_2_triggered()
{
<<<<<<< Updated upstream
    // extract comments
=======

    //extract
    Eksporter* eksportForm = new Eksporter();
    eksportForm->setComments(this->m_Comments);
    eksportForm->show();
}
>>>>>>> Stashed changes

}
