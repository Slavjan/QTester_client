#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include "users/user.h"
#include "db/sqlmgr.h"

namespace Permissions {
    enum Permission{
        AuthWithoutPassword
    };
}

class AccessControl
{
public:
    AccessControl();

    static bool isAccessTo(const User &user, const Permissions::Permission permission, const SQLMgr &db);
};

#endif // ACCESSCONTROL_H
