#ifndef FILEREADINGUTILS_H
#define FILEREADINGUTILS_H

#include <QString>



class FileReadingUtils
{
private:
    FileReadingUtils();

public:
    static QString readGivenLines(QList<int>* lineList, QString file);
};

#endif // FILEREADINGUTILS_H
