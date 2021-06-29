#ifndef MULTIFILECOMMENT_H
#define MULTIFILECOMMENT_H

#include <QHash>
#include <QString>

class MultiFileComment
{
public:
    //TODO still no constructor :)
    MultiFileComment();
    ~MultiFileComment();

    bool containFile(QString fileName);
    QList<int>* getLinesByName(QString fileName);
    void addNewFile(QString fileName);
    void setComment(QString comment);

    bool isPositive();

    void setPositive();
    void setNegative();

    QString getComment();

private:
    QHash<QString, QList<int>*> *m_files;
    QString m_comment = "";
    bool m_isPositvie = true;
};

#endif // MULTIFILECOMMENT_H
