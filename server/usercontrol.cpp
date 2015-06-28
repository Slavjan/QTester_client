#include "usercontrol.h"


UserControl *UserControl::_instance = nullptr;
quint64 UserControl::tokenCount = 0;

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
QString UserControl::pushUser( const User &user )
{
    QByteArray salt  = "QTes" + user.getLogin().toUtf8() + "ter";
    QString newToken = QCryptographicHash::hash(
                           salt
                           + QString::number( tokenCount ).toUtf8(),
                           QCryptographicHash::Md5 )
                       .toHex();
    qDebug() << newToken;
//    QString newToken = QString::number(tokenCount);
    tokenCount++;
    _users[newToken] = user;

    return newToken;
}

bool UserControl::remove( const QString &token )
{
    return (_users.remove( token ) >= 1);
}
