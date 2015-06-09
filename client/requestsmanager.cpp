#include "requestsmanager.h"


QString RequestsManager::request( const SQLMgr &db, const QUrl &url )
{
    QString request = url.path();
    QUrlQuery query(url);

    QJsonObject obj;

    if( request == "/auth" )
    {
       obj = autorisation( db, query );
    }
    else obj = report( db, request, query );

    QJsonDocument doc;
    doc.setObject( obj );
    return doc.toJson();
}

QJsonObject RequestsManager::autorisation(const SQLMgr &db, const QUrlQuery &urlQuery )
{
    UserControl userControl = UserControl::instance();
    QString login     = urlQuery.queryItemValue( "login" ),
            password  = urlQuery.queryItemValue( "password" );

    if( db.auth( login, password ) )
    {
        /*db.select( "USERS", { "name", } );*/

        User user( login );
        QString token = userControl.pushUser( user );
        
        QJsonObject response{
            { "token", token }
        };
        QJsonObject obj{
            { "code", 200 },
            { "response", response }
        };
        return obj;
    }
    QJsonObject failed{
        {"autirisation", "failed"}
    };
    return failed;
}

QJsonObject RequestsManager::report( const SQLMgr &db, const QString &request, const QUrlQuery &query )
{
    IdTitleMap  List;
    QJsonObject obj;
    if( request.startsWith("/get") )          // /getProfessionsLIst
    {
        QString listName = request.right( 4 );
        
        List = listName.startsWith( "lesson", Qt::CaseInsensitive ) ?   // наверное это ужасно читается, но раотает
               Lesson::getLessonsList( db, query.queryItemValue( "id" ) ) :
               
               listName.startsWith( "prof", Qt::CaseInsensitive ) ?
               Profession::getProfList( db ) :
               
               listName.startsWith( "theme", Qt::CaseInsensitive ) ?
               Theme::getThemeList( db, query.queryItemValue( "id" ) ): 
               IdTitleMap();

        obj = JsonFormat::lessonsListToJsonObj( List );
    }
    //TODO TcpSocket::report( obj );
    return obj;
}