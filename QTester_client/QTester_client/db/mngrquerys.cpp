#include "mngrquerys.h"



QSqlQuery MngrQuerys::select(QString &tableName, QStringList &fields, QString &limit)
{
    QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + " LIMIT " + limit);

    query.exec();

    return query;
}

QSqlQuery MngrQuerys::select(QString &tableName, QStringList &fields, QString &where, QString &limit)
{
    QString _where = (where.isEmpty() || where.isNull())? "" : " WHERE " + where;
    QString _limit = (limit.isEmpty() || limit.isNull())? "" : " LIMIT " + limit;

    QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + _where + _limit);

    query.exec();

    return query;
}
