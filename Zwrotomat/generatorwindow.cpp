#include "generatorwindow.h"
#include "ui_generatorwindow.h"

#include <algorithm>
#include <algorithm>
#include <QStringBuilder>

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
	//TODO: Figure out why it's broken :( 
    QString outputPage = QFile(":/Res/Templates/main_index.html").readAll();

    outputPage.replace("${body}", "Dupa");

    qDebug() << outputPage;


    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();
        qDebug() << "::Comment Name::: " << i.key();

        MultiFileComment* multifileComment = i.value();
        qDebug() << "::Comment::: " << multifileComment->getComment();


        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();
            qDebug() << "::File::: " << z.key();
            std::sort(z.value()->begin(), z.value()->end()); //sorting lines



        }
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
