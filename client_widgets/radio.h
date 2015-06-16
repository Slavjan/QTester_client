#ifndef RADIO_H
#define RADIO_H
#include <QRadioButton>


typedef QMap<int, int> selectedAnswersMap;

namespace selectedNums
{
    const char qNum[] = "qNum";
    const char ansNum[] = "ansNum";
}

class Radio : public QRadioButton
{
    Q_OBJECT
private:


public:
    Radio();
    ~Radio();
private slots:
    void ansSelected(bool clicked);

signals:
    void ansSelected( int qNum, int ansNum );
};

#endif // RADIO_H
