#ifndef MULTIFILECOMMENT_H
#define MULTIFILECOMMENT_H

#include <QHash>
#include <QString>



class MultiFileComment
{
public:
    MultiFileComment();
    ~MultiFileComment();

    bool containFile(QString fileName);
    QVector<int>* getLinesByName(QString fileName);
    void addNewFile(QString fileName);

    void setComment(QString comment);
    QString* getComment();

private:
    QHash<QString, QVector<int>*> *files;
    QString *comment;
};

#endif // MULTIFILECOMMENT_H
