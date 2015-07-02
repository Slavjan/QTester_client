#ifndef USER_H
#define USER_H

#include "sqlmgr.h"
#include <QString>
#include <QCryptographicHash>

class User
{
private:
    QString _login;
    QString _fullName;
    QString _group;
    QString _apiVersion = "1.0";


public:
    User()
    {
    }
    User( const QString &login, const QString &password, const SQLMgr &db, const QString & = "1.0" );

    QString getLogin() const;
    QString getApiVersion() const;
    QString getFullName() const;
    QString getGroup() const;

    void setName( const QString &name );
    void setApiVersion( const QString &version );
};

namespace Tables
{
    namespace Users
    {
        const QString TABLE_NAME = "Users";

        namespace Fields
        {
            const QString USER_ID = "user_id";
            const QString FIRSTNAME = "firstName";
            const QString SECONDNAME = "secondName";
            const QString LOGIN = "login";
            const QString PASSWORD = "password";
            const QString USERGROUP_ID = "userGroup_id";
        }
    }

    namespace UserGroups
    {
        const QString TABLE_NAME = "UserGropes";

        namespace Fields
        {
            const QString USERGROUP_ID = "userGrope_id";
            const QString NAME = "name";
            const QString TITLE = "title";
        }
    }

}
#endif
