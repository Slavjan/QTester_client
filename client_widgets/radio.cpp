#include "radio.h"
#include <QVariant>

Radio::Radio(QString text, QWidget *parent)
    :QRadioButton(parent)
{
    setText( text );
}

Radio::Radio(QString text,
             int questionNum,
             int answerNum,
             QWidget *parent)
    :QRadioButton(parent)
{
    setText( text );
    setProperty( SelectedNums::Radio::qNum, questionNum);
    setProperty( SelectedNums::Radio::ansNum, answerNum);
}

void Radio::ansSelected(bool clicked)
{
    int questionNumber = property(SelectedNums::Radio::qNum).toInt();
    int answerNumber = property(SelectedNums::Radio::ansNum).toInt();

    emit ansSelected( questionNumber, answerNumber );
}

