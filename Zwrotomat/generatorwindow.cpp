#include "generatorwindow.h"
#include "ui_generatorwindow.h"

GeneratorWindow::GeneratorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GeneratorWindow)
{
    ui->setupUi(this);
}

GeneratorWindow::~GeneratorWindow()
{
    delete ui;
}

void GeneratorWindow::on_pushButton_clicked()
{

}
