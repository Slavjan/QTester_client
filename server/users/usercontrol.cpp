#include "usercontrol.h"


UserControl *UserControl::_instance = nullptr;
quint64 UserControl::tokenCount = 0;

/*! \~russian
 * \brief Метод для получения instance singleton объекта
 * \return UserControl& - ссылка на instance
 */
UserControl& UserControl::instance()
{
    if( !_instance )
    {
        _instance = new UserControl;
    }
    return *_instance;
}

/*! \~russian
 * \brief Мотод для получения пользователя по его токену
 * \param token - токен авторизированного пользователя, выдается методом UserControl::pushUser
 * \return User - пользователь с соответствующим токеном
 * \exceptions UserControl::InvalidToken - выбрасывается если пользователя с таким токеном не существует
 */
User UserControl::getUser( const QString &token ) const
{
    if( _users.contains( token ) ) {
        return _users[token];
    } else {
        throw new InvalidToken;
    }
}

/*! \~russian
 * \brief метод для получения карты всех пользователей с их токенами
 * \return TokenUserMap - карта вида <Токен, Пользователь>
 */
TokenUserHash UserControl::getUsers()const
{
    return _users;
}

/*! \~russian
 * \brief Метод для добавления пользователя
 * \param user - ссылка на объект User
 * \return QString - токен выданный для данного пользователя
 */
QString UserControl::pushUser( const User &user )
{
    QByteArray salt  = "QTes" + user.getLogin().toUtf8() + "ter";
    QString newToken = QCryptographicHash::hash(
                           salt
                           + QString::number( tokenCount ).toUtf8(),
                           QCryptographicHash::Md5 )
                       .toHex();
    tokenCount++;
    _users[newToken] = user;

    return newToken;
}

/*! \~russian
 * \brief Метод для удаления пользователя из списка
 * \param token - токен пользователя выданный ему методом UserControl::pushUser
 * \return bool - успех удаления
 */
bool UserControl::remove( const QString &token )
{
    return (_users.remove( token ) >= 1);
}
