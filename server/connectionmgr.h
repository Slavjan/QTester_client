#ifndef CONNECTIONMNGR_H
#define CONNECTIONMNGR_H

//#include "definespath.h"

#include <QtSql>
#include <QCoreApplication>
#include <QDir>
#include <QUrl>

class ConnectionMgr
{
private:
    QSqlDatabase db;
public:
    ConnectionMgr(const QString &dbDriver,
                  const QString &dbHost,
				  QString		 dbPath,
				  const QString &dbUser,
				  const QString &dbPass);
    QSqlError lastError();
    bool open();
    void close();
    bool transaction();
    bool commit();
    bool rollback();
    bool isOpen();
};

#endif // MNGRCONNECTION_H
