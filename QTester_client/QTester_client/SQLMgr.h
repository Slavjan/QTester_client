#ifndef SQLMGR_H
#define SQLMGR_H

#include <QString>
#include "ConnectionMgr.h"
#include "SQLMgr.h"

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
	
	virtual bool sessionConfigurate(QStringList &parameters, QStringList &values, qint64 limit) = 0;

public:			
	SQLMgr();// ms vs complains in derived classes, that there is no default constructor
	
	SQLMgr(const QString &dbDriver,
		   const QString &dbHost,
		   QString		  dbPath,
		   const QString &dbUser,
		   const QString &dbPass);

	~SQLMgr();

	virtual bool connectionOpen();
					   
	virtual bool createTable(QString &tableName, DataMap &data);
	virtual bool createTable(QString &tableName, DataMap &data,
					 QStringList &primary_keys_field, 
					 QStringList &foreign_keys_field, 
					 QStringList &preferences_tables,
					 QStringList &preferences_fields);

	virtual QSqlQuery select(QString &tableName,
							QStringList &fields,
							qint64 limit = 25);
	virtual QSqlQuery select(QString &tableName,
							QStringList &fields,
							QString &where_field,
							QString &where_value,
							qint64 limit = 25);
	virtual QSqlQuery insert(QString& tableName_to,
							QStringList& fields_to,
							QString& tableName_from,
							QStringList& fields_from,
							QString& where_field,
							QString& where_value,
							qint64 limit);
	virtual QSqlQuery insert(QString &tableName,
							QStringList &fields,
							QStringList &values,
							qint64 limit = 25);

	
};
#endif
