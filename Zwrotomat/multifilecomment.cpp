#include "multifilecomment.h"

MultiFileComment::MultiFileComment()
{
    this->m_files = new QHash<QString, QVector<int>*>;
}

/*
* Checking is MultiFileComment already contain given file
* @param fileName file to check
*/
bool MultiFileComment::containFile(QString fileName)
{
    return this->m_files->contains(fileName);
}

/*
 * Returns data contained in multifilecomment
 */
QHash<QString, QList<int> *> *MultiFileComment::getData()
{
    return this->m_files;
}

/*
* Getting selected lines indexes for given file
* @param fileName file
*/
QVector<int>* MultiFileComment::getLinesByName(QString fileName)
{
    if(!this->containFile(fileName)) //in case if comment don't containg file putting empty one.
        addNewFile(fileName);

    return this->m_files->value(fileName);
}

/*
* Adding given file to the multiFileComment
* In case of multiFileComment already containing fileName skiping.
*/
void MultiFileComment::addNewFile(QString fileName)
{
    if(!this->containFile(fileName))
        this->m_files->insert(fileName, new QVector<int>);
}

/*
* Modifier of m_comment variable
* @param comment value to assign
*/
void MultiFileComment::setComment(QString comment)
{
    this->m_comment = comment;
}

/*
* Accesor of m_comment value
* @returns assigned comment (QString)
*/
QString MultiFileComment::getComment()
{
    return this->m_comment;
}

/*
* Returns is m_isPositvie equal to true
*/
bool MultiFileComment::isPositive()
{
    return this->m_isPositvie;
}

/*
* Setts m_isPositvie to true
*/
void MultiFileComment::setPositive()
{
    this->m_isPositvie = true;
}

/*
* Setts m_isPositvie to false
*/
void MultiFileComment::setNegative()
{
    this->m_isPositvie = false;
}
