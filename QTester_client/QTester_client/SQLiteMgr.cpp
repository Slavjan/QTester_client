#include "SQLiteMgr.h"


SQLiteMgr::SQLiteMgr() : SQLMgr()
{				 	
}


SQLiteMgr::~SQLiteMgr()
{
	SQLMgr::~SQLMgr();
}

void SQLiteMgr::init(const QString& dbHost, const QString& dbUser, const QString& dbPass)
{
	Connection = new ConnectionMgr("QSQLITE", dbHost, dbUser, dbPass);
	Connection->open();
}

bool SQLiteMgr::createTable(QString& tableName, DataMap& data)
{
	return true;
}

QSqlQuery SQLiteMgr::select(QString& tableName, QStringList& fields, qint64 limit)
{
	return QSqlQuery();
}

//bool SQLiteMgr::createTable(QString& tableName, DataMap& data) : createTable(&tableName, &data);


QSqlQuery SQLiteMgr::insert(QString& tableName_to, QStringList& fields_to, QString& tableName_from, QStringList& fields_from, QString& where_field, QString& where_value, qint64 limit)
{
	return QSqlQuery();
}

void SQLiteMgr::Hi(QString)
{
}

bool SQLiteMgr::sescionConfigurate(QStringList& parameters, QStringList& values, qint64 limit)
{
	QSqlQuery query;
	if ((!parameters.isEmpty() && !values.isEmpty()) && parameters.count() == values.count())
	{
		QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
		QString query_string = "\0";
		for (size_t i = 0; i <= parameters.count(); i++)
		{
			query_string += "PRAGMA" + parameters.at(i) + " = " + values.at(i) + " \n";
		}
		query_string += _limit;

		return query.exec(query_string);			
	}
	return false;
}