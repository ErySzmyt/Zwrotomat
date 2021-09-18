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

    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();

        QString comment = "";
        qDebug() << "::Comment Name::: " << i.key();

        //comment += HtmlFormater::loadHeaderDisplayTemplate(i.key());

        MultiFileComment* multifileComment = i.value();
        qDebug() << "::Comment::: " << multifileComment->getComment();


        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();

            QFileInfo fileInfo(z.key());

            qDebug() << "::File::: " << z.key();
            qDebug() << "::Value::: " <<z.value();
            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive())
                    // psoitive comment
                    qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                   // comment += fileInfo.fileName(), selectedLines;
                else
                    // negative comment
                     qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                    //comment += fileInfo.fileName(), selectedLines;
            }
        }

       // comment += HtmlFormater::loadTextDisplayTemplate(multifileComment->getComment());

       // body += comment;
    }
}
