#ifndef EKSPORT_H
#define EKSPORT_H

#include <QWidget>
#include <QDir>
#include "multifilecomment.h"

namespace Ui {
class eksport;
}

class eksport : public QWidget
{
    Q_OBJECT

public:
    explicit eksport(QWidget *parent = nullptr);
    ~eksport();

private slots:
    void on_chooseButton_clicked();

    void on_export_2_clicked();

private:
    Ui::eksport *ui;
    static inline QDir s_last_selectedDir = QDir("C://");
    void setComments(QHash<QString, MultiFileComment*>*commentMap);
    QHash<QString, MultiFileComment*> *m_Comments;
};

#endif // EKSPORT_H
