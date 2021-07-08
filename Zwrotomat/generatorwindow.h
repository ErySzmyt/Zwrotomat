#ifndef GENERATORWINDOW_H
#define GENERATORWINDOW_H

#include <QMainWindow>

namespace Ui {
class GeneratorWindow;
}

class GeneratorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneratorWindow(QWidget *parent = nullptr);
    ~GeneratorWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GeneratorWindow *ui;
};

#endif // GENERATORWINDOW_H
