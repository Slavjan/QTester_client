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

namespace ReturnCodes {
    enum ReturnCodes{
        success = 0,
        invalidPort
    };
}

int main( int argc, char *argv[] )
{
    setlocale( LC_ALL, "Russian" );
    QCoreApplication a( argc, argv );
    CommandLineArgs args = parseCommandLineArgs(argc, argv);


    SQLMgr *db = SQLiteMgr::instance();


    bool toIntSuccess = false;
    int port = args.port.toInt( &toIntSuccess );
    if( ! toIntSuccess ){
        qCritical() << "Invalid Port";
        return ReturnCodes::invalidPort;
    }

    NetworkManager netMan( *db, port );

    return a.exec();
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
