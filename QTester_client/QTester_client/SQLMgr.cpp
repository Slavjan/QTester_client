#include "SQLMgr.h"

// public
SQLMgr::SQLMgr()
{
}

SQLMgr::SQLMgr(QString hostName = "localhost", QString DBName, QString userName, QString password)
{		
	setHost(hostName);
	setDBName(DBName);
	setUName(userName);
	setPWD(password);
}


SQLMgr::~SQLMgr()
{
}

void SQLMgr::setHost(QString host)
{
	_host = host;
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

void SQLMgr::setSqlDRV(QString SQLDRV)	// QSQLITE or like
{
	_SQLDRV = SQLDRV;
}

void SQLMgr::createDB()
{
	QString SQL = "CREATE DATABESE";

	request(SQL);
}

void SQLMgr::connect()
{
	_connect();
}

void SQLMgr::reqSelect(QString fields = "", QString tablesNames = "")
{
	QString Select = "SELECT ",
			from = " FROM ",
			SQL = "\0";

	if (fields != "" && tablesNames != "")
	{
		SQL = Select + fields + from + tablesNames;
	}
	else SQL = Select + "*" + from + "*";

	request(SQL);
}

void SQLMgr::reqSelectWhere(QString fields = "", QString tablesNames = "", QString WHERE = "")
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

	request(SQL);
}

// /public
// private

// /private