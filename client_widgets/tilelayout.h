#ifndef TILELAYOUT_H
#define TILELAYOUT_H

#include <QLayout>
#include <QLayoutItem>
#include <QList>

class TileLayout : public QLayout
{
private:
    QList<QLayoutItem*> iList;
public:
    TileLayout(QWidget *parent = 0) : QLayout(parent) {}
    ~TileLayout();

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem* itemAt(int index) const;
    QLayoutItem* takeAt(int index);
    void setGeometry(const QRect &rect);
};

#endif // TILELAYOUT_H
