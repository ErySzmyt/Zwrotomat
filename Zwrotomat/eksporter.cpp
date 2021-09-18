#include "eksporter.h"
#include "ui_eksporter.h"
#include "QDir"
#include "QFileDialog"
#include "QHash"
#include <QFile>
#include <QTextStream>
#include "filereadingutils.h"
Eksporter::Eksporter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Eksporter)
{
    ui->setupUi(this);
}

void Eksporter::setComments(QHash<QString, MultiFileComment *> *commentMap)
{
    //set comments for export
    this->m_Comments = commentMap;
}

Eksporter::~Eksporter()
{
    delete ui;
}

void Eksporter::on_chooseButton_clicked()
{
    // choose folder for comments export and display path in UI
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->s_last_selectedDir = dir;
    ui->f_path->setText(dir.path());
}

void Eksporter::on_export_2_clicked()
{
    // export comments
    qDebug() << "start export";
    QHashIterator<QString, MultiFileComment*> i(*this->m_Comments);
    //QString text;
    qDebug() << "::Starting loop::: ";
    while (i.hasNext()){
        i.next();
        qDebug() << "::Comment Name::: " << i.key();

        MultiFileComment* multifileComment = i.value();
        qDebug() << "::Comment::: " << multifileComment->getComment();
        qDebug() << "::CommentData::: " <<multifileComment->getData();


        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();

            QFileInfo fileInfo(z.key());

            qDebug() << "::File::: " << z.key();

            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive())
                    qDebug() <<"Positive"<< "::File::: " << fileInfo.fileName() <<"::"<< selectedLines;
                    //comment += HtmlFormater::loadPositiveCommentTemplate(fileInfo.fileName(), selectedLines);
                else
                    qDebug() <<"Negative"<< "::File::: " << fileInfo.fileName() <<"::"<< selectedLines;
                    //comment += HtmlFormater::loadNegativeCommentTemplate(fileInfo.fileName(), selectedLines);
            }
        }



    }

}
