#include "importer.h"
#include "ui_importer.h"
#include "filereadingutils.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <msxml.h>


Importer::Importer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Importer)
{
    ui->setupUi(this);
}

QHash<QString, MultiFileComment *> *Importer::importCommentsFromFile()
{
    return 0;

}


/*
QHash<QString, MultiFileComment *> *Importer::importCommentsFromFile()
{
    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();
        qDebug() << "::Comment Name::: " << i.key();
        comment +="<comment-number>" + i.key()+"</comment-number>";
        MultiFileComment* multifileComment = i.value();
        comment += "<comment>" + multifileComment->getComment() + "</comment>";
        qDebug() << "::Comment::: " << multifileComment->getComment();

        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();
            QFileInfo fileInfo(z.key());
            qDebug() << "::File::: " << z.key();
            qDebug() << "::Value::: " <<z.value();
            comment += "<File>" + z.key() + "</File>";
            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());
            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive()){
                    // psoitive comment
                    qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                    comment += "<Positive>  True </Positive>";
                    comment += "<Lines>" + fileInfo.fileName() + selectedLines + "</Lines>";
                }
                else{
                    // negative comment
                     qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                     comment += "<Positive>  Flase </Positive>";
                     comment += "<Lines>" + fileInfo.fileName() + selectedLines + "</Lines>";
                    }
            }
        }

       // comment += HtmlFormater::loadTextDisplayTemplate(multifileComment->getComment());
       // body += comment;
    }
}
*/
Importer::~Importer()
{
    delete ui;
}
