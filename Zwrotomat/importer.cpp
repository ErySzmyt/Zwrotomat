#include "importer.h"
#include "ui_importer.h"
<<<<<<< Updated upstream
#include "filereadingutils.h"
=======
>>>>>>> Stashed changes

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <msxml.h>
<<<<<<< Updated upstream
=======
#include <QtXml>
#include <QFileDialog>
#include <QFile>
>>>>>>> Stashed changes


Importer::Importer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Importer)
{
<<<<<<< Updated upstream
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
=======
   ui->setupUi(this);
   connect(this,SIGNAL(setCommentsAfterImport(QHash<QString, MultiFileComment*>*)), parent, SLOT(reciveImport(QHash<QString, MultiFileComment*>*)));
}

Importer::~Importer()
{
    delete ui;
}

/**
 * @brief Importer::on_chooseButton_clicked Action on chossing new input path
 */
void Importer::on_chooseButton_clicked()
{
    // choose folder for comments export and display path in UI
    QString file = QFileDialog::getOpenFileName(0, ("Select Import XML file"));
    this->s_last_selectedFile = file;
    qDebug() << file;
    ui->f_path->setText(file);
}

/**
 * @brief Importer::on_import_2_clicked action on importing selected path
 */
void Importer::on_import_2_clicked()
{
    auto data = FileReadingUtils::importCommentsFromFile(this->s_last_selectedFile);

    emit(setCommentsAfterImport(data));
>>>>>>> Stashed changes
}
