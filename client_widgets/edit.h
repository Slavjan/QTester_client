#ifndef EDIT_H
#define EDIT_H

#include <QLineEdit>
#include <QString>

namespace SelectedNums{
    namespace Edit {
        const char qNum[] = "qNum";
        const char ansNum[] = "ansNum";
    }
}

class Edit : public QLineEdit                    
{
    Q_OBJECT
public:
    Edit(QString text, int qNum, QWidget *parent = 0);

private slots:
    void ansEntered(const QString &text);
    void textChanged(const QString &text);
signals:
    void ansSignalEntered(int qNum, QString ansText);
};

#endif // EDIT_H
