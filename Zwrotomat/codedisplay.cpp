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

    connect(this, &CodeDisplay::blockCountChanged, this, &CodeDisplay::updateLineNumberAreaWidth);
    connect(this, &CodeDisplay::updateRequest, this, &CodeDisplay::updateLineNumberArea);
    //connect(this, &CodeDisplay::cursorPositionChanged, this, &CodeDisplay::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
}

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

bool CodeDisplay::isMouseOver()
{
    return this->mouseOver;
}

void CodeDisplay::loadSelectedLines(MultiFileComment &multiFileComment, QString selectedFile)
{
    for(int i : *multiFileComment.getLinesByName(selectedFile)) {
        QTextCursor coursor(this->document()->findBlockByLineNumber(i));
        QTextBlockFormat frmt = coursor.blockFormat();
        frmt.setBackground(QBrush(Qt::gray));
        coursor.setBlockFormat(frmt);
    }
}

void CodeDisplay::processCurrentLine(MultiFileComment &multiFileComment, QString selectedFile)
{
    const QString fileName = selectedFile;
    Qt::KeyboardModifiers key = QGuiApplication::queryKeyboardModifiers();

    int selectedline = this->textCursor().blockNumber();

    if(!multiFileComment.containFile(fileName))
        multiFileComment.addNewFile(fileName);

    if(isMouseOver()) {
        QTextCursor cur = this->textCursor();
        QTextBlockFormat f;

        if(multiFileComment.getLinesByName(fileName)->contains(selectedline)) {
            if(key != Qt::ShiftModifier)
                return;

            multiFileComment.
                    getLinesByName(selectedFile)->
                    removeAt(multiFileComment.getLinesByName(selectedFile)->
                             indexOf(selectedline));

            f.setBackground(Qt::white);
        }else
             if(key != Qt::ShiftModifier){
                 multiFileComment.getLinesByName(fileName)->append(selectedline);
                 f.setBackground(Qt::gray);
             }

        this->setTextCursor(cur);
        cur.select(QTextCursor::LineUnderCursor);
        cur.setBlockFormat(f);
      }
}

void CodeDisplay::enterEvent(QEnterEvent *event)
{
    this->mouseOver = true;

    QWidget::enterEvent(event);
}

void CodeDisplay::leaveEvent(QEvent * event)
{
     this->mouseOver = false;

    QWidget::leaveEvent(event);
}

void CodeDisplay::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeDisplay::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeDisplay::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}