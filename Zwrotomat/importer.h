#ifndef IMPORTER_H
#define IMPORTER_H

#include <QMainWindow>
#include <QDir>
#include <multifilecomment.h>

namespace Ui {
class Importer;
}

class Importer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Importer(QWidget *parent = nullptr);
    QHash<QString, MultiFileComment*>* importCommentsFromFile();
    ~Importer();

private:
    Ui::Importer *ui;
    QDir s_last_selectedDir;
    QHash<QString, MultiFileComment*> *m_Comments;
};

#endif // IMPORTER_H
