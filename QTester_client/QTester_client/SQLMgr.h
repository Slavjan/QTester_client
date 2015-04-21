#pragma once
#include "stdHeaders.h"	   
#include <QtSql>

class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected:
	// connection info
	QString _host;
	QString _DBName;
	QString _userName;
	QString _pwd;
	QString _SQLDRV;
	// base info
	QVector<QString> tablesNames;
	QVector<QString> fieldsNames;
	QSqlDatabase db;
	
	

	virtual void _connect();
	virtual void _disconnect();
	
	virtual bool request(QString SQL);
	bool validationTNames(QString TNames);
	bool validationFNames(QString FNames);	 

public:
	SQLMgr();
	SQLMgr(QString hostName, QString DBName, QString userName, QString password);
	virtual ~SQLMgr();											   
	
	void setHost(QString host = "localhost");
	void setDBName(QString);
	void setUName(QString);
	void setPWD(QString);
	void setSqlDRV(QString SQLDRV);

	void connect();
	void createDB();
	//	void connect
	void reqSelect(QString fields, QString tablesNames);
	void reqSelectWhere(QString fields, QString tablesNames, QString WHERE);
};

