#include "filereadingutils.h"

#include <QFile>
#include <QTextStream>

FileReadingUtils::FileReadingUtils()
{

}

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

    return result;
}
