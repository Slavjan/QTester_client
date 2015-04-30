#include <QDebug>
#include "SQLMgr.h"

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
	Connection->open();
}


SQLMgr::~SQLMgr()
{
	Connection->close();
	delete Connection;
}


void SQLMgr::connect()
{
	//db = QSqlDatabase::addDatabase(_SQLDRV, _connectionName);
	//db.setHostName(_host);
	//db.setDatabaseName(_DBName);
	//db.setUserName(_userName);
	//db.setPassword(_pwd);
	//if (!db.open())
	//	return false;
	////TODO: error enum;
	//return true;
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

	qDebug() << sql; /// < \todo delete that

	QSqlQuery query(sql);
	return query.exec();
}

QSqlQuery SQLMgr::select(QString &tableName, QStringList &fields, qint64 limit)
{
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
	QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + _limit);

	query.exec();

	return query;
}

QSqlQuery SQLMgr::select(QString &tableName, QStringList &fields, QString &where_field, QString &where_value, qint64 limit)
{
	QString _where = ((where_field.isEmpty() || where_field.isNull()) && (where_value.isEmpty() || where_value.isNull())) ? "" : " WHERE " + where_field + " = " + where_value;
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);

	QSqlQuery query("SELECT " + fields.join(", ") + " FROM " + tableName + _where + _limit);

	query.exec();

	return query;
}

QSqlQuery SQLMgr::insertSelection(QString &tableName_to, QStringList &fields_to, QString &tableName_from, QStringList &fields_from, QString &where_field, QString &where_value, qint64 limit)
{
	QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
	QSqlQuery query("INSERT INTO " + tableName_to + "(" + fields_to.join(", ") + ")" +
		"SELECT " + fields_from.join(", ") + ")  FROM " + tableName_from +
		" WHERE " + where_field + " = " + where_value + _limit);

	query.exec();

	return query;
}
 //TODO: ���������� �������� �������� � ����������, ��������� ����������� 
QSqlQuery SQLMgr::insertValues(QString &tableName, QStringList &fields, QStringList &values, qint64 limit)
{
	QSqlQuery query;
	if (!values.isEmpty())
	{
		QString _limit = (limit <= 0) ? "" : " LIMIT " + QString::number(limit);
		query = QSqlQuery("INSERT INTO " + tableName + "(" + fields.join(", ") + ")" + "VALUES(" + values.join(", ") + ") " + _limit);

		query.exec();
	}

	return query;
}



// /private