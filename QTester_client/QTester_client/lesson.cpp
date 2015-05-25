#include "lesson.h"	  

Lesson::Lesson(const QString &title)
{
	_title = title;
}

QString Lesson::getTitle() const
{
	return _title;
}
QLocale::Language Lesson::getLang() const
{
	return _lang;
}
QVector<Theme> Lesson::getThemes() const
{
	return _themes;
}

void Lesson::setTitle(const QString &title)
{
	_title = title;
}
void Lesson::setLang(const QLocale::Language &lang)
{
	_lang = lang;
}
void Lesson::pushTheme(const Theme &theme)
{
	_themes.push_back(theme);
}

void Lesson::selectThemesFromDataBase( const SQLMgr &sqlManager, 
                                      const QVector<int> &themIds, 
                                      const int themesCount,  
                                      const qint64 questionsCount,
                                      const int answersCount )
{
    for( auto i = 0; i < themesCount; i++ )
    {
        Theme topic = selectTheme( themIds.at( i ), sqlManager, questionsCount, answersCount );
        pushTheme( topic );
    }         
}

Theme Lesson::selectTheme( const int themeId, 
                           const SQLMgr &sqlManager, 
                           const qint64 questionsCount,
                           const int answersCount )const
{
    using namespace Table::Theme;
    SqlWhere _where( Fields::THEME_ID + " = '" + themeId + "'" );
    QStringList _fields( { Fields::LESSON_ID, 
                           Fields::NAME, 
                           Fields::TITLE, 
                           Fields::DIFFICULTY } );

    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, _where );

    query.first();

    Theme topic( query.value( query.record().indexOf( Table::Theme::Fields::TITLE ) ).toString() );
    topic.setDifficulty( query.value( query.record().indexOf( Fields::DIFFICULTY ) ).toInt() );
    topic.setId( QString::number( themeId ) );
    topic.setLessonId( _id );

    topic.selectFromDatabase( sqlManager, questionsCount, answersCount );

    return topic;
}