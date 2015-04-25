#ifndef MNGRCONNECTION_H
#define MNGRCONNECTION_H

//#include "definespath.h"

#include <QtSql>
#include <QApplication>
#include <QDir>
#include <QUrl>
#include <QMessageBox>

class MngrConnection
{
private:
    QSqlDatabase db;
public:
    MngrConnection(const QString &dbDriver,
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
