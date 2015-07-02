#pragma once
#ifndef USERCONTROL_H
#define USERCONTROL_H

#include <QMap>
#include "user.h"

typedef QHash<QString, User> TokenUserHash;
#define exceptions public

class UserControl
{
private:
    static quint64 tokenCount;
    TokenUserHash _users;
    static UserControl *_instance;

    UserControl(){}

exceptions:
    class InvalidToken{};

public:
    static UserControl& instance();

    User getUser(const QString &token) const;
    TokenUserHash getUsers()const;
    QString pushUser( const User &user );
    bool remove( const QString &token );
};

#endif
