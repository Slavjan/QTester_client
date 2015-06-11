#include <QApplication>
#include <qcoreapplication.h>
#include <QDir>
#include <QQmlApplicationEngine>

#include <QMainwindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QQmlContext>
#include "networkquerymanager.h"
#include "jsonparser.h"
#include "uisetter.h"

QString getUserLogin()
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

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    setlocale( LC_ALL, "Russian" );
    /*   QMainWindow w;               */
//    QWidget *wgt = new QWidget;
//    QVBoxLayout *lay = new QVBoxLayout( wgt );
//    QPushButton *myBtnConnect = new QPushButton( "&Connect", wgt );
//    QPushButton *myBtnAuth = new QPushButton( "&Autorisation", wgt );
//    QLabel *lbl = new QLabel( wgt );
//    wgt->setLayout( lay );
//    lay->addWidget( lbl );
//    lay->addWidget( myBtnConnect );
//    lay->addWidget( myBtnAuth );

//    wgt->show();

    NetworkQueryManager *mngr = new NetworkQueryManager( "127.0.0.1", 3434 );
    TcpClient *client = mngr->getClient();

    JsonParser jParser;
//    QObject::connect( myBtnConnect, SIGNAL( clicked() ),
//                      mngr, SLOT( connectionOpen() ) );

//    QObject::connect( myBtnAuth, SIGNAL( clicked() ),
//                      mngr, SLOT( authorisation(  ) ) );

    QObject::connect( client, &TcpClient::dataRecieved,
                      &jParser, &JsonParser::responseSlot );


    // app.setApplicationName("client");
    //  app.setApplicationDisplayName("QTester");
    //   app.setApplicationVersion("0.0.0 Pre-Aplha");


    //mngr->authorisation( "d3i0", "12345" );

    QQmlApplicationEngine engine;
    UiSetter ui( engine.rootContext() );
    ui.setLogin( getUserLogin() );

    QObject::connect( &jParser, SIGNAL(authSignalPars(QString)),
                      &ui, SLOT(setFullName(QString)) );
    QObject::connect( &jParser, SIGNAL( takeProf( QString ) ),
                      &ui, SLOT() );
//    engine.rootContext()->setContextProperty("fullName", getUserLogin() );
    engine.rootContext()->setContextProperty( "NetManager", mngr );
    engine.load( QUrl( QStringLiteral( "qrc:/main.qml" ) ) );

    return app.exec();
}
