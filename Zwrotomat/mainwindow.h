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

    void dragEnterEvent(QDragEnterEvent *event); //Drag event
    void dropEvent(QDropEvent *event); //Let down the event
private slots:
    void on_treeFileExplorer_clicked(const QModelIndex &index);
    void on_actionZ_Folderu_triggered();
    void on_actionPliki_triggered(); //debug

    void on_textBrowser_cursorPositionChanged();


private:
    void loadSelectedLines();

    Ui::MainWindow *ui;
    QFileSystemModel *fileModel; // model for filed display

    QString selectedFile;
    QDir selectedDir;

    Highlighter *highlighter;
    MultiFileComment *multiFileComment;
    bool fileJustOpen = true;
};
#endif // MAINWINDOW_H
