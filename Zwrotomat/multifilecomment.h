#ifndef MULTIFILECOMMENT_H
#define MULTIFILECOMMENT_H

#include <QHash>
#include <QString>

class MultiFileComment
{
public:

    MultiFileComment();
    MultiFileComment(QHash<QString, QList<int> *> *, QString, bool);
    ~MultiFileComment();

    bool containFile(QString fileName);
    QHash<QString, QList<int>*>* getData();
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
    bool m_isPositvie = false;
};

#endif // MULTIFILECOMMENT_H
