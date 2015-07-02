#include <QCoreApplication>

#include "tester/profession.h"
#include "jsonformat.h"
#include "network/networkmanager.h"
#include "db/sqlitemgr.h"

#include "../common/ParametrParser/parametrparser.h"

#include <QCryptographicHash>

struct CommandLineArgs{
    QString port;
};
CommandLineArgs parseCommandLineArgs( int argc, char* argv[] ){
    CommandLineArgs args;

    ParametrParser parser(argc, argv);

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
//    qDebug() << QCryptographicHash::hash( "QTester", QCryptographicHash::Md5 ).toHex();

    setlocale( LC_ALL, "Russian" );
    QCoreApplication a( argc, argv );
    CommandLineArgs args = parseCommandLineArgs(argc, argv);

    a.setApplicationName("QTester_server");
    a.setApplicationVersion("0.1.2 PreAlpha");
    a.setOrganizationName("Slavjan");

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
