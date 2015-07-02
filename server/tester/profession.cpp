#include "profession.h"


Profession::Profession()
{
}
Profession::Profession( const QString &name )
{
    _name = name;
}
  
void Profession::setId( const QString &id )
{
    _id = id;
}
void Profession::setName( const QString &name )
{
    _name = name;
}
void Profession::setTitle( const QString &title )
{
    _title = title;
}
void Profession::pushLesson( const Lesson &lesson )
{
    _lessons.push_back( lesson );
}

QString Profession::getId()const
{
    return _id;
}
QString Profession::getName()const
{
    return _name;
}
QString Profession::getTitle()const
{
    return _title;
}
QVector<Lesson> Profession::getLessons()const
{
    return _lessons;
}
// TODO: REPLACE
//QMap<QVector<QString>, QVector<QString>> lessons_themes_ids;
void Profession::selectLessonsFromDatabase( const SQLMgr &sqlManager,
                                            const idThemeIdsMap &lessons_themes_ids,
                                            const int questionsCount,
                                            const int answersCount )
{
    Lesson less;
    for( auto i = 0; i < lessons_themes_ids.keys().count(); i++ )
    {
        QString key = lessons_themes_ids.keys().at( i );
        less = selectLesson( key,
                             sqlManager, 
                             lessons_themes_ids[key],
                             questionsCount, 
                             answersCount );
        pushLesson( less );
    }

}

Lesson Profession::selectLesson( const QString &lessonId,
                                  const SQLMgr &sqlManager,
                                  const QStringList &themeIds,
                                  const qint64 questionsCount,
                                  const int answersCount )const
{
    using namespace Tables::Lesson;

    QStringList _fields( {Fields::NAME, Fields::TITLE, Fields::LANGUAGE, Fields::COURSE } );     
    SqlWhere _where( Fields::LESSON_ID + " = '" + lessonId + "'" );
    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, _where );
    query.first();

    Lesson less( query.value( query.record().indexOf( Fields::NAME ) ).toString() );
    less.setTitle( query.value( query.record().indexOf( Fields::TITLE ) ).toString() );

    QLocale::Language language = static_cast<QLocale::Language>(query.value( query.record().indexOf( Fields::LANGUAGE ) ).toInt());
    if( language == 0 )
    {
        language = QLocale::system().language();
    }    
    less.setLang( language );

    less.selectThemesFromDataBase( sqlManager, themeIds, questionsCount, answersCount );

    return less;
}

IdTitleMap Profession::getProfList( const SQLMgr &sqlManager )
{
    using namespace Tables::Professtion;
    QStringList _fields( { Fields::PROFESSION_ID, Fields::TITLE } );
    IdTitleMap profList;

    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, 25);
   // qDebug() << "[Profession::getProfList]> query.size" << query.value("rCount").toInt();
    while( query.next() )
    {
        QString id = query.value( query.record().indexOf( Fields::PROFESSION_ID ) ).toString(),
                title = query.value( query.record().indexOf( Fields::TITLE ) ).toString();

        qDebug() << " " << id << " | title > " << title;
        qDebug() << " 0 profList writed";
        profList.insert(id, title);
        qDebug() << "profList writed: " << profList ;
    }
  //  qDebug() << "[Profession::getProfList]> IdTitleMap >" << profList;
    return profList;
}

void Profession::print()const
{
    qDebug() << _title;

    for( auto i = 0; i < _lessons.count(); i++ )
    {
        _lessons.at( i ).print();
    }
}
