#include "sqlitemgr.h"

SQLiteMgr* SQLiteMgr::_instance = nullptr;

SQLiteMgr::SQLiteMgr() : SQLMgr()
{
}

SQLiteMgr::SQLiteMgr(const QString& dbHost, const QString &dbPath)
    : SQLMgr("QSQLITE", dbHost, dbPath, "", "")
{
}

SQLiteMgr *SQLiteMgr::instance(const QString &dbHost, const QString &dbPath)
{
    if( ! _instance ){
        _instance = new SQLiteMgr(dbHost, dbPath);
    }

    return _instance;
}

qlonglong SQLiteMgr::size(const QString &tableName)
{
    QSqlQuery query = select( tableName, {"COUNT(rowid) AS rCount"} );
    query.first();
    return query.value("rCount").toLongLong();
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
