#ifndef FILEREADINGUTILS_H
#define FILEREADINGUTILS_H

#include "multifilecomment.h"

#include <QDir>
#include <QString>



class FileReadingUtils
{
private:
    FileReadingUtils();

public:
    static QString readGivenLines(QList<int>* lineList, QString file);

    static void exportData(QHash<QString, MultiFileComment*> *data, QDir outDir);
    static QHash<QString, MultiFileComment *> *importCommentsFromFile(QString path);

};

#endif // FILEREADINGUTILS_H
