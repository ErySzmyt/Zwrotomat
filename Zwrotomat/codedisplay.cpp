#include "codedisplay.h"

#include "linenumberarea.h"
#include "multifilecomment.h"

#include <QGuiApplication>
#include <QPainter>
#include <QTextObject>
#include <QWidget>

CodeDisplay::CodeDisplay(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    setReadOnly(true);

    connect(this, &CodeDisplay::blockCountChanged, this, &CodeDisplay::updateLineNumberAreaWidth);
    connect(this, &CodeDisplay::updateRequest, this, &CodeDisplay::updateLineNumberArea);

    updateLineNumberAreaWidth(0);
}

/**
 * @brief CodeDisplay::lineNumberAreaPaintEvent Painting line Number Area
 * @param event
 */
void CodeDisplay::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
        int blockNumber = block.blockNumber();
        int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
        int bottom = top + qRound(blockBoundingRect(block).height());
        while (block.isValid() && top <= event->rect().bottom()) {
                if (block.isVisible() && bottom >= event->rect().top()) {
                    QString number = QString::number(blockNumber + 1);
                    painter.setPen(Qt::black);
                    painter.drawText(0, top, lineNumberArea->width()-2, fontMetrics().height(),
                                     Qt::AlignRight, number);
                }

                block = block.next();
                top = bottom;
                bottom = top + qRound(blockBoundingRect(block).height());
                ++blockNumber;
            }
}

/**
 * @brief CodeDisplay::lineNumberAreaWidth Calculte lenght of Number Area
 * @returns int number of pixels
 */
int CodeDisplay::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 5 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

/**
 * @brief CodeDisplay::isMouseOver Returns bool is mouse over current CodeDisplay widget
 * @return is mouse over text area
 */
bool CodeDisplay::isMouseOver()
{
    return this->mouseOver;
}

/**
 * @brief CodeDisplay::loadSelectedLines
 * Painting lines given by numbers(indexes) from multiFileComment for given file
 * @param multiFileComment &multiFileComment comment containing lines to select
 * @param selectedFile selectedFile
 */
void CodeDisplay::loadSelectedLines(MultiFileComment &multiFileComment, QString selectedFile)
{
    for(int i : *multiFileComment.getLinesByName(selectedFile)) {
        QTextCursor coursor(this->document()->findBlockByLineNumber(i));
        QTextBlockFormat frmt = coursor.blockFormat();
        frmt.setBackground(QBrush(Qt::gray));
        coursor.setBlockFormat(frmt);
    }
}

/**
 * @brief CodeDisplay::processCurrentLine adding or removing lines from given &multiFileComment
 * @param multiFileComment &multiFileComment comment containing lines
 * @param selectedFile selectedFile
 */
void CodeDisplay::processCurrentLine(MultiFileComment &multiFileComment, QString selectedFile)
{
    const QString fileName = selectedFile;
    Qt::KeyboardModifiers key = QGuiApplication::queryKeyboardModifiers();

    int selectedline = this->textCursor().blockNumber(); //selected line index

    if(!multiFileComment.containFile(fileName))
        multiFileComment.addNewFile(fileName);

    if(isMouseOver()) {
        QTextCursor cur = this->textCursor();
        QTextBlockFormat f;

        if(multiFileComment.getLinesByName(fileName)->contains(selectedline)) {
            if(key != Qt::ShiftModifier) //if shift isn't pressed
                return;

            multiFileComment.
                    getLinesByName(selectedFile)->
                    removeAt(multiFileComment.getLinesByName(selectedFile)->
                             indexOf(selectedline)); //removing selected line

            f.setBackground(Qt::white); //painting white
        }else
             if(key != Qt::ShiftModifier){
                 multiFileComment.getLinesByName(fileName)->append(selectedline); //adding selected line
                 f.setBackground(Qt::gray); //painting gray
             }

        this->setTextCursor(cur);
        cur.select(QTextCursor::LineUnderCursor);
        cur.setBlockFormat(f); //highlighting line
      }
}

/**
 * @brief CodeDisplay::enterEvent Overring on mouse over Event
 * @param event event
 */
void CodeDisplay::enterEvent(QEnterEvent *event)
{
    this->mouseOver = true;

    QWidget::enterEvent(event);
}

/**
 * @brief CodeDisplay::leaveEvent Overring on mouse leave Event
 * @param event event
 */
void CodeDisplay::leaveEvent(QEvent * event)
{
     this->mouseOver = false;

    QWidget::leaveEvent(event);
}

/**
 * @brief CodeDisplay::resizeEvent Overring resize Event to modify LineNumberArea
 * @param e resizeEvent
 */
void CodeDisplay::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

/**
 * @brief CodeDisplay::updateLineNumberAreaWidth updating LineNumberArea Width
 */
void CodeDisplay::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

/**
 * @brief CodeDisplay::updateLineNumberArea updating LineNumberArea
 * @param rect
 * @param dy
 */
void CodeDisplay::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}
