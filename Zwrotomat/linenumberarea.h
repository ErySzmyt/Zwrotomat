#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include "codedisplay.h"
#include <QWidget>

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeDisplay *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CodeDisplay *codeEditor;
};

#endif // LINENUMBERAREA_H
