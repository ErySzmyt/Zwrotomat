#ifndef COMMENTEXTRACTOR_H
#define COMMENTEXTRACTOR_H

#include <QHash>
#include <QList>

class CommentExtractor
{
public:
    CommentExtractor();

private:
    QHash<QString, QList<int>*> filesIndexes;
};

#endif // COMMENTEXTRACTOR_H
