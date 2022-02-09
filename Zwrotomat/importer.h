#ifndef IMPORTER_H
#define IMPORTER_H

#include <QMainWindow>
#include <QDir>
#include <multifilecomment.h>
<<<<<<< Updated upstream
=======
#include <filereadingutils.h>

>>>>>>> Stashed changes

namespace Ui {
class Importer;
}

class Importer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Importer(QWidget *parent = nullptr);
<<<<<<< Updated upstream
    QHash<QString, MultiFileComment*>* importCommentsFromFile();
    ~Importer();

private:
    Ui::Importer *ui;
    QDir s_last_selectedDir;
    QHash<QString, MultiFileComment*> *m_Comments;
=======
    ~Importer();

signals:
    void setCommentsAfterImport(QHash<QString, MultiFileComment*>*);

private slots:
    void on_chooseButton_clicked();
    void on_import_2_clicked();

private:
    Ui::Importer *ui;
    QString s_last_selectedFile;
>>>>>>> Stashed changes
};

#endif // IMPORTER_H
