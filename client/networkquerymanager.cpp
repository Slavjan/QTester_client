#include "networkquerymanager.h"

NetworkQueryManager::NetworkQueryManager( const QString &host, const int port )
    : _client( new TcpClient(host, port) )
{
    
}


NetworkQueryManager::~NetworkQueryManager()
{
    delete _client;
}

void NetworkQueryManager::connectionOpen()
{
    _client->connectToServer( "127.0.0.1", 3434 );
    qDebug() << "[NetworkQueryManager:: Try connectionOpen]";
}

//void NetworkQueryManager::dataRecieved( QString str)
//{
//    _client->dataRecieved( str );
//
//    statusMessage( "[NetworkQueryManager::dataRecieved]" + str );
//}

void NetworkQueryManager::authorisation(const QString &login, const QString &password)
{
    QUrl url("/auth");
    QUrlQuery urlQuery(url);

    urlQuery.addQueryItem( "login", login );
    urlQuery.addQueryItem( "password", password );

    url.setQuery(urlQuery);
    _client->sendToServer( url.toString() );
}

void NetworkQueryManager::statusMessage( const QString &msg )
{          
  qDebug() << "client [NetworkQueryManager::statusMessage] "<< msg;
}

void NetworkQueryManager::sendPullRequestProfList()
{
  QUrl url("/auth");
  QUrlQuery urlQuery(url);

  urlQuery.addQueryItem( "login", login );
  urlQuery.addQueryItem( "password", password );

  url.setQuery(urlQuery);
  _client->sendToServer( url.toString() );
}


TcpClient* NetworkQueryManager::getClient()
{
    return _client;
}
