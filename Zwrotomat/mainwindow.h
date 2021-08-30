#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "highlighter.h"
#include "multifilecomment.h"

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeFileExplorer_clicked(const QModelIndex &index);
    void on_actionZ_Folderu_triggered();
    void on_actionPliki_triggered();

    void on_textBrowser_cursorPositionChanged();
    void on_addingCommentButton_clicked();

    void removeComment(const QString &text);
    void selectComment(const QString &text);

    void changePositivityOfComment(const QString &text, const bool &isChecked);
    void on_commentEdit_textChanged();

    void on_actionGeneruj_triggered();

    void on_actionPusty_triggered();

    void on_actionKomentarze_triggered();

    void on_actionGit_triggered();

    void on_actionEksportuj_2_triggered();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_fileModel; // model for filed display

    QString m_selectedFile;
    QDir m_selectedDir;

    Highlighter *m_highlighter;

    MultiFileComment *m_currentComment;

    QHash<QString, MultiFileComment*> *m_Comments;

    void loadCurrentFile();

};
#endif // MAINWINDOW_H
