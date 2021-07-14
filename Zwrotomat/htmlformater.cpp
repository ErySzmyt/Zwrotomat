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
    QFile file(HtmlFormater::MAIN_INDEX_RESOURCE);

    file.open(QIODevice::ReadOnly);
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
    QFile file(HtmlFormater::COMMENT_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

QString HtmlFormater::loadNegativeCommentTemplate(QString FileName, QString Code)
{
    QString data;
    QFile file(HtmlFormater::NEGATIVE_COMMENT_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

QString HtmlFormater::loadTextDisplayTemplate(QString comment)
{
    QString data;
    QFile file(HtmlFormater::COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${comment}", comment);
}

QString HtmlFormater::loadHeaderDisplayTemplate(QString Text)
{
    QString data;
    QFile file(HtmlFormater::COMMENT_HEADER_DISPLAY_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${comment}", Text);
}
