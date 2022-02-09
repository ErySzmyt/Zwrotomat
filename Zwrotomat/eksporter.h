#ifndef EKSPORTER_H
#define EKSPORTER_H

#include <QMainWindow>
#include <QHash>
#include <QDir>
#include "multifilecomment.h"
#include "filereadingutils.h"

namespace Ui {
class Eksporter;
}

class Eksporter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Eksporter(QWidget *parent = nullptr);
    ~Eksporter();

    void setComments(QHash<QString, MultiFileComment*>* commentMap);

private slots:
    void on_chooseButton_clicked();
    void on_export_2_clicked();

private:
    Ui::Eksporter *ui;
    QDir s_last_selectedDir;
    QHash<QString, MultiFileComment*> *m_Comments;
};

#endif // EKSPORTER_H
