#include "accesscontrol.h"

AccessControl::AccessControl()
{

}

bool AccessControl::isAccessTo(const User &user, const Permissions::Permission permission, const SQLMgr &db)
{
//    QString group = user.getGroup();
//    SqlWhere where(Tables::UserGroups::Fields::NAME + " = " + group);
//    db.select( Tables::UserGroups::TABLE_NAME, {Tables::UserGroups::Fields::NAME},  "");
    return false;
}

