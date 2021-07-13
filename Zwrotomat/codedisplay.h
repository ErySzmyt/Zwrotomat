#ifndef CODEDISPLAY_H
#define CODEDISPLAY_H

#include "multifilecomment.h"

#include <QObject>
#include <QPlainTextEdit>

class CodeDisplay : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeDisplay(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    bool isMouseOver();

    void loadSelectedLines(MultiFileComment &multiFileComment, QString selectedFile);
    void processCurrentLine(MultiFileComment &multiFileComment, QString selectedFile);

    virtual void enterEvent(QEnterEvent *event) override;
    virtual void leaveEvent(QEvent * event) override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    QWidget *lineNumberArea;
    bool mouseOver = false;
};

#endif // CODEDISPLAY_H
