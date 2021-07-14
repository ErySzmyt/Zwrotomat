#include "filereadingutils.h"
#include "generatorwindow.h"
#include "htmlformater.h"
#include "ui_generatorwindow.h"
#include "multifilecomment.h"

#include <algorithm>
#include <algorithm>
#include <QStringBuilder>
#include <QDateTime>
#include <QFileInfo>
#include <QMessageBox>

#include <QFileDialog>

GeneratorWindow::GeneratorWindow(QWidget *parent, QHash<QString, MultiFileComment*> *m_Comments) :
    QMainWindow(parent),
    ui(new Ui::GeneratorWindow)
{
    ui->setupUi(this);

    ui->subjectTextEdit->setPlainText(s_last_subject);
    ui->topicTextEdit->setPlainText(s_last_topic);
    ui->checkerTextEdit->setPlainText(s_last_checker);

    this->m_Comments = m_Comments;
    ui->outputDirDisplay->setText(this->s_last_selectedDir.path());
}

GeneratorWindow::~GeneratorWindow()
{
    delete ui;
}


void GeneratorWindow::on_generateButton_clicked()
{
    QString mainPage = HtmlFormater::loadMainTemplate(
                ui->subjectTextEdit->toPlainText(),
                ui->topicTextEdit->toPlainText(),
                ui->checkerTextEdit->toPlainText(),
                QDateTime::currentDateTime().toString("dd-MM-yyyy"),
                ui->scoreTextEdit->toPlainText()
                );

    QString body = "";

    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();

        QString comment = "";
        qDebug() << "::Comment Name::: " << i.key();

        comment += HtmlFormater::loadHeaderDisplayTemplate(i.key());

        MultiFileComment* multifileComment = i.value();
        qDebug() << "::Comment::: " << multifileComment->getComment();


        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();

            QFileInfo fileInfo(z.key());

            qDebug() << "::File::: " << z.key();

            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive())
                    comment += HtmlFormater::loadPositiveCommentTemplate(fileInfo.fileName(), selectedLines);
                else
                    comment += HtmlFormater::loadNegativeCommentTemplate(fileInfo.fileName(), selectedLines);
            }
        }

        comment += HtmlFormater::loadTextDisplayTemplate(multifileComment->getComment());

        body += comment;
    }

    mainPage.replace("${body}", body);

    QString filename = ui->fileNameTextEdit->toPlainText();

    if(filename.isEmpty()){
       QMessageBox::information(0, "Error", "Missing file name");
       return;
    }

    if(!filename.endsWith(".html")){
        filename += ".html";
    }

    QString path = this->s_last_selectedDir.path() + filename;

    const QString qPath(path);
    QFile qFile(qPath);
    if (qFile.open(QIODevice::WriteOnly)) {
      QTextStream out(&qFile); out << mainPage;
      qFile.close();
    }

}

void GeneratorWindow::on_subjectTextEdit_textChanged()
{
    s_last_subject = ui->subjectTextEdit->toPlainText();
}

void GeneratorWindow::on_topicTextEdit_textChanged()
{
    s_last_topic = ui->topicTextEdit->toPlainText();
}

void GeneratorWindow::on_checkerTextEdit_textChanged()
{
    s_last_checker = ui->checkerTextEdit->toPlainText();
}

void GeneratorWindow::on_outputDirPicker_clicked()
{
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    s_last_selectedDir = dir;
    ui->outputDirDisplay->setText(dir.path());
}
