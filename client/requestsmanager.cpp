#include "requestsmanager.h"


void RequestsManager::request( const SQLMgr &db, const QUrl &url )
{
    QString request = url.path();
    QUrlQuery query(url);

    if( request == "/auth" )
    {
        autorisation( db, query );
    }
    else report( db, request, query );
}

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

void RequestsManager::report( const SQLMgr &db, const QString &request, const QUrlQuery &query )
{
    IdTitleMap  List;
    QJsonObject obj;
    if( request.startsWith("/get") )
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
}
