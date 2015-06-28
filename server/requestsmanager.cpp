#include "requestsmanager.h"

namespace DefaultValues {
    const QString API_VERSION = "1.0";
}

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

QJsonDocument RequestsManager::request(const QUrl &url, const SQLMgr &db)
{
    // d3i0

    QString request = url.path();
    QUrlQuery query( url );

    QString apiVersion = query.queryItemValue( ApiRequests::Params::API_VERSION );
    if( apiVersion.isEmpty() )
        apiVersion = DefaultValues::API_VERSION;

    Api *api = ApiFactory::createApi( apiVersion );

    int code = 0;

    QJsonObject response = api->responseRequest( url, db, code );

    delete api;

    return report(code, request, response);
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

        User user( login, password, db );

        QString token = userControl.pushUser( user );

        QJsonObject response{
            { "token",        token },
            { "fullUserName", user.getFullName() },
            { "userGroup",    user.getGroup() }
        };
        QJsonObject obj{
            { "code", Codes::auth },
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

QJsonObject RequestsManager::qCountToJsonObj(qint64 maxQCount)
{
  QJsonObject response{
    {reqLists::maxQCount, QString::number(maxQCount)}
  };
  QJsonObject QCount{
    {"code", QString::number(Codes::QuestionsCount) },
    {"response", response}
  };

  return QCount;
}

QJsonObject RequestsManager::report( const SQLMgr &db, const QString &request, const QUrlQuery &query )
{
    IdTitleMap  List;
    QJsonObject obj;
    if( request.startsWith( "/get" ) )          // /get...
    {
       QString listName = request;
       listName.remove( 0, 4 );

       qDebug() << "[RequestsManager::report]> listName" << listName;
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
       {  // GET /getQuestions?Id= %id &questionsCount= %qCount &answersCount= %aCount

           if(query.hasQueryItem(reqLists::maxQCount))
           {
//               QString themeId = query.queryItemValue()
//               QSqlQuery sqLquery = db.select(Table::Question::TABLE_NAME, ("COUNT(*) AS rCount"),
//                                              SqlWhere(Table::Question::Field::THEME_ID + " = '" +  + "'"));
//              qint64 maxQCount = sq
//              QJsonObject QCount = qCountToJsonObj(maxQCount);
//              obj = QCount;
           }
           else
           {
             Lesson lesson;
             QStringList themeId( query.queryItemValue( "id" ) );// %id
             int qcount = query.queryItemValue( "questionsCount" ).toInt();// %qCount

             lesson.selectThemesFromDataBase( db,
                                              themeId,
                                              qcount,
                                              5 ); //%aCount
             Theme theme = lesson.getThemes().first();
             obj = JsonFormat::themeToJsonObj( theme );
           }
       }
    }
    //TODO TcpSocket::report( obj );
    qDebug() << "[RequestsManager::report] > obj >" << obj;

    return obj;
}

QJsonDocument RequestsManager::report(const int code, const QString &request, const QJsonObject &response)
{
    // d3i0

    QJsonObject report{
      {"code", code },
      {"request", request},
      {"response", response}
    };

    QJsonDocument doc;
    doc.setObject( report );

    return doc;
}
