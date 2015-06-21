#include "tilelayout.h"

    
TileLayout::~TileLayout()
{
    QLayoutItem *item;
    while ( ( item = takeAt(0) ) )
        delete item;
}

void TileLayout::addItem(QLayoutItem *item)
{
    iList.append(item);
}

QSize TileLayout::sizeHint() const
{
    QSize size( 0, 0 );
    int count = iList.count();
    if( count > 0 )
        size = QSize( 100, 70 );
    for (int i = 0; i < count; ++i) {
        QLayoutItem *item = iList.at( i );
        size = size.expandedTo( item->sizeHint() );
    }

    return size + count * QSize( spacing(), spacing() );
}

QSize TileLayout::minimumSize() const
{
    QSize size(0,0);
    int count = iList.count();
    for ( int i = 0; i < count; ++i ) {
        QLayoutItem *item = iList.at( i );
        size = size.expandedTo( item->minimumSize() );
    }
    return size + count * QSize( spacing() , spacing() );
}

int TileLayout::count() const
{
    return iList.size();
}

QLayoutItem *TileLayout::itemAt(int index) const
{
    return iList.value(index);
}

QLayoutItem *TileLayout::takeAt(int index)
{
    return ( index >= 0 && index < iList.size() )
            ? iList.takeAt( index )
            : 0;
}

void TileLayout::setGeometry(const QRect &rect)
{
    const int MAX_COLUMN = 6;
    QLayout::setGeometry( rect );

    if( iList.size() == 0 )
        return;

//    int w = rect.width()  - (list.count() - 1) * spacing();
//    int h = rect.height() - (list.count() - 1) * spacing();

    int count = iList.count();

    int row    = 0;
    int column = 0;


    int widthOneItem = rect.width() / MAX_COLUMN;

    for (int i = 0; i < count; ++i) {
        if( column >= MAX_COLUMN ){
            row++;
            column = 0;
        }

        QLayoutItem *item = iList.at( i );

//        QSize sh = item->sizeHint();
//        int   w  = sh.width();

        int x1 = column * widthOneItem;
        int y1 = row    * widthOneItem;

        column++;
        QRect geometry( x1, y1, x1+widthOneItem, y1+widthOneItem );
        item->setGeometry( geometry );
    }
}
