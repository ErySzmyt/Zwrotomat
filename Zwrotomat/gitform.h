#ifndef GITFORM_H
#define GITFORM_H

#include <QWidget>

namespace Ui {
class GitForm;
}

class GitForm : public QWidget
{
    Q_OBJECT

public:
    explicit GitForm(QWidget *parent = nullptr);
    ~GitForm();

private:
    Ui::GitForm *ui;
};

#endif // GITFORM_H
