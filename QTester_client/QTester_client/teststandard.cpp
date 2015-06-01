#include "teststandard.h"


TestStandard::TestStandard()
{
    questionsCount = 0;
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
    return questionsCount;
}
int TestStandard::getRang5()const
{
    return _rang5;
}
int TestStandard::getRang4()const
{
    return _rang4;
}
int TestStandard::getRang3()const
{
    return _rang3;
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