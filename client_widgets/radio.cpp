#include "radio.h"

#include <QVariant>

Radio::Radio()
{

}

Radio::~Radio()
{

}

void Radio::ansSelected(bool clicked)
{
    int questionNumber = property("qNum").toInt();
    int answerNumber = property("ansNum").toInt();

    emit ansSelected( questionNumber, answerNumber );
}

