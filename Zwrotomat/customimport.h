#ifndef CUSTOMIMPORT_H
#define CUSTOMIMPORT_H

#include <QMainWindow>
#include "QDir"
#include "QHash"
#include "multifilecomment.h"
namespace Ui {
class CustomImport;
}

class CustomImport : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomImport(QWidget *parent = nullptr);
    ~CustomImport();
    void importCommentsFromFile(QDir);
private  slots:
    void on_chooseButton_clicked();

    void on_export_2_clicked();

private:
    Ui::CustomImport *ui;
    QDir s_last_selectedDir;
    QHash<QString, MultiFileComment*> *m_Comments;
};

#endif // CUSTOMIMPORT_H
