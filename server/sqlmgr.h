#ifndef SQLMGR_H
#define SQLMGR_H

#include <QString>
#include "connectionmgr.h"
#include "sqlwhere.h"
#include "sqlorderby.h"
//#include "user.h"

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QCryptographicHash>

#ifdef _DEBUG
    #include <QDebug>
#endif

typedef QMap<QString, QString> DataMap;



class SQLMgr ///SQL \brief Manadger the base class for work with Data Bases
{
protected:
    static SQLMgr *_instance;
    ConnectionMgr *_connection;


    virtual bool sessionConfigurate(const DataMap &data) = 0;


public:
    /*static SQLMgr& instance();
    static SQLMgr& instance( const QString &dbDriver,
                             const QString &dbHost,
                             QString  dbPath,
                             const QString &dbUser,
                             const QString &dbPass );*/
    SQLMgr(){}// ms vs complains in derived classes, that there is no default constructor

    SQLMgr( const QString &dbDriver,
            const QString &dbHost,
            QString  dbPath,
            const QString &dbUser,
            const QString &dbPass );
    ~SQLMgr();

    static bool transaction();

    virtual bool connectionOpen();

    virtual bool createTable(const QString     &tableName,
                             const DataMap     &data) const;
    virtual bool createTable(const QString     &tableName,
                             const DataMap     &data,
                             const QStringList &primary_keys_field,
                             const QStringList &foreign_keys_field,
                             const QStringList &preferences_tables,
                             const QStringList &preferences_fields) const;

    virtual QSqlQuery select(const QString     &tableName,
                             const QStringList &fields,
                                   qint64       limit = 25) const;
    virtual QSqlQuery select(const QString     &tableName,
                             const QStringList &fields,
                             const SqlWhere    &where,
                                   qint64       limit = 25) const;
    virtual QSqlQuery select(const QString     &tableName,
                             const QStringList &fields,
                             const SqlOrderBy  &order,
                                   qint64       limit = 25) const;
    virtual QSqlQuery select(const QString     &tableName,
                             const QStringList &fields,
                             const SqlWhere    &where,
                             const SqlOrderBy  &order,
                                   qint64       limit = 25) const;

    virtual QSqlQuery insert(const QString     &tableName_to,
                             const QStringList &fields_to,
                             const QString     &tableName_from,
                             const QStringList &fields_from,
                             const QString     &where) const;
    virtual QSqlQuery insert(const QString     &tableName,
                             const DataMap     &data) const;

    virtual qint64 size(     const QString     &tableName) = 0;

    virtual bool auth(const QString &login, const QString &password)const;

};
#endif
