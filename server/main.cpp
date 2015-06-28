#include <QCoreApplication>

//#include "sqlitemgr.h"
#include "profession.h"
#include "testgenerator.h"
#include "jsonformat.h"
#include "networkmanager.h"

#include "../common/ParametrParser/parametrparser.h"

#include <QCryptographicHash>

struct CommandLineArgs{
    QString host;
    QString port;
};
CommandLineArgs parseCommandLineArgs( int argc, char* argv[] ){
    CommandLineArgs args;

    ParametrParser parser(argc, argv);

    parser.setOption( "h", "host", [&](std::string arg){
        args.host = QString::fromStdString( arg );
    } );
    parser.setOption( "p", "port", [&](std::string arg){
        args.port = QString::fromStdString( arg );
    } );

    try {
        parser.exec();
    } catch ( ParametrParser::UnknownOption e ) {
        qWarning() << "Unknown option: " << QString::fromStdString( e.optionName );
    }

    return args;
}

int main( int argc, char *argv[] )
{
    setlocale( LC_ALL, "Russian" );
    QCoreApplication a( argc, argv );
    CommandLineArgs args = parseCommandLineArgs(argc, argv);


    SQLMgr *db = SQLiteMgr::instance( args.host, args.port );

    NetworkManager netMan( *db );
    return  a.exec();
}


/////////////////////////
/*
 TODO:
* SocketConnectionManager
* UserControl
* AccessManager
* iApiManager
* Api_1_0

*/
