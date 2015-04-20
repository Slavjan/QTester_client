#pragma once
#include "stdHeaders.h"	   
#include <QSqlDatabase>

class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected:
	// connection info
	QString _host;
	QString _DBName;
	QString _userName;
	QString _pwd;
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
	~SQLMgr();

	void connect();
	void createDB();
//	void connect
	void reqSelect(QString fields, QString tableNames);
	void reqSelectWhere(QString fields, QString tableNames, QString WHERE);

	void setHost(QString host = "localhost");
	void setDBName(QString);
	void setUName(QString);
	void setPWD(QString);

};

