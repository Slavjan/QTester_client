#include "teststandard.h"


TestStandard::TestStandard()
{
    _questionsCount = 0;
}            
TestStandard::TestStandard( const QString &name )
{

}

QString TestStandard::getId()const
{
    return QString();
}


QString TestStandard::getName()const
{
    return QString();
}

QString TestStandard::getTitle()const
{
    return _title;
}
int TestStandard::getQuestionsCount()const
{
    return _questionsCount;
}
int TestStandard::getRang5()const
{
    return _range5;
}
int TestStandard::getRang4()const
{
    return _range4;
}
int TestStandard::getRang3()const
{
    return _range3;
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
void TestStandard::setRang5( const int range )
{
    _range5 = range;
}
void TestStandard::setRang4( const int range )
{
    _range4 = range;
}
void TestStandard::setRang3( const int range )
{
    _range3 = range;
}

void TestStandard::selectStandardFromBase( const SQLMgr &sqlManager )
{ //TODO: ƒŒœ»—¿“‹  À¿——
    using namespace Table::TestStandard;
    QStringList _fields( { Fields::TITLE, 
                           Fields::QUESTIONS_COUNT, 
                           Fields::RANGE5, 
                           Fields::RANGE4, 
                           Fields::RANGE3 } );
    SqlWhere _where( Fields::NAME + " = '" + _name + "'" );    

    QSqlQuery query( sqlManager.select( TABLE_NAME, _fields, _where, 1 ) );

}