#include "requestsmanager.h"


void RequestsManager::request( const SQLMgr &db, const QUrl &url )
{
    QString request = url.path();
    QUrlQuery query(url);
    if( request == "/auth" )
    {
        autorisation( db, query );
    }
    else if( request == "/getProffessionsList" )
    {

    }
    
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