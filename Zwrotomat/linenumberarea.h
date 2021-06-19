#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include "codeDisplay.h"
#include <QWidget>

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeDisplay *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeDisplay *codeEditor;
};

#endif // LINENUMBERAREA_H
