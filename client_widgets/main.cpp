#include "rootwindow.h"
#include "apitestwindow.h"
#include <QApplication>
#include <QTime>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    srand( QDateTime::currentMSecsSinceEpoch() );

    QTranslator *translator = new QTranslator;

    if( ! translator->load("://QTester_ru.qm") ){
        qDebug() << "Error loading language" ;
    }


    ApiTestWindow w;
//    RootWindow w;
    w.show();

    return a.exec();
}
