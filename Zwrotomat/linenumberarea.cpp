#include "linenumberarea.h"

/*
* Calculates hinted size of the LineNumberArea
* @returns calculated QSize
*/
QSize LineNumberArea::sizeHint() const
{
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}

/*
* Overriding paintEvent to repaint lineNumberArea
*/
void LineNumberArea::paintEvent(QPaintEvent *event)
{
    codeEditor->lineNumberAreaPaintEvent(event);
}
