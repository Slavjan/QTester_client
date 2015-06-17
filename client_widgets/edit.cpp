#include "edit.h"
#include <QVariant>

Edit::Edit( QString text,
            int qNum,
            QWidget *parent )
            :QLineEdit( parent )
{
    setText( text );
    setProperty( SelectedNums::Edit::qNum, qNum );
}

void Edit::textChanged( const QString &text )
{
    ansEntered( text );
}

void Edit::ansEntered( const QString &text )
{
    int qNum = property( SelectedNums::Edit::qNum ).toInt();

    emit ansSignalEntered( qNum, text );
}

