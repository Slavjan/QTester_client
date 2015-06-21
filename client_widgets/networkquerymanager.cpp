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
    QUrl url(reqLists::auth);
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
  QUrl url(reqLists::get + reqLists::profList);
  QUrlQuery urlQuery(url);
  url.setQuery( urlQuery );
  _client->sendToServer( url.toString() );
}

void NetworkQueryManager::sendPullRequestLessonsList( const QString &profId )           
{
    QUrl url( reqLists::get + reqLists::lessonsList );
    QUrlQuery urlQuery( url );

    urlQuery.addQueryItem( "id", profId );

    url.setQuery( urlQuery );
    _client->sendToServer( url.toString() );
}
void NetworkQueryManager::sendPullRequestThemesList( const QString &lessonId ) 
{
   QUrl url( reqLists::get + reqLists::themesList );
    QUrlQuery urlQuery( url );

    urlQuery.addQueryItem( "id", lessonId );

    url.setQuery( urlQuery );
    _client->sendToServer( url.toString() );
}
void NetworkQueryManager::sendPullRequestQuestions( const QString &themeId, 
                                                    qint64 questionsCount, 
                                                    qint64 answersCount ) 
{
    QUrl url( reqLists::get + reqLists::questions );
    QUrlQuery urlQuery( url );

    urlQuery.addQueryItem( "id", themeId );
    urlQuery.addQueryItem( "questionsCount", QString::number(questionsCount) );
    urlQuery.addQueryItem( "answersCount", QString::number( answersCount ) );

    url.setQuery( urlQuery );
    _client->sendToServer( url.toString() );
}

// sendPullRequest for Trees items

TcpClient* NetworkQueryManager::getClient()
{
    return _client;
}
