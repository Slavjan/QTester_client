#include "jsonformat.h"


QJsonObject JsonFormat::professionToJsonObj( const Profession &prof )
{
    QJsonArray jLessons;
    for( auto i = 0; i < prof.getLessons().count(); i++ )
    {
        jLessons.append( lessonToJsonObj( prof.getLessons().at( i ) ) );
    }

    QJsonObject jProfession{
        { "id", prof.getId() },
        { "title", prof.getTitle() },
        { "lessons", jLessons }
    };

    return jProfession;
}

QJsonObject JsonFormat::lessonToJsonObj( const Lesson &lesson )
{
    QJsonArray jThemes;
    for( auto i = 0; i < lesson.getThemes().count(); i++ )
    {
        jThemes.append( themeToJsonObj( lesson.getThemes().at( i ) ) );
    }

    QJsonObject jLesson{
        { "id", lesson.getId() },
        { "title", lesson.getTitle() },
        { "themes", jThemes }
    };

    return jLesson;
}

QJsonObject JsonFormat::themeToJsonObj( const Theme &theme )
{
    QJsonArray jQuestions;
    for( auto i = 0; i < theme.getQuestions().count(); i++ )
    {
        jQuestions.append( questionToJsonObj( theme.getQuestions().at( i ) ) );
    }

    QJsonObject jTheme{
        { "id", theme.getId() },
        { "title", theme.getTitle() },
        { "questions", jQuestions }
    };

    return jTheme;
}

QJsonObject JsonFormat::questionToJsonObj( const Question &question )
{
    QJsonArray jAnswers;
    for( auto i = 0; i < question.getAnswers().count(); i++ )
    {
        jAnswers.append( answerToJsonObj( question.getAnswers().at( i ) ) );
    }

    QJsonObject jQuestion{
        { "id", question.getId() },
        { "text", question.getText() }, 
        { "type", question.getType() },
        { "answers", jAnswers }
    };

    return jQuestion;
}

QJsonObject JsonFormat::answerToJsonObj( const Answer &answer )
{
    QJsonObject jAnswer{
        { "id", answer.getId() },
        { "text", answer.getValue() },
        { "valid", answer.isValid() }
    };

    return jAnswer;
}


QJsonObject JsonFormat::profListToJsonObj( const IdTitleMap &list )
{
    return idTitleMapToJsonObj( list, Codes::Prof, reqLists::profList );
}

QJsonObject JsonFormat::lessonsListToJsonObj( const IdTitleMap &list )
{
    return idTitleMapToJsonObj( list, Codes::Lessons, reqLists::lessonsList );
}

QJsonObject JsonFormat::themesListToJsonObj( const IdTitleMap &list )
{
    return idTitleMapToJsonObj( list, Codes::Themes, reqLists::themesList );
}

QJsonObject JsonFormat::idTitleMapToJsonObj( const IdTitleMap &list, int code, const QString &listName )
{
    QJsonArray jArray = mapListTojArray( list );
    QJsonObject response{
        { listName, jArray }
    };
    QJsonObject jList{
        { "code", code },
        { "response", response }
    };

    return jList;
}

QJsonArray JsonFormat::mapListTojArray( const IdTitleMap &map )
{
    QJsonArray jArray;
    QMapIterator<QString, QString> i( map );

    while( i.hasNext() )
    {
        i.next();
        jArray.append( mapListItemtojObject( i.key(), i.value() ) );
    }

    return jArray;
}
QJsonObject JsonFormat::mapListItemtojObject( const QVariant &key, const QVariant &value )
{
    QJsonObject obj{
        { "id", key.toInt() },
        { "title", value.toString() }
    };

    return obj;
}
