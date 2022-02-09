#include "eksporter.h"
#include "ui_eksporter.h"
#include "QDir"
#include "QFileDialog"
#include "QHash"
#include <QFile>
#include <QTextStream>

Eksporter::Eksporter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Eksporter)
{
    ui->setupUi(this);
}

/**
 * @brief Eksporter::setComments setter for commentMap, because mateusz decided so
 * @param commentMap pointer to comment map
 */
void Eksporter::setComments(QHash<QString, MultiFileComment *> *commentMap)
{
    //set comments for export
    this->m_Comments = commentMap;
}

Eksporter::~Eksporter()
{
    delete ui;
}

/**
 * @brief Eksporter::on_chooseButton_clicked action on chosing output directory
 */
void Eksporter::on_chooseButton_clicked()
{
    // choose folder for comments export and display path in UI
    QDir dir = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    this->s_last_selectedDir = dir;
    ui->f_path->setText(dir.path());
}

/**
 * @brief Eksporter::on_export_2_clicked action on export
 */
void Eksporter::on_export_2_clicked()
{
<<<<<<< Updated upstream
    // export comments
    QString comment = "<?xml version='1.0' encoding='UTF-8'?> <comments-extractions> \n";
    QHashIterator<QString, MultiFileComment*> i(*m_Comments);
    while (i.hasNext()) {
        i.next();
        qDebug() << "::Comment Name::: " << i.key();
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

            qDebug() << "::File::: " << z.key();
            qDebug() << "::Value::: " <<z.value();
            comment += "<File>" + z.key() + "</File>\n";
            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
                if(multifileComment->isPositive()){
                    // psoitive comment
                    qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                    comment += "<Positive>  True </Positive>\n";
                    comment += "<Lines>" + fileInfo.fileName() + selectedLines + "</Lines>\n";
                   // comment += fileInfo.fileName(), selectedLines;
                }
                else{
                    // negative comment
                     qDebug() << "::File::: " << fileInfo.fileName(), selectedLines;
                     comment += "<Positive>  Flase </Positive>\n";
                     comment += "<Lines>" + fileInfo.fileName() + selectedLines + "</Lines>\n";
                    //comment += fileInfo.fileName(), selectedLines;
                    }
            }
        }

       // comment += HtmlFormater::loadTextDisplayTemplate(multifileComment->getComment());
       // body += comment;
    }
    comment += "</comments-extractions>";
    // write to file
    QFile file(s_last_selectedDir.path() + "/commentExport.txt" );
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << s_last_selectedDir.path()+"commentExport.txt";
        qDebug() << "write";
        QTextStream out(&file);
             out << comment;
    }
    file.close();
=======
    FileReadingUtils::exportData(this->m_Comments, this->s_last_selectedDir);
>>>>>>> Stashed changes
}
