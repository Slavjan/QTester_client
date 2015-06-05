#pragma once
#ifndef USERCONTROL_H
#define USERCONTROL_H

#include <QMap>
#include "user.h"

typedef QMap<QString, User> TokenUserMap;

class UserControl
{
private:
    static int tokenCount;
    TokenUserMap _users;
    static UserControl *_instance;

    UserControl(){}
public:
    static UserControl& instance();

    User getUser(const QString &token) const;
    TokenUserMap getUsers()const;
    void pushUser( const User &user );
    bool remove( const QString &token );
};

#endif       