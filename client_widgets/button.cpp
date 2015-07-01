#include "button.h"

Button::Button(QString text, int id, QWidget *parent)
    : QToolButton(parent)
{
    _id = id;
    setText( text );
    this->setCheckable( true );
    connect( this, SIGNAL(clicked(bool)),
             this, SLOT(selectedSlot(bool)) );
}

void Button::selectedSlot(bool pressed)
{
//    setChecked( pressed );
    if( pressed )
        emit selected(_id);
}
