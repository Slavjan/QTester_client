#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>



class Button : public QToolButton
{
    Q_OBJECT
private:
    int _id;
public:
    Button(QString text, int id, QWidget *parent = 0);

signals:
    void selected(int id);
private slots:
    void selectedSlot(bool);
};

#endif // BUTTON_H
