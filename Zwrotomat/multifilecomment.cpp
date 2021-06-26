#include "multifilecomment.h"

MultiFileComment::MultiFileComment()
{
    this->m_files = new QHash<QString, QVector<int>*>;
}

bool MultiFileComment::containFile(QString fileName)
{
    return this->m_files->contains(fileName);
}

QVector<int> *MultiFileComment::getLinesByName(QString fileName)
{
    if(!this->containFile(fileName))
        addNewFile(fileName);

    return this->m_files->value(fileName);
}

void MultiFileComment::addNewFile(QString fileName)
{
    if(!this->containFile(fileName))
        this->m_files->insert(fileName, new QVector<int>);
}

void MultiFileComment::setComment(QString comment)
{
    this->m_comment = &comment;
}

QString* MultiFileComment::getComment()
{
    return this->m_comment;
}

bool MultiFileComment::isPositive(){
    return this->m_isPositvie;
};

void MultiFileComment::setPositive(){
    this->m_isPositvie = true;
};

void MultiFileComment::setNegative(){
    this->m_isPositvie = false;
};
