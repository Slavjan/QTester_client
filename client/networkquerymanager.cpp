#include "networkquerymanager.h"

NetworkQueryManager::NetworkQueryManager( const QString &host, const int port )
    : _client( new TcpClient(host, port) )
{
    
}


NetworkQueryManager::~NetworkQueryManager()
{
    delete _client;
}

void NetworkQueryManager::authorisation( const QString &login, const QString &password )
{
    QUrl url("/auth");
    QUrlQuery urlQuery(url);

    urlQuery.addQueryItem( "login", login );
    urlQuery.addQueryItem( "password", password );

    _client->sendToServer( urlQuery.toString() );
}
