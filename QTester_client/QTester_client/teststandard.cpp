#include "teststandard.h"


TestStandard::TestStandard()
{
    _questionsCount = 0;
}  
TestStandard::TestStandard( const QString &id, const QString &name )
{
    _id = id;
    _name = name;
}

QString TestStandard::getId()const
{
    return _id;
}
QString TestStandard::getName()const
{
    return _name;
}                                       
QString TestStandard::getTitle()const
{
    return _title;
}
int TestStandard::getQuestionsCount()const
{
    return _questionsCount;
}
S_VS TestStandard::getLessons_Themes_ids()const
{
    return _lessons_themes_ids;
}

void TestStandard::setId( const QString &id )
{
    _id = id;
}
void TestStandard::setName( const QString &name )
{
    _name = name;
}
void TestStandard::setTitle( const QString &title )
{
    _title = title;
}
void TestStandard::setQuestionsCount( const int questionsCount )
{
    _questionsCount = questionsCount;
}
void TestStandard::pushName( const QString &name )
{
    StandardNames.push_back( name );
}

void TestStandard::selectStandardFromBase( const SQLMgr &sqlManager )
{ //TODO: ДОПИСАТЬ КЛАСС
    using namespace Table::TestStandard;
    QStringList _fields( { Fields::TITLE, 
                           Fields::QUESTIONS_COUNT} );
    SqlWhere _where( Fields::STANDARD_ID + " = '" + _id + "'" );    

    QSqlQuery query( sqlManager.select( TABLE_NAME, _fields, _where, 1 ) );

    _title = query.value( query.record().indexOf( Fields::TITLE ) ).toString();
    _questionsCount = query.value( query.record().indexOf( Fields::QUESTIONS_COUNT ) ).toInt();
    

}