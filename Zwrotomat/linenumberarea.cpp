#include "linenumberarea.h"

/**
 * @brief LineNumberArea::sizeHint Calculates hinted size of the LineNumberArea
 * @return calculated QSize
 */
QSize LineNumberArea::sizeHint() const
{
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}

/**
 * @brief LineNumberArea::paintEvent
 * Overriding paintEvent to repaint lineNumberArea
 * @param event
 */
void LineNumberArea::paintEvent(QPaintEvent *event)
{
    codeEditor->lineNumberAreaPaintEvent(event);
}
