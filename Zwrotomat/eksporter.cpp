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
    QString comment = "<?xml version='1.0' encoding='UTF-8'?> \n <comments-extractions> \n";
    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();
        qDebug() << "::Comment Name::: " << i.key();
        comment +="<comment-start> \n";
        comment +="<comment-number>" + i.key()+"</comment-number>\n";

        //comment += HtmlFormater::loadHeaderDisplayTemplate(i.key());

        MultiFileComment* multifileComment = i.value();
        comment += "<comment>" + multifileComment->getComment() + "</comment>\n";
        qDebug() << "::Comment::: " << multifileComment->getComment();



        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();

            QFileInfo fileInfo(z.key());
            comment += "<File>\n";
            qDebug() << "::File::: " << z.key();
            qDebug() << "::Value::: " <<z.value();
            comment += "<File-name>" + z.key() + "</File-name>\n";
            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive()){
                    // psoitive comment
                    qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                    comment += "<Positive>  True </Positive>\n";
                    comment += "<Lines> \n";
                     for(const auto& i : *z.value()){
                         qDebug() << i;
                         comment += "<line>";
                         QString s = QString::number(i);
                         comment += s;
                         comment += "</line>\n";
                     }
                    comment += "</Lines>\n";
                   // comment += fileInfo.fileName(), selectedLines;
                }
                else{
                    // negative comment
                     qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                     comment += "<Positive>  Flase </Positive>\n";
                     comment += "<Lines> \n";
                     for(const auto& i : *z.value()){
                         qDebug() << i;
                         comment += "<line>";
                         QString s = QString::number(i);
                         comment += s;
                         comment += "</line>\n";
                     }
                     comment += "</Lines> \n";
                    }
            }
            comment +="</File>\n";

        }
      comment +="</comment-start> \n";
    }
    comment += "</comments-extractions>";
    // write to file
    QFile file(s_last_selectedDir.path() + "/commentExport.xml" );
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << s_last_selectedDir.path()+"commentExport.txt";
        qDebug() << "write";
        QTextStream out(&file);
             out << comment;
    }
    file.close();
}
