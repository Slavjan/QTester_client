#ifndef RADIO_H
#define RADIO_H
#include <QRadioButton>


typedef QMap<int, int> selectedAnswersRadioMap;

namespace SelectedNums{
    namespace Radio {
        const char qNum[] = "qNum";
        const char ansNum[] = "ansNum";
    }
}

class Radio : public QRadioButton
{
    Q_OBJECT
private:


public:
    Radio(QString text, QWidget *parent = 0);
    Radio(QString text,
          int questionId,
          int answerId,
          QWidget *parent = 0);
private slots:
    void ansSelected(bool clicked);

signals:
    void ansSelected( int qNum, int ansNum );
};

#endif // RADIO_H
