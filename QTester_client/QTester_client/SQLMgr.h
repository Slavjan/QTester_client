#ifndef SQLMGR_H
#define SQLMGR_H

#include <QString>
#include "ConnectionMgr.h"
#include "SQLMgr.h"

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>

typedef QMap<QString, QString> DataMap;


class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected: 	
	ConnectionMgr*	Connection;
	
	SQLMgr();// ms vs complains in derived classes, that there is no default constructor

public:			
	SQLMgr(const QString &dbDriver,
		   const QString &dbHost,
		   const QString &dbUser,
		   const QString &dbPass);

	~SQLMgr();	

	void connect();
	void disconnect();

	static bool createTable(QString &tableName, DataMap &data);

	static QSqlQuery select(QString &tableName,
							QStringList &fields,
							qint64 limit = 25);
	static QSqlQuery select(QString &tableName,
							QStringList &fields,
							QString &where_field,
							QString &where_value,
							qint64 limit = 25);
	static QSqlQuery insertSelection(QString& tableName_to,
									 QStringList& fields_to,
									 QString& tableName_from,
									 QStringList& fields_from,
									 QString& where_field,
									 QString& where_value,
									 qint64 limit);
	static QSqlQuery insertValues(QString &tableName,
								  QStringList &fields,
								  QStringList &values,
								  qint64 limit = 25);
};
#endif
