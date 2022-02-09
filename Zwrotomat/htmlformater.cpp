#include "htmlformater.h"

#include <QDebug>

#include <QString>
#include <QStringBuilder>
#include <QFile>
#include <QIODevice>

HtmlFormater::HtmlFormater()
{ 
}

/**
 * @brief HtmlFormater::loadMainTemplate loading MainTemplate from resources
 * @param Subject param to fill
 * @param Topic param to fill
 * @param Checker param to fill
 * @param date param to fill
 * @param score param to fill
 * @return MainTemplate resource with injected values
 */
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

/**
 * @brief HtmlFormater::loadPositiveCommentTemplate loading PositiveCommentTemplate from resources
 * @param FileName param to fill
 * @param Code param to fill
 * @return PositiveCommentTemplate resource with injected values
 */
QString HtmlFormater::loadPositiveCommentTemplate(QString FileName, QString Code)
{
    QString data;
    QFile file(HtmlFormater::COMMENT_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

/**
 * @brief HtmlFormater::loadNegativeCommentTemplate loading NegativeCommentTemplate from resources
 * @param FileName param to fill
 * @param Code param to fill
 * @return NegativeCommentTemplate resource with injected values
 */
QString HtmlFormater::loadNegativeCommentTemplate(QString FileName, QString Code)
{
    QString data;
    QFile file(HtmlFormater::NEGATIVE_COMMENT_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${fileName}", FileName).replace("${code}", Code);
}

/**
 * @brief HtmlFormater::loadTextDisplayTemplate loading TextDisplayTemplate from resources
 * @param comment param to fill
 * @return TextDisplayTemplate resource with injected values
 */
QString HtmlFormater::loadTextDisplayTemplate(QString comment)
{
    QString data;
    QFile file(HtmlFormater::COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${comment}", comment);
}

/**
 * @brief HtmlFormater::loadHeaderDisplayTemplate loading HeaderDisplayTemplate from resources
 * @param Text param to fill
 * @return HeaderDisplayTemplate resource with injected values
 */
QString HtmlFormater::loadHeaderDisplayTemplate(QString Text)
{
    QString data;
    QFile file(HtmlFormater::COMMENT_HEADER_DISPLAY_TEMPLATE_RESOURCE);

    file.open(QIODevice::ReadOnly);
    data = file.readAll();

    file.close();

    return data.replace("${comment}", Text);
}
