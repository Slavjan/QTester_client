#include "user.h"

User::User(const QString &login, const QString &password, const SQLMgr &db, const QString &apiVersion )
{
    _name = login;
    _apiVersion = apiVersion;

    SqlWhere _where( Table::Users::Fields::LOGIN + " = '" + login + "'" );
             _where.AND( Table::Users::Fields::PASSWORD + " = '" + password + "'" );
    QStringList _fields( { "firstName ||' '|| secondName AS fullName", Table::Users::Fields::USERGROUP_ID } );

    QSqlQuery query = db.select(Table::Users::TABLE_NAME, _fields, _where);
    query.first();

    QString fullUserName = query.value( "fullName" ).toString();
    int userGroup = query.value( Table::Users::Fields::USERGROUP_ID ).toInt();

    _fullName = fullUserName;
    _group = QString::number( userGroup );
}

QString User::getName()
{
    return _name;
}

QString User::getApiVersion()
{
    return _apiVersion;
}

QString User::getFullName()
{
    return _fullName;
}

QString User::getGroup()
{
    return _group;
}

void User::setName( const QString &name )
{
    _name = name;
}

void User::setApiVersion( const QString &version )
{
    _apiVersion = version;
}
