#ifndef GENERATORWINDOW_H
#define GENERATORWINDOW_H

#include "multifilecomment.h"
#include <QDir>
#include <QMainWindow>

namespace Ui {
class GeneratorWindow;
}

class GeneratorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneratorWindow(QWidget *parent = nullptr, QHash<QString, MultiFileComment*> *m_Comments = nullptr);
    ~GeneratorWindow();

private slots:
    void on_generateButton_clicked();
    void on_subjectTextEdit_textChanged();
    void on_topicTextEdit_textChanged();
    void on_checkerTextEdit_textChanged();
    void on_outputDirPicker_clicked();

private:
    Ui::GeneratorWindow *ui;

    static inline QString s_last_subject = "";
    static inline QString s_last_topic = "";
    static inline QString s_last_checker = "";
    static inline QDir s_last_selectedDir = QDir("C:/");
    QHash<QString, MultiFileComment*> *m_Comments;

};

#endif // GENERATORWINDOW_H
