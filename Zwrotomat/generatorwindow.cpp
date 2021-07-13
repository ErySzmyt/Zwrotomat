#include "filereadingutils.h"
#include "generatorwindow.h"
#include "htmlformater.h"
#include "ui_generatorwindow.h"

#include <algorithm>
#include <algorithm>
#include <QStringBuilder>
#include <QDateTime>


#include <MultiFileComment.h>
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
    // loadMainTemplate(QString Subject, QString Topic, QString Checker, QString date, QString score);
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
            qDebug() << "::File::: " << z.key();
            //std::sort(z.value()->begin(), z.value()->end()); //sorting lines

            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key()).replace("    ", "\t");

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive())
                    comment += HtmlFormater::loadPositiveCommentTemplate(z.key(), selectedLines);
                else
                    comment += HtmlFormater::loadNegativeCommentTemplate(z.key(), selectedLines);
            }
        }

        comment += HtmlFormater::loadTextDisplayTemplate(multifileComment->getComment());

        body += comment;
    }

    mainPage.replace("${body}", body);

    const QString qPath("testQTextStreamEncoding.txt");
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
}
