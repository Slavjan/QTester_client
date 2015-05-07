#include <QDebug>
#include "SQLMgr.h"
#include <iostream>


SQLMgr::SQLMgr()
{
}



// public
SQLMgr::SQLMgr(const QString &dbDriver,
			   const QString &dbHost,
			   const QString &dbUser,
			   const QString &dbPass)
{	
	Connection = new ConnectionMgr(dbDriver, dbHost, dbUser, dbPass);
	connectionOpen();
}


SQLMgr::~SQLMgr()
{
	Connection->close();
	delete Connection;
}


bool SQLMgr::connectionOpen()
{
	if(Connection->open())
	{
		qDebug() << "connecton Open \n";
		return true;
	}
	return false;
}

bool SQLMgr::createTable(QString &tableName, DataMap &data)
{
	QString sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";

	for (int i = 0; i < data.size(); ++i){
		sql += data.keys().at(i) + " " + data.values().at(i);
		if (i + 1 < data.size())
			sql += ", ";
	}

	sql += " );";

	qDebug() << sql << "\n"; /// < \todo delete that

	QSqlQuery query(sql);
	return query.exec();
}

bool SQLMgr::createTable(QString &tableName, DataMap &data, 
						 QStringList &primary_keys_field, 
						 QStringList &foreign_keys_field, 
						 QStringList &preferences_tables, 
						 QStringList &preferences_fields)
{
	QString sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ( ";

	for (int i = 0; i < data.size(); ++i){
		sql += data.keys().at(i) + " " + data.values().at(i);
		if (i + 1 < data.size())
			sql += ", ";
	}
	sql += ",\n CONSTRAINT PK_" + tableName + "PRIMARY KEY (";
	for (size_t i = 0; i < primary_keys_field.count(); i++)
	{
		sql += primary_keys_field.join(", ");
	}
	sql += " ),\n ";
	for (size_t i = 0; i < foreign_keys_field.count(); i++)
	{
		sql += "CONTRANT FK_";
	}

	sql += " )\n)\nGO";
#ifdef _DEBUG
	qDebug() << sql << "\n"; // TODO: delete that
#endif
	QSqlQuery query(sql);
	return query.exec();
}

QSqlQuery SQLMgr::select(QString &tableName, QStringList &fields, qint64 limit)
{
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
	QString sql("SELECT " + fields.join(", ") + " FROM " + tableName + _limit);
	QSqlQuery query(sql);
#ifdef _DEBUG
	qDebug() << sql << "\n"; // TODO: delete that
#endif	
	
	query.exec();

	return query;
}

QSqlQuery SQLMgr::select(QString &tableName, QStringList &fields, QString &where_field, QString &where_value, qint64 limit)
{
	QString _where = ((where_field.isEmpty() || where_field.isNull()) && (where_value.isEmpty() || where_value.isNull())) ? "" : " WHERE " + where_field + " = " + where_value;
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
	QString sql("SELECT " + fields.join(", ") + " FROM " + tableName + _where + _limit); 
	QSqlQuery query(sql);

#ifdef _DEBUG
	qDebug() << sql << "\n"; // TODO: delete that
#endif

	query.exec();

	return query;
}

QSqlQuery SQLMgr::insert(QString &tableName_to, 
						 QStringList &fields_to, 
						 QString &tableName_from, 
						 QStringList &fields_from, 
						 QString &where_field, 
						 QString &where_value, 
						 qint64 limit)
{
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
	QString	sql("INSERT INTO " + tableName_to + "(" + fields_to.join(", ") + ")" +
				"SELECT " + fields_from.join(", ") + ")  FROM " + tableName_from +
				" WHERE " + where_field + " = " + where_value + _limit);
	
	QSqlQuery query(sql);

#ifdef _DEBUG
	qDebug() << sql << "\n"; // TODO: delete that
#endif
	
	query.exec();

	return query;
}
 //TODO: необходимо уточнить действие и сиснтаксис, следующей конструкции 
QSqlQuery SQLMgr::insert(QString &tableName, QStringList &fields, QStringList &values, qint64 limit)
{
	QSqlQuery query;
	if (!values.isEmpty())
	{
		QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
		QString sql("INSERT INTO " + tableName + " (" + fields.join(", ") + ")" + "VALUES(" + values.join(", ") + ") " + _limit);
		query = QSqlQuery(sql);

#ifdef _DEBUG
		qDebug() << sql << "\n"; // TODO: delete that
#endif

		query.exec();
	}

	return query;
}