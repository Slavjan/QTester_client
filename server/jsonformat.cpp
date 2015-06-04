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
        { "themes", jLessons }
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