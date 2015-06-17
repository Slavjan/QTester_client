#include "check.h"
#include <QVariant>

Check::Check(QString text, QWidget *parent)
    :QCheckBox(parent)
{
    setText( text );
}

Check::Check(QString text,
             int questionId,
             int answerId,
             QWidget *parent)
    :QCheckBox(parent)
{
    setText( text );
    setProperty(SelectedNums::Check::qNum, questionId);
    setProperty(SelectedNums::Check::ansNum, answerId);
}

void Check::ansSelected(bool clicked)
{
    int questionNumber = property(SelectedNums::Check::qNum).toInt();
    int answerNumber = property(SelectedNums::Check::ansNum).toInt();

    emit ansSelected( questionNumber, answerNumber );
}

