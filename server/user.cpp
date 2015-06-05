#include "user.h"

User::User( const QString &name, const QString &apiVersion )
{
    _name = name;
    _apiVersion = apiVersion;
}

QString User::getName()
{
    return _name;
}                         

QString User::getApiVersion()
{
    return _apiVersion;
}    

void User::setName( const QString &name )
{
    _name = name;
}

void User::setApiVersion( const QString &version )
{
    _apiVersion = version;
}              