#pragma once
#include "stdHeaders.h"	   
#include <QtSql>

class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected: //fields
	// connection info
	QString _host;
	QString _connectionName;
	QString _DBName;
	QString _userName;
	QString _pwd;
	QString _SQLDRV;
	// base info
	QVector<QString> tablesNames;
	QVector<QString> fieldsNames;
	QSqlDatabase db;
	QSqlQuery query;
// /fields

public:	//methods
	SQLMgr();
	SQLMgr(QString hostName, QString DBName, QString userName, QString password);
	virtual ~SQLMgr();											   
	
	void setHost(QString);
	void setConnectionName(QString);
	void setDBName(QString);
	void setUName(QString);
	void setPWD(QString);
	void setSqlDRV(QString SQLDRV);

	int connect();
	int createDB();
	//	void connect
	int reqSelect(QString fields, QString tablesNames);
	int reqSelectWhere(QString fields, QString tablesNames, QString WHERE);

protected:
	void _disconnect();

	bool request(QString SQL);
	bool validationTNames(QString TNames);
	bool validationFNames(QString FNames);

// /methods
};

