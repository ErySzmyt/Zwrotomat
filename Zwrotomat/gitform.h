#ifndef GITFORM_H
#define GITFORM_H

#include <QWidget>
#include <QDir>
namespace Ui {
class GitForm;
}

class GitForm : public QWidget
{
    Q_OBJECT

public:
    explicit GitForm(QWidget *parent = nullptr);
    ~GitForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GitForm *ui;
    static inline QDir s_last_selectedDir = QDir("C://");
};

#endif // GITFORM_H
