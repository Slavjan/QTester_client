#include "mngrquerys.h"

#include <QDebug>

bool MngrQuerys::createTable(QString &tableName, DataMap &data)
{
    QString sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";

    for(int i = 0; i < data.size(); ++i){
        sql += data.keys().at(i) + " " + data.values().at(i);
        if( i+1 < data.size() )
            sql += ", ";
    }

    sql += " );";

    qDebug() << sql; /// < \todo delete that

    QSqlQuery query(sql);
    return query.exec();
}

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
