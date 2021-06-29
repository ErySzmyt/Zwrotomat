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

protected:
    void mouseReleaseEvent ( QMouseEvent * event ) override;

signals:
    void sendRemoveItem(const QString &text);
    void sendCommentClicked(const QString &text);
    void sendPositiveCheckChanged(const QString &text, const bool &isPositive);

private slots:
    void on_removeButton_clicked();

    void on_wskaznikPozytyw_clicked();

private:
    Ui::ItemDisplay *ui;
};

#endif // ITEMDISPLAY_H
