#ifndef CONNECTIONMNGR_H
#define CONNECTIONMNGR_H

//#include "definespath.h"

#include <QtSql>
#include <QApplication>
#include <QDir>
#include <QUrl>
#include <QMessageBox>

class ConnectionMgr
{
private:
    QSqlDatabase db;
public:
    ConnectionMgr(const QString &dbDriver,
                  const QString &dbHost,
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
