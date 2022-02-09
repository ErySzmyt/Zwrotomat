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
#include "eksporter.h"
<<<<<<< Updated upstream
=======
#include "importer.h"
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

/**
 * @brief MainWindow::on_textBrowser_cursorPositionChanged
 * Action on cursor position channged
 */
void MainWindow::on_textBrowser_cursorPositionChanged()
{
    ui->textBrowser->processCurrentLine(*this->m_currentComment, this->m_selectedFile);
}

/**
 * @brief MainWindow::on_treeFileExplorer_clicked action on clicked file in treeview
 * @param index selected index
 */
void MainWindow::on_treeFileExplorer_clicked(const QModelIndex &index)
{
    QString sPath = m_fileModel->fileInfo(index).absoluteFilePath();
    this->m_selectedFile = sPath;

    qDebug() << sPath;

    loadCurrentFile();
}

/**
 * @brief MainWindow::on_actionZ_Folderu_triggered
 * Action on loading files from given folder
 */
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

/**
 * @brief MainWindow::on_actionKomentarze_triggered
 * Action for showing cloased docking 'comment' widget
 */
void MainWindow::on_actionKomentarze_triggered()
{
    ui->dockWidget_1->show();
}

/**
 * @brief MainWindow::on_actionPliki_triggered
 * Loading given file
 */
void MainWindow::on_actionPliki_triggered()
{
    ui->dockWidget_2->show();
}

/**
 * @brief MainWindow::on_addingCommentButton_clicked
 * Action for adding comment
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
        } else
            this->m_Comments->insert(text, this->m_currentComment);

        item->setSizeHint(buttons->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, buttons);

        buttons->focusWidget();

        selectComment(text);
    }
}

/**
 * @brief MainWindow::removeComment
 * Removes the item from the comment list
 * @param text
 * key of the comment to remove
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

/**
 * @brief MainWindow::selectComment Action for changing selected comment
 * @param text key of the comment to load
 */
void MainWindow::selectComment(const QString &text)
{

    this->m_currentComment = this->m_Comments->value(text);
    //reloading lines
    if(!this->m_selectedFile.isEmpty()){
        this->loadCurrentFile();
        ui->textBrowser->loadSelectedLines(*this->m_currentComment, this->m_selectedFile);
    }
    ui->commentEdit->setText(m_currentComment->getComment());
}

/**
 * @brief MainWindow::doneClonning
 * Action to preform afther git cloning
 * @param clonedDir cloned dir
 */
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

/**
 * @brief MainWindow::loadCurrentFile
 * Reloading currently displayed file
 */
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

/**
 * @brief MainWindow::on_commentEdit_textChanged
 * Updating comment in memory when text in window changes
 */
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

/**
 * @brief MainWindow::on_actionGit_triggered
 * Opening git export window
 */
void MainWindow::on_actionGit_triggered()
{
    //otworzyc okno do wyboru folderu
    GitForm* gitform = new GitForm(this);
    gitform->show();
}

/**
 * @brief MainWindow::on_actionEksport_triggered
 * Openning export window
 */
void MainWindow::on_actionEksport_triggered()
{
    qDebug() <<"debug on_actionEksport_triggered";
    // extract comments
    Eksporter* eksport = new Eksporter(this);
    eksport->setComments(this->m_Comments);
    eksport->show();

}

/**
 * @brief MainWindow::on_actionImport_triggered
 * Opening import window
 */
void MainWindow::on_actionImport_triggered()
{
<<<<<<< Updated upstream
    // import
=======
    Importer* import = new Importer(this);
    import->show();
}

/**
 * @brief MainWindow::on_actionImport_triggered
 * Action on reciving Import
 */
void MainWindow::reciveImport(QHash<QString, MultiFileComment*>* s)
{
    qDeleteAll(this->m_Comments->begin(),this->m_Comments->end());

    this->m_Comments = s;

    qDebug() << "size imported:"<<this->m_Comments->size();
    QHash<QString, MultiFileComment*>::iterator i;
    for (i = this->m_Comments->begin(); i != this->m_Comments->end(); ++i) {

        QListWidgetItem* item = new QListWidgetItem();

        ItemDisplay* buttons = new ItemDisplay(this);

        buttons->setText(i.key());
        item->setSizeHint(buttons->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, buttons);
        qDebug() << i.key();
        qDebug() <<"comment:"<< i.value()->getComment();
    }

>>>>>>> Stashed changes
}
