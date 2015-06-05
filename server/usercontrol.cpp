#include "usercontrol.h"


UserControl *UserControl::_instance = nullptr;
int UserControl::tokenCount = 0;

UserControl& UserControl::instance()
{
    if( !_instance )
    {
        _instance = new UserControl;
    }
    return *_instance;
}

User UserControl::getUser( const QString &token ) const
{
    if( _users.contains( token ) )
    {
        return _users[token];
    }
    else
    {
        return User();
    }
}
TokenUserMap UserControl::getUsers()const
{
    return _users;
}
void UserControl::pushUser( const User &user )
{
    QString newToken = QCryptographicHash::hash( QString::number( tokenCount ).toUtf8(), QCryptographicHash::Md5 );
    tokenCount++;
    _users[newToken] = user;
}

bool UserControl::remove( const QString &token )
{
    return (_users.remove( token ) >= 1);
}