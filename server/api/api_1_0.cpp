#include "api_1_0.h"

const QString API_VERSION = "1.0";

QJsonObject Api_1_0::invalidRequest(int &code) const
{
    code = ReplyCodes::InvalidRequest;
    return QJsonObject();
}

QJsonObject Api_1_0::authorisation(const QUrlQuery &query, const SQLMgr &db, int &code) const
{
    /// /auth?login=11po1_1&password=123456&api_version=1.0
    QString login    = query.queryItemValue( ApiRequests::Params::LOGIN );
    QString password = query.queryItemValue( ApiRequests::Params::PASSWORD );

    if ( login.isEmpty() ){
        code = ReplyCodes::LostRequiredParameter;
        return QJsonObject();
    }
    if ( ! db.auth( login, password ) ){
        code = ReplyCodes::AuthentificationFailed;
        return QJsonObject();
    }

    code = ReplyCodes::OK;

    User user(login, password, db, API_VERSION);

    UserControl userControl = UserControl::instance();
    QString token = userControl.pushUser( user );


    QJsonObject response{
        { ResponseParams::TOKEN          , token },
        { ResponseParams::FULL_USER_NAME , user.getFullName() },
        { ResponseParams::USER_GROUP     , user.getGroup() }
    };

    return response;
}

QJsonObject Api_1_0::getProfessionsList(const QUrlQuery &/*query*/, const SQLMgr &db, int &code) const
{
    /// /get_professions_list
    code = ReplyCodes::OK;

    IdTitleMap list = Profession::getProfList( db );
    return JsonFormat::profListToJsonObj( list );
}

QJsonObject Api_1_0::getLessonsList(const QUrlQuery &query, const SQLMgr &db, int &code) const
{
    /// /get_lessons_list?profession_id=0
    code = ReplyCodes::OK;
    QString profession_id = query.queryItemValue( ApiRequests::Params::PROFESSION_ID );
    if( profession_id.isEmpty() ){
        code = ReplyCodes::LostRequiredParameter;
        return QJsonObject();
    }

    IdTitleMap list = Lesson::getLessonsList( db, profession_id );
    return JsonFormat::lessonsListToJsonObj( list );
}

QJsonObject Api_1_0::getThemesList(const QUrlQuery &query, const SQLMgr &db, int &code) const
{
    /// /get_themes_list?lesson_id=0
    code = ReplyCodes::OK;
    QString lesson_id = query.queryItemValue( ApiRequests::Params::LESSON_ID );

    if( lesson_id.isEmpty() ){
        code = ReplyCodes::LostRequiredParameter;
        return QJsonObject();
    }

    IdTitleMap list = Theme::getThemeList( db, lesson_id );
    return JsonFormat::lessonsListToJsonObj( list );
}

QJsonObject Api_1_0::responseRequest(const QUrl &url, const SQLMgr &db, int &code)
{
    QString request = url.path();
    QUrlQuery query( url );

    if( request == ApiRequests::AUTHORISATION )
        return authorisation(query, db, code);

    if( request == ApiRequests::GET_PROFESSIONS_LIST )
        return getProfessionsList(query, db, code);

    if( request == ApiRequests::GET_LESSONS_LIST )
        return getLessonsList(query, db, code);

    if( request == ApiRequests::GET_THEMES_LIST )
        return getThemesList(query, db, code);

    return invalidRequest(code);
}

