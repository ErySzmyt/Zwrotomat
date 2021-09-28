#ifndef GITFORM_H
#define GITFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QDir>
#include <gitwrapper.h>
namespace Ui {
class GitForm;
}

class GitForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit GitForm(QWidget *parent = nullptr);
    ~GitForm();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked(); //TODO dlaczego pushButton/pushButton_2 ?

signals:
    void sendDoneClonning(const QDir &);

private:
    Ui::GitForm *ui;
    static inline QDir s_last_selectedDir = QDir("C://");
    GitWrapper* gitWrapper;
};

#endif // GITFORM_H
