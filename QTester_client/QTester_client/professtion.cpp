#include "professtion.h"


Professtion::Professtion()
{
}


Professtion::~Professtion()
{
}

void Professtion::setId( const QString &id )
{
    _id = id;
}
void Professtion::setName( const QString &name )
{
    _name = name;
}
void Professtion::setTitle( const QString &title )
{
    _title = title;
}
void Professtion::pushLesson( const Lesson &lesson )
{
    _lessons.push_back( lesson );
}

QString Professtion::getId()const
{
    return _id;
}
QString Professtion::getName()const
{
    return _name;
}
QString Professtion::getTitle()const
{
    return _title;
}
QVector<Lesson> Professtion::getLessons()const
{
    return _lessons;
}
// TODO: REPLACE
//QMap<QVector<QString>, QVector<QString>> lessons_themes_ids;
void Professtion::selectLessonsFromDatabase( const SQLMgr &sqlManager,
                                             const QMap<QString, QVector<QString>> &lessons_themes_ids,
                                             const int questionsCount,
                                             const int answersCount )
{
    Lesson less;
    for( auto i = 0; i < lessons_themes_ids.keys().count(); i++ )
    {
        less = selectLesson( lessons_themes_ids.keys().at( i ),
                             sqlManager, 
                             lessons_themes_ids.values().at( i ), 
                             questionsCount, 
                             answersCount );
        pushLesson( less );
    }

}

Lesson Professtion::selectLesson( const QString &lessonId,
                                  const SQLMgr &sqlManager,
                                  const QVector<QString> &themeIds,
                                  const qint64 questionsCount,
                                  const int answersCount )const
{
    using namespace Table::Lesson;

    QStringList _fields( {Fields::NAME, Fields::TITLE, Fields::LANGUAGE, Fields::COURS } );

    
    SqlWhere _where( Fields::LESSON_ID + " = '" + lessonId + "'" );
    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, _where );

    Lesson less( query.value( query.record().indexOf( Fields::TITLE ) ).toString() );
    QLocale::Language language = static_cast<QLocale::Language>(query.value( query.record().indexOf( Fields::LANGUAGE ) ).toInt());
    if( language == 0 )
    {
        language = QLocale::system().language();
    }                                        

    less.setTitle();
    less.setLang( language );

    less.selectThemesFromDataBase( sqlManager, themeIds, questionsCount, answersCount );

    return less;
}