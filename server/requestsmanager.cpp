#include "requestsmanager.h"

QString RequestsManager::request( const SQLMgr &db, const QUrl &url )
{
    QString request = url.path();
    QUrlQuery query( url );

    QJsonObject obj;

    qDebug() << "[RequestsManager::request]>" << request << "/url > " << url;
    if( request == "/auth" )
    {
        obj = autorisation( db, query );
    }
    else obj = report( db, request, query );

    QJsonDocument doc;
    doc.setObject( obj );
    return doc.toJson();
}

QJsonObject RequestsManager::autorisation( const SQLMgr &db, const QUrlQuery &urlQuery )
{
    UserControl userControl = UserControl::instance();
    QString login = urlQuery.queryItemValue( "login" ),
        password = urlQuery.queryItemValue( "password" );

    qDebug() << "login :" << login << "\npassword :" << password;
    if( db.auth( login, password ) )
    {
        qDebug() << "/auth success";
        /*db.select( "USERS", { "name", } );*/

        User user( login );
        SqlWhere _where(Table::Users::Fields::LOGIN + " = '" + login + "'");
                 _where.AND(Table::Users::Fields::PASSWORD + " = '" + password + "'");
                 QStringList _fields( "firstName ||' '|| secondName AS fullName" );
        QString tn = Table::Users::TABLE_NAME;        
        QSqlQuery query = db.select(tn, _fields, _where);
        query.first();
        QString fullUserName = query.value( "fullName" ).toString();
        QString token = userControl.pushUser( user );

        QJsonObject response{
            { "token", token },
            { "fullUserName", fullUserName }
        };
        QJsonObject obj{
            { "code", 200 },
            { "response", response }
        }; qDebug() << "/auth obj :"<< obj;
        return obj;
    }
    QJsonObject failed{
        { "autirisation", "failed" }
    };
    qDebug() << "/auth :" << failed;
    return failed;
}

QJsonObject RequestsManager::report( const SQLMgr &db, const QString &request, const QUrlQuery &query )
{
    IdTitleMap  List;
    QJsonObject obj;
    if( request.startsWith( "/get" ) )          // /get...
    {
       QString listName = request.right( 4 );


       if(listName.startsWith( reqLists::lessonsList, Qt::CaseInsensitive ))  // if  /...LessonsList ? id=%lId  
       {
         List = Lesson::getLessonsList( db, query.queryItemValue( "id" ) );
         obj = JsonFormat::lessonsListToJsonObj( List );
       }   
       else if( listName.startsWith( reqLists::profList, Qt::CaseInsensitive ) )  // if  /...ProfList  ? id=%lId
       {
         List = Profession::getProfList( db );
         obj = JsonFormat::profListToJsonObj( List );
       }
       else if(listName.startsWith( reqLists::themesList, Qt::CaseInsensitive ))  // if  /...ThemesList ? id=%tId
       {
         List = Theme::getThemeList( db, query.queryItemValue( "id" ) );  
         obj = JsonFormat::themesListToJsonObj( List );          
       }
       else if( listName.startsWith( reqLists::questions, Qt::CaseInsensitive ) ) // if   /... Questions
       {  // GET /getQuestions?themeId= %id &questionsCount= %qCount &answersCount= %aCount
           Lesson lesson;
           lesson.selectThemesFromDataBase( db,
                                            QStringList( query.queryItemValue( "themeId" ) ),// %id
                                            query.queryItemValue( "questionsCount" ).toInt(),// %qCount
                                            5 ); //%aCount
           Theme theme = lesson.getThemes().first();
           obj = JsonFormat::themeToJsonObj( theme );
       }
       else IdTitleMap();
    }
    //TODO TcpSocket::report( obj );
    return obj;
}
