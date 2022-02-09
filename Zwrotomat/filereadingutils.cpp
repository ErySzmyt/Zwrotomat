#include "filereadingutils.h"

#include <QDomElement>
#include <QFile>
#include <QTextStream>

FileReadingUtils::FileReadingUtils()
{

}

/**
 * @brief FileReadingUtils::readGivenLines
 *  Reading lines specified in @param lineList from file specified by given path @param file
 *  method read file line by line, and if lineList contains current index then it reads and concats into output.
 * @param lineList lines to read from given file.
 * @param file file path of given file to read.
 * @return
 */
QString FileReadingUtils::readGivenLines(QList<int>* lineList, QString file)
{
    QFile inputFile((QString(file)));
    inputFile.open(QIODevice::ReadOnly);
    if (!inputFile.isOpen())
        return "";

    QTextStream stream(&inputFile);

    int i = 0;
    QString result = "";

    for (QString line = stream.readLine(); !line.isNull(); line = stream.readLine()) {
        /* process information */
        if(lineList->contains(i)){
            //result += (i == 0) ? line.simplified() : line;
            result += line;
            result += '\n';
        }
        i++;
    }

    inputFile.close();

    return result;
}

/**
 * @brief FileReadingUtils::exportData exporting data into file
 * @param data data to export
 * @param outDir output directory
 */
void FileReadingUtils::exportData(QHash<QString, MultiFileComment *> *data, QDir outDir)
{
    // export comments
    QString comment = "<?xml version='1.0' encoding='UTF-8'?>\n";
    QHashIterator<QString, MultiFileComment*> i(*data);
    comment += "<start_data>\n";
    while (i.hasNext()) {
        i.next();
        qDebug() << "::Comment Name::: " << i.key();
        comment +="<comment_start>\n";
        comment +="<comment_name>" + i.key()+"</comment_name>\n";

        //comment += HtmlFormater::loadHeaderDisplayTemplate(i.key());

        MultiFileComment* multifileComment = i.value();
        comment += "<comment>" + multifileComment->getComment() + "</comment>\n";
        qDebug() << "::Comment::: " << multifileComment->getComment();

        multifileComment->isPositive() ? comment += "<Positive>1</Positive>\n" : comment += "<Positive>0</Positive>\n";

        QHash<QString, QList<int>*>* filesIndexes = multifileComment->getData();
        QHashIterator<QString, QList<int>*> z(*filesIndexes);
        while (z.hasNext()) {
            z.next();

            QFileInfo fileInfo(z.key());
            comment += "<File>\n";
            qDebug() << "::File::: " << z.key();
            qDebug() << "::Value::: " <<z.value();
            comment += "<File_name>" + z.key() + "</File_name>\n";
            QString selectedLines = FileReadingUtils::readGivenLines(z.value(), z.key());

            if(!selectedLines.simplified().isEmpty()) {
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
            comment +="</File>\n";

        }
      comment +="</comment_start> \n";

    }
    comment += "</start_data>\n";
    // write to file
    QFile file(outDir.path() + "/commentExport.xml" );
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << outDir.path() + "commentExport.txt";
        qDebug() << "write";
        QTextStream out(&file);
             out << comment;
    }
    file.close();
}

QHash<QString, MultiFileComment *>* FileReadingUtils::importCommentsFromFile(QString path)
{
    QHash<QString, MultiFileComment *>* comments = new QHash<QString, MultiFileComment *>();

    QDomDocument xmlBOM;

    // Load xml file as raw data
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
    {
        // Error while loading file
        qDebug() << "Error while loading file";
        // return new QHash<QString, MultiFileComment *>();
     }
     // Set data into the QDomDocument before processing
     xmlBOM.setContent(&f);
     f.close();
     qDebug() << "loader debug";
     // Extract the root markup
     QDomElement root = xmlBOM.documentElement();
     // Get root names and attributes
     QString Type = root.tagName();

     // Get the first child of the root (Markup COMPONENT is expected)
     QDomElement Component = root.firstChild().toElement();

     //QHash<QString, MultiFileComment *> result = {};

     // Loop while there is a child
     while(!Component.isNull())
     {
         // Check if the child tag name is COMPONENT
         if (Component.tagName() == "comment_start")
         {
             // Get the first child of the component
             QDomElement Child = Component.firstChild().toElement();

             QString commentName;
             QString comment;
             QString text;
             bool is_positive;

             // Read each child of the component node
             while (!Child.isNull())
             {
                 // Read Name and value
                 if (Child.tagName()=="comment_name") commentName = Child.firstChild().toText().data();
                 if (Child.tagName()=="comment") comment = Child.firstChild().toText().data();
                 if (Child.tagName()=="Positive") is_positive = (bool)Child.firstChild().toText().data().toInt();
                 if (Child.tagName()=="File"){
                        QDomElement file_child = Child.firstChild().toElement();

                        QString file_name;

                        while (!file_child.isNull())
                        {
                            if (file_child.tagName()=="File_name") file_name = file_child.firstChild().toText().data();

                            QList<int> lines = {};

                            if (file_child.tagName()=="Lines"){
                                QDomElement lines_child = file_child.firstChild().toElement();
                                while (!lines_child.isNull())
                                {

                                    if (lines_child.tagName()=="line")
                                       lines.append(lines_child.firstChild().toText().data().toInt());

                                    lines_child = lines_child.nextSibling().toElement();
                                }
                            }

                            file_child = file_child.nextSibling().toElement();
                        }
                    }

                    // Next child
                    Child = Child.nextSibling().toElement();
                }
                QHash<QString, QList<int>*> * s = new QHash<QString, QList<int>*>;
                MultiFileComment cm(s,comment,is_positive);
                comments->insert(commentName,&cm);
            }
            // Next component
            Component = Component.nextSibling().toElement();
      }

     return comments;
}
