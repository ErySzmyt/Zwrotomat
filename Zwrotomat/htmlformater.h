#ifndef HTMLFORMATER_H
#define HTMLFORMATER_H

#include <QString>



class HtmlFormater
{
public:
    HtmlFormater();

    const inline static QString MAIN_INDEX_RESOURCE = ":/Res/Templates/main_index.html";
    const inline static QString COMMENT_TEMPLATE_RESOURCE = ":/Res/Templates/comment_template.html";
    const inline static QString NEGATIVE_COMMENT_TEMPLATE_RESOURCE = ":/Res/Templates/comment_template_negative.html";

    const inline static QString COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE = ":/Res/Templates/comment_text_display.html";

    static QString loadMainTemplate(QString Subject, QString Topic, QString Checker, QString date, QString score);

    static QString loadPositiveCommentTemplate(QString FileName, QString Code);
    static QString loadNegativeCommentTemplate(QString FileName, QString Code);
    static QString loadTextDisplayTemplate(QString Text);

};

#endif // HTMLFORMATER_H
