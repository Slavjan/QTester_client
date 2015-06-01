#pragma once
#ifndef PROFESSTION_H
#define PROFESSTION_H

#include <QString>
#include <QVector>
#include "lesson.h"
#include "sqlitemgr.h"

//QMap<QVector<QString>, QVector<QString>> lessons_themes_ids;

class Professtion
{
    QString _id;
    QString _name;
    QString _title;
    QVector<Lesson> _lessons;

    Lesson selectLesson( const QString &lessonId,
                         const SQLMgr &sqlManager,
                         const QVector<QString> &themeIds,
                         const qint64 questionsCount,
                         const int answersCount )const;
    
public:
    Professtion();
    Professtion( const QString &name );

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void pushLesson(const Lesson &lesson);

    QString getId()const;
    QString getName()const;
    QString getTitle()const;
    QVector<Lesson>  getLessons()const;

    void selectLessonsFromDatabase( const SQLMgr &sqlManager,
                                    const QMap<QString, QVector<QString>> &lessons_themes_ids,
                                    const int questionsCount,
                                    const int answersCount );
};


namespace Table
{
    namespace Professtion
    {
        const QString TABLE_NAME = "Professtions";

        namespace Fields
        {
            const QString PROFESSTION_ID = "professtion_id";
            const QString NAME = "name";
            const QString TATLE = "titel";
        }
    }
}
#endif