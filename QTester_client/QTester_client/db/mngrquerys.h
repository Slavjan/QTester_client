#ifndef MNGRQUERYS_H
#define MNGRQUERYS_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>

typedef QMap<QString,QString> DataMap;

/*!
 * \brief The MngrQuerys is static class for executable SQL querys
 */
class MngrQuerys
{
private:
    MngrQuerys();
    ~MngrQuerys();

public:
    static bool createTable(QString &tableName, DataMap &data);
public:
    static QSqlQuery select(QString &tableName, QStringList &fields, qint64 limit = 25 );
    static QSqlQuery select(QString &tableName, QStringList &fields, QString &where, qint64 limit = 25 );
};

#endif // MNGRQUERYS_H
