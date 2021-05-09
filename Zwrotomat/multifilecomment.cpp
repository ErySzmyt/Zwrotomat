#include "multifilecomment.h"

MultiFileComment::MultiFileComment()
{
    this->files = new QHash<QString, QVector<int>*>;
}

bool MultiFileComment::containFile(QString fileName)
{
    return this->files->contains(fileName);
}

QVector<int> *MultiFileComment::getLinesByName(QString fileName)
{
    if(!this->containFile(fileName))
        addNewFile(fileName);

    return this->files->value(fileName);
}

void MultiFileComment::addNewFile(QString fileName)
{
    if(!this->containFile(fileName))
        this->files->insert(fileName, new QVector<int>);
}

void MultiFileComment::setComment(QString comment)
{
    this->comment = &comment;
}

QString* MultiFileComment::getComment()
{
    return this->comment;
}
