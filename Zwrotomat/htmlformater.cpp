#include "htmlformater.h"

#include <QDebug>

#include <QString>
#include <QStringBuilder>
#include <QFile>
#include <QIODevice>

HtmlFormater::HtmlFormater()
{ 
}

QString HtmlFormater::loadMainTemplate(QString Subject, QString Topic, QString Checker, QString date, QString score)
{
    QString data;
    QString fileName = HtmlFormater::MAIN_INDEX_RESOURCE;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"filenot opened";
    else
        data = file.readAll();

    file.close();

    return data
            .replace("${Subject}", Subject)
            .replace("${Topic}", Topic)
            .replace("${Checker}", Checker)
            .replace("${date}", date)
            .replace("${score}", score);
}

QString HtmlFormater::loadPositiveCommentTemplate(QString FileName, QString Code)
{
    QString data;
    QString fileName = HtmlFormater::COMMENT_TEMPLATE_RESOURCE;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"filenot opened";
    else
        data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

QString HtmlFormater::loadNegativeCommentTemplate(QString FileName, QString Code)
{
    QString data;
    QString fileName = HtmlFormater::NEGATIVE_COMMENT_TEMPLATE_RESOURCE;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"filenot opened";
    else
        data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

QString HtmlFormater::loadTextDisplayTemplate(QString comment)
{
    QString data;
    QString fileName = HtmlFormater::COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"filenot opened";
    else
        data = file.readAll();

    file.close();

    return data.replace("${comment}", comment);
}
