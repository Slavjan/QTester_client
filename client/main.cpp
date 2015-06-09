#include <QApplication>
//#include <QQmlApplicationEngine>
#include <qcoreapplication.h>
#include "tcpclient.h"
#include "networkquerymanager.h"
#include <QDir>

#include <QMainwindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
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

    QMainWindow w;
    QPushButton *myBtnConnect = new QPushButton( "&Connect" );
    QPushButton *myBtnAuth = new QPushButton( "&Autorisation" );
    QLabel statusMessage;

    

    myBtnConnect->show();
    myBtnAuth->show();

    NetworkQueryManager *mngr = new NetworkQueryManager( "127.0.0.1", 3434 );
    TcpClient *client = mngr->getClient();
    QObject::connect( myBtnConnect, SIGNAL( clicked() ), mngr, SLOT( connectionOpen() ) );
    
    QObject::connect( myBtnConnect, SIGNAL( clicked() ),
                      mngr, SLOT( authorusation() ) ); 

    QObject::connect( client , SIGNAL( dataRecieved( QString ) ), 
                      myBtnAuth, SLOT( setText() ) );




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
