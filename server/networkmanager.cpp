#include "networkmanager.h"


void NetworkManager::connectSlots()
{
    connect( _server, SIGNAL( dataRecieved(QString, QTcpSocket*) ),
             this, SLOT( inputQuery( QString, QTcpSocket* ) )
             );
}

NetworkManager::NetworkManager( SQLMgr &sqlMgr)
{
    _sqlMgr = &sqlMgr;  
    
    _server = new TcpServer( 3434 );
    connectSlots();
}


NetworkManager::~NetworkManager()
{
}

void NetworkManager::authorisation( const QString &login, const QString &password )
{
    bool ok;
    ok = _sqlMgr->auth( login, password );

    if( ok )
    {
        UserControl::instance().pushUser( User( login ) );
        //чувак всё ок
        //_server->sendToClient( socket, "[code:200, response: {\"Welcome\":true}]" );
    }
}

void NetworkManager::inputQuery(QString request, QTcpSocket* client )
{
    qDebug() << "NetworkManager::inputQuery :";
    qDebug() << "Request: " << request;
    
    QString outputData = RequestsManager::request( *_sqlMgr, request );
    qDebug() << outputData;
    _server->sendToClient( client, outputData );
}