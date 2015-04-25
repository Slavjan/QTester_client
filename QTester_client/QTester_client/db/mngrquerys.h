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

    void createTable(QString &tableName, DataMap &data);
public:
    QSqlQuery select(QString &tableName, QStringList &fields, QString &limit = "25");
    QSqlQuery select(QString &tableName, QStringList &fields, QString &where, QString &limit = "25");
};

#endif // MNGRQUERYS_H
