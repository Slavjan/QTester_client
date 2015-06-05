#include "requestsmanager.h"


//void RequestsManager::request( const SQLMgr &db, const QUrl &url )
//{
//    QString request = url.path();
//    QUrlQuery query(url);
//    if( request == "/auth" )
//    {
//        autorisation( db, query );
//    }
//    else if( request == "/getProffessionsList" )
//    {
//        report( db, request);
//    }             
//}

void RequestsManager::autorisation(const SQLMgr &db, const QUrlQuery &urlQuery )
{
    UserControl userControl = UserControl::instance();
    QString login     = urlQuery.queryItemValue( "login" ),
            password  = urlQuery.queryItemValue( "password" );

    if( db.auth( login, password ) )
    {
        userControl.pushUser( User() );
    }
}

void report( const SQLMgr &db, const QString &request )
{
    IdTitleMap profList = Profession::getProfList( db );

    QJsonObject obj = JsonFormat::profListToJsonObj( profList );
    //TODO TcpSocket::report( obj );
}