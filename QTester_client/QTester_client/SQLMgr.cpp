#include "SQLMgr.h"

// public
SQLMgr::SQLMgr()
{
}

SQLMgr::SQLMgr(QString hostName, QString DBName, QString userName, QString password)
{		
	setHost(hostName);
	setDBName(DBName);
	setUName(userName);
	setPWD(password);
}


SQLMgr::~SQLMgr()
{
	_disconnect();
}
//  setters
void SQLMgr::setHost(QString host = "localhost")
{
	_host = host;
}

void SQLMgr::setConnectionName(QString connectionName = "myConnetion")
{
	_connectionName = connectionName;
}

void SQLMgr::setDBName(QString name)
{
	_DBName = name;
}

void SQLMgr::setUName(QString name)
{								  
	_userName = name;
}

void SQLMgr::setPWD(QString pwd)
{								
	_pwd = pwd;
}

void SQLMgr::setSqlDRV(QString SQLDRV)	// QSQLITE, QMYSQL  or like
{
	_SQLDRV = SQLDRV;
}
//  /setters

int SQLMgr::connect()
{
	db = QSqlDatabase::addDatabase(_SQLDRV, _connectionName);
	db.setHostName(_host);
	db.setDatabaseName(_DBName);
	db.setUserName(_userName);
	db.setPassword(_pwd);
	if (!db.open())
		return false;
	//TODO: error enum;
	return true;
}

int SQLMgr::createDB()
{
	QString SQL = "CREATE DATABESE";

	if (!request(SQL))
		return 1;
//TODO: error enum;
	return 0;
}

int SQLMgr::reqSelect(QString fields = "", QString tablesNames = "")
{
	QString Select = "SELECT ",
			from = " FROM ",
			SQL = "\0";

	if (fields != "" && tablesNames != "")
	{
		SQL = Select + fields + from + tablesNames;
	}
	else SQL = Select + "*" + from + "*";

	if (!request(SQL))
		return 1;
//TODO: error enum;
	return 0;
}

int SQLMgr::reqSelectWhere(QString fields = "", QString tablesNames = "", QString WHERE = "")
{
	QString Select = "SELECT ",
		from = " FROM ",
		where = " WHERE ",
		SQL = "\0";

	if (fields != "" && tablesNames != "" && WHERE != "")
	{
		SQL = Select + fields + from + tablesNames + where + WHERE;
	}
	else SQL = Select + "*" + from + "*" + where + "*";

	if (!request(SQL))
		return 1;
//TODO: error enum;
	return 0;
}

// /public

// private

void SQLMgr::_disconnect()
{
	db.close();
}

bool SQLMgr::request(QString SQL)
{
	if (!query.exec(SQL))
		return false;
//TODO: error enum;
	return true;
}

// /private