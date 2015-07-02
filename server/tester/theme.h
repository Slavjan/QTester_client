#pragma once
#ifndef THEM_H
#define THEM_H

#include <QString>
#include <QVector>
#include "question.h"
#include "db/sqlmgr.h"

typedef QMap<QString/*id*/, QString/*title*/> IdTitleMap;

class Theme
{
private:
    QString _id;
    QString _name;
    QString _title;
    int 	_difficulty = 0;
    QString _lessonId;
    QVector <Question> _questions;

    Question selectQuestion( const QSqlQuery &query ) const;

    QVector<Answer> selectAnswers( const SQLMgr  &sqlManager,
                                   const int      answersCount,
                                   const QString &questionId ) const;
public:
    Theme()
    {
    };
    Theme( const QString &Name );

    QString getId()const;
    QString getName()const;
    QString getTitle()const;
    int getDifficulty()const;
    QString getLessonId()const;
    QVector <Question> getQuestions() const;

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void setDifficulty( const int &difficulty );
    void setLessonId( const QString &lessonId );
    void pushQuestion( const Question &question );
    void pushQuestion( const QString &text,
                       const QString &type );
    void pushQuestion( const QString &text,
                       const QString &type,
                       const QVector <Answer> &answers );

    bool selectFromDatabase( const SQLMgr &sqlManager,
                             const qint64 questionsCount,
                             const int answersCount );
    static IdTitleMap getThemeList( const SQLMgr &sqlManager, const QString &lessonId );
    void print()const;
};

namespace Tables
{
    namespace Theme
    {
        const QString TABLE_NAME = "Themes";

        namespace Fields
        {
            const QString THEME_ID = "theme_id";
            const QString NAME = "name";
            const QString TITLE = "title";
            const QString DIFFICULTY = "difficulty";
            const QString LESSON_ID = "lesson_id";
        }
    }
}
#endif

