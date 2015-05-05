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