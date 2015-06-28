#include "user.h"

User::User(const QString &login, const QString &password, const SQLMgr &db, const QString &apiVersion )
{
    _login = login;
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

QString User::getLogin() const
{
    return _login;
}

QString User::getApiVersion() const
{
    return _apiVersion;
}

QString User::getFullName() const
{
    return _fullName;
}

QString User::getGroup() const
{
    return _group;
}

void User::setName( const QString &name )
{
    _login = name;
}

void User::setApiVersion( const QString &version )
{
    _apiVersion = version;
}
