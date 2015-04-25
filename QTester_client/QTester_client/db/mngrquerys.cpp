#include "mngrquerys.h"



QSqlQuery MngrQuerys::select(QString &tableName, QStringList &fields, qint64 limit)
{
    QString _limit = (limit <= 0)? "" : " LIMIT " + QString::number(limit);
    QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + _limit );

    query.exec();

    return query;
}

QSqlQuery MngrQuerys::select(QString &tableName, QStringList &fields, QString &where, qint64 limit)
{
    QString _where = (where.isEmpty() || where.isNull())? "" : " WHERE " + where;
    QString _limit = (limit <= 0)? "" : " LIMIT " + QString::number(limit);

    QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + _where + _limit);

    query.exec();

    return query;
}
