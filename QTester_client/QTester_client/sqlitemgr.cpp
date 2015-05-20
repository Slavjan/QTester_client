#include "sqlitemgr.h"
	 
SQLiteMgr::SQLiteMgr() : SQLMgr()
{				 	
}

SQLiteMgr::SQLiteMgr(const QString& dbHost, QString	dbPath, const QString& dbUser, const QString& dbPass)
    : SQLMgr("QSQLITE", dbHost, dbPath, dbUser, dbPass)
{
}

qlonglong SQLiteMgr::size(const QString &tableName)
{
    QSqlQuery query = select( tableName, {"count(rowid)"} );
    query.first();
    return query.value(0).toLongLong();
}

bool SQLiteMgr::sessionConfigurate(const DataMap &data)
{
	QSqlQuery query;
    if( ! data.isEmpty() )
	{
		QString query_string;
        for (auto i = 0; i < data.count(); i++) /// \warning TODO: БЫЛО <= ПРОВЕРИТЬ
        {
            query_string += "PRAGMA" + data.keys().at(i) + " = " + data.values().at(i) + " \n";
		}

		return query.exec(query_string);			
	}
	return false;
}
