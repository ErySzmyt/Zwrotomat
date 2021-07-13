#include "filereadingutils.h"

#include <QFile>
#include <QTextStream>

FileReadingUtils::FileReadingUtils()
{

}

/*
* Reading lines specified in @param lineList from file specified by given path @param file
* method read file line by line, and if lineList contains current index then it reads and concats into output.
*
* @param lineList lines to read from given file.
* @param file path of given file to read.
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
            result += line;
            result += '\n';
        }
        i++;
    }

    inputFile.close();

    return result;
}
