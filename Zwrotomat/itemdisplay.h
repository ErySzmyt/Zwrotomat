#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H

#include <QWidget>

namespace Ui {
    class ItemDisplay;
}

class ItemDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ItemDisplay(QWidget *parent = nullptr);
    ~ItemDisplay();

    void setText(const QString &text);
    QString getText();


signals:
    void sendRemoveItem(const QString &text);
    void sendCommentClicked(const QString &text);

private slots:
    void on_removeButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::ItemDisplay *ui;
};

#endif // ITEMDISPLAY_H
