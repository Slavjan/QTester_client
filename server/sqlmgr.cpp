#include <QDebug>
#include "sqlmgr.h"	 
                 
// public
SQLMgr::SQLMgr( const QString &dbDriver,
                const QString &dbHost,
                QString		  dbPath,
                const QString &dbUser,
                const QString &dbPass )
{
    Connection = new ConnectionMgr( dbDriver, dbHost, dbPath, dbUser, dbPass );
    connectionOpen();
}


SQLMgr::~SQLMgr()
{
    Connection->close();
    delete Connection;
}


bool SQLMgr::connectionOpen()
{
    if( Connection->open() )
    {
        qDebug() << "Debug> connecton Open ";
        return true;
    }
    return false;
}

bool SQLMgr::createTable( const QString &tableName, const DataMap &data ) const
{
    QString sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";

    for( int i = 0; i < data.size(); ++i )
    {
        sql += data.keys().at( i ) + " " + data.values().at( i );
        if( i + 1 < data.size() )
            sql += ", ";
    }

    sql += " );";

    qDebug() << "Debug> [SQLMgr::createTable] " << sql; /// < \todo delete that

    QSqlQuery query( sql );
    return query.exec();
}

bool SQLMgr::createTable( const QString     &tableName,
                          const DataMap     &data,
                          const QStringList &primary_keys_field,
                          const QStringList &foreign_keys_field,
                          const QStringList &preferences_tables,
                          const QStringList &preferences_fields ) const
{
    QString sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";

    for( int i = 0; i < data.size(); ++i )
    {
        sql += data.keys().at( i ) + " " + data.values().at( i );
        if( i + 1 < data.size() )
            sql += ", ";
    }
    sql += ",\n CONSTRAINT PK_" + tableName + "PRIMARY KEY (";
    for( int i = 0; i < primary_keys_field.count(); i++ )
    {
        sql += primary_keys_field.join( ", " );
    }
    sql += " ),\n ";
    for( int i = 0; i < foreign_keys_field.count(); i++ )
    {
        sql += "CONTRANT FK_";
    }

    sql += " )\n)\nGO";
#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::createTable] " << sql; // TODO: delete that
#endif
    QSqlQuery query( sql );
    return query.exec();
}

QSqlQuery SQLMgr::select( const QString &tableName, const QStringList &fields, qint64 limit ) const
{
    QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number( limit );
    QString sql( "SELECT " + fields.join( ", " ) + " FROM " + tableName + _limit );
    QSqlQuery query( sql );

#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::select] " << sql; // TODO: delete that
#endif	
#ifdef QT_DEBUG
    qDebug() << "Debug> [SQLMgr::select] " << sql; // TODO: delete that
#endif

    query.exec();

    return query;
}

/*!
 * \brief SQLMgr::select
 * \param tableName - table name
 * \param fields - list of fields
 * \param where - WHERE SQL construction with out 'WHERE'
 * \param limit
 * \return - QSqlQuery
 */
QSqlQuery SQLMgr::select( const QString     &tableName,
                          const QStringList &fields,
                          const SqlWhere     &where,
                          qint64       limit ) const
{
    QString _where;
    if( !where.toString().isEmpty() )
    {
        _where = where.toString();
    }

    QString _limit = (limit > 0) ? " LIMIT " + QString::number( limit ) : "";

    QStringList _fields;
    /*for(int i = 0; i < fields.count(); ++i){
        _fields.push_back("[" + fields[i] + "]");
        }*/
    QString sql( "SELECT " + fields.join( ", " ) + " FROM " + tableName + _where + _limit + ";" );
    QSqlQuery query;

#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::select] " << sql; // TODO: delete that
#endif

    if( !query.exec( sql ) )
    {
        qWarning() << "Warning> [SQLMgr::select] " << query.lastError(); // TODO: delete that
    }

    return query;
}

QSqlQuery SQLMgr::select( const QString     &tableName,
                          const QStringList &fields,
                          const SqlOrderBy  &order,
                          qint64       limit ) const
{
    QString _order;
    if( !order.toString().isEmpty() )
    {
        _order = order.toString();
    }


    QString _limit = (limit > 0) ? " LIMIT " + QString::number( limit ) : "";

    QStringList _fields;
    /*for(int i = 0; i < fields.count(); ++i){
    _fields.push_back("[" + fields[i] + "]");
    }*/
    QString sql( "SELECT " + fields.join( ", " ) + " FROM " + tableName + _order + _limit + ";" );
    QSqlQuery query;

#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::select] " << sql; // TODO: delete that
#endif

    if( !query.exec( sql ) )
    {
        qWarning() << "Warning> [SQLMgr::select] " << query.lastError(); // TODO: delete that
    }

    return query;
}

QSqlQuery SQLMgr::select( const QString     &tableName,
                          const QStringList &fields,
                          const SqlWhere    &where,
                          const SqlOrderBy  &order,
                          qint64       limit ) const
{
    QString _order;
    if( !order.toString().isEmpty() )
    {
        _order = order.toString();
    }

    QString _where;
    if( !where.toString().isEmpty() )
    {
        _where = where.toString();
    }

    QString _limit = (limit > 0) ? " LIMIT " + QString::number( limit ) : "";

    QStringList _fields;
    /*for(int i = 0; i < fields.count(); ++i){
    _fields.push_back("[" + fields[i] + "]");
    }*/
    QString sql( "SELECT " + fields.join( ", " ) + " FROM " + tableName + _where + _order + _limit + ";" );
    QSqlQuery query;

#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::select] " << sql; // TODO: delete that
#endif

    if( !query.exec( sql ) )
    {
        qWarning() << "Warning> [SQLMgr::select] " << query.lastError(); // TODO: delete that
    }

    return query;
}

//TODO: необходимо уточнить действие и сиснтаксис, следующей конструкции 
QSqlQuery SQLMgr::insert( const QString     &tableName_to,
                          const QStringList &fields_to,
                          const QString     &tableName_from,
                          const QStringList &fields_from,
                          const QString     &where ) const
{
    // This code is autogenerated
    QString _fields_to = " (" + fields_to.join( ", " ) + ") ";
    QString _select = "SELECT (" + fields_from.join( ", " ) + ") ";
    QString _from = "FROM " + tableName_from + " ";
    QString _where = "WHERE " + where + ";";

    QString	sql( "INSERT INTO " + tableName_to + _fields_to + _select + _where );

    QSqlQuery query( sql );

#ifdef _DEBUG
    qDebug() << "Debug> [SQLMgr::insert] " << sql; // TODO: delete that
#endif
    if( !query.exec() )
    {
        qWarning() << "Warning> [SQLMgr::insert] " << query.lastError();
    }

    return query;
}

QSqlQuery SQLMgr::insert( const QString &tableName, const DataMap &data ) const
{
    QSqlQuery query;
    DataMap _data;
    if( !data.isEmpty() )
    {
        for( int i = 0; i < data.count(); ++i )
        {
            _data[data.keys().at( i )] = "'" + data.values().at( i ) + "'";
        }
        QString keys = QStringList( _data.keys() ).join( ", " );
        QString values = QStringList( _data.values() ).join( ", " );
        QString sql( "INSERT INTO " + tableName + " (" + keys + ") VALUES (" + values + ");" );
        QSqlQuery query;

        qDebug() << "Debug>  [SQLMgr::insert] " << sql; /// \todo TODO: debug outpud

        if( !query.exec( sql ) )
        {
            qWarning() << "Warning> [SQLMgr::insert] " << query.lastError();
        }            
    }

    return query;
}

bool SQLMgr::auth( const QString &login, const QString &password ) const
{
    using namespace Table::Users;

//    QByteArray hashPass = QCryptographicHash::hash( "123", QCryptographicHash::Md5 );

//    qDebug() << "[SQLMgr::auth]password>" << hashPass;

    SqlWhere _where( Fields::LOGIN + "= '" + login + "'" );
    _where.AND( Fields::PASSWORD + "= '" + password + "'" );

    QSqlQuery query = select( TABLE_NAME, QStringList( "COUNT(*) AS rCount" ), _where );

    if( !query.exec() )
    {
        //  dbug
        return false;
    }

    bool ok = false;
    qDebug() << query.value("rCount");
    query.first();
    qDebug() << query.value("rCount");
    if( ( query.value("rCount").toInt(&ok) >= 1 ) && ok )
    {
        return true;
    }

    return false;
}
