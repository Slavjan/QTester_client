#ifndef SQLMGR_H
#define SQLMGR_H

#include <QString>
#include "connectionmgr.h"

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>

#ifdef _DEBUG
#include <QDebug>
#endif

typedef QMap<QString, QString> DataMap;


class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected: 	
	ConnectionMgr*	Connection;
	
    virtual bool sessionConfigurate(const DataMap &data) = 0;

public:			
	SQLMgr();// ms vs complains in derived classes, that there is no default constructor
	
	SQLMgr(const QString &dbDriver,
		   const QString &dbHost,
                 QString  dbPath,
		   const QString &dbUser,
		   const QString &dbPass);

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
                             const QString     &where,
                                   qint64       limit = 25) const;
    virtual QSqlQuery insert(const QString     &tableName_to,
                             const QStringList &fields_to,
                             const QString     &tableName_from,
                             const QStringList &fields_from,
                             const QString     &where) const;

    virtual QSqlQuery insert(const QString     &tableName,
                             const DataMap     &data) const;
    virtual qint64 size(     const QString     &tableName) = 0;

};
#endif
