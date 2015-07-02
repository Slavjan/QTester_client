#pragma once

#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "tester/profession.h"

namespace Codes{
    enum requests{auth = 200, Prof, Lessons, Themes, Questions, QuestionsCount };
}

class JsonFormat
{
private:
    static QJsonArray  mapListTojArray( const IdTitleMap &map );
    static QJsonObject mapListItemtojObject( const QVariant &key, const QVariant &value );


public:
    static QJsonObject professionToJsonObj( const Profession &prof );
    static QJsonObject lessonToJsonObj( const Lesson &lesson );
    static QJsonObject themeToJsonObj( const Theme &theme );
    static QJsonObject questionToJsonObj( const Question &question );
    static QJsonObject answerToJsonObj( const Answer &answer );

    static QJsonObject profListToJsonObj( const IdTitleMap &list );
    static QJsonObject lessonsListToJsonObj( const IdTitleMap &list );
    static QJsonObject themesListToJsonObj( const IdTitleMap &list );

    static QJsonObject idTitleMapToJsonObj(const IdTitleMap &list, int code, const QString &listName );
};

namespace reqLists
{
    const QString auth = "/auth";
    const QString get = "/get";
    const QString profList = "profList";
    const QString lessonsList = "lessonsList";
    const QString themesList = "themesList";
    const QString questions = "questions";
    const QString maxQCount = "maxQCount";
}
