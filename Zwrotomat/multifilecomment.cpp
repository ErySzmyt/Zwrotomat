#include "multifilecomment.h"

MultiFileComment::MultiFileComment()
{

}

bool MultiFileComment::containFile(QString fileName)
{
    return this->files->contains(fileName);
}

QVector<int> *MultiFileComment::getLinesByName(QString fileName)
{
    if(!this->containFile(fileName))
        this->files->insert(fileName, new QVector<int>);

    return this->files->value(fileName);
}

void MultiFileComment::setComment(QString comment)
{
    this->comment = &comment;
}

QString* MultiFileComment::getComment()
{
    return this->comment;
}
