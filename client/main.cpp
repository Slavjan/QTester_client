#include <QApplication>
//#include <QQmlApplicationEngine>
#include <qcoreapplication.h>
#include "tcpclient.h"
#include "networkquerymanager.h"
#include <QDir>

#include <QHBoxLayout>
#include <QPushButton>
//#include <QQmlContext>

QString getUserName()
{
    //* Variant #1 : simple
    return QDir().home().dirName();
    // */
    /* Variant #2
    QString name;
    name = qgetenv(“USER”); // get the user name in Linux
    if( name.isEmpty() ){
        name = qgetenv(“USERNAME”); // get the name in Windows
    }
    // */
    //* Variant #3
    // google it: http://qt-project.org/forums/viewthread/11951
    // */
}

int main(int argc, char *argv[])
{
    QApplication app( argc, argv );

    QPushButton *myBtn = new QPushButton( "&PushMe" );

    myBtn->show();
    
    NetworkQueryManager *mngr = new NetworkQueryManager( "127.0.0.1", 3434 );// давай копирнем просто из гит хаба твои классы окон

    QObject::connect( myBtn, SIGNAL( clicked() ),
                      mngr, SLOT( authorusation() ) );            


   // app.setApplicationName("client");
  //  app.setApplicationDisplayName("QTester");
 //   app.setApplicationVersion("0.0.0 Pre-Aplha");

    
    //mngr->authorisation( "d3i0", "12345" );

 //   QQmlApplicationEngine engine;
 //   engine.rootContext()->setContextProperty("username", getUserName() );
//    engine.rootContext()->setContextProperty("Database", db );
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    

    return app.exec();
}
