#ifndef API_1_0_H
#define API_1_0_H

#include "api.h"

#include "users/usercontrol.h"
#include "profession.h"
#include "jsonformat.h"

namespace ApiRequests {
    const QString AUTHORISATION = "/auth";
    const QString GET_PROFESSIONS_LIST = "/get_professions_list";
    const QString GET_LESSONS_LIST = "/get_lessons_list";
    const QString GET_THEMES_LIST = "/get_themes_list";

    namespace Params {
        const QString LOGIN    = "login";
        const QString PASSWORD = "password";


        const QString PROFESSION_ID = "profession_id";
        const QString LESSON_ID     = "lesson_id";
        const QString THEME_ID      = "theme_id";
    }
}

namespace ResponseParams{
    const QString TOKEN          = "token";
    const QString FULL_USER_NAME = "full_user_name";
    const QString USER_GROUP     = "user_group";

    const QString PROFESSIONS_LIST = "professions_list";
    const QString LESSONS_LIST     = "lessons_list";
    const QString THEMES_LIST      = "themes_list";


    const QString ID = "id";
    const QString TITLE = "title";
}

class Api_1_0 : public Api
{
    QJsonObject invalidRequest(int &code) const;

    QJsonObject authorisation(const QUrlQuery &query, const SQLMgr &db, int &code) const;

    QJsonObject getProfessionsList(const QUrlQuery &query, const SQLMgr &db, int &code) const;
    QJsonObject getLessonsList(const QUrlQuery &query, const SQLMgr &db, int &code) const;
    QJsonObject getThemesList(const QUrlQuery &query, const SQLMgr &db, int &code) const;
public:
    QJsonObject responseRequest(const QUrl &url, const SQLMgr &db, int &code) override;
};

#endif // API_1_0_H
