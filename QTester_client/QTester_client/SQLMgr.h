#pragma once
#include "stdHeaders.h"	
#include <QString>

class SQLMgr //SQL Manadger the base class for work with Data Bases
{
protected: 
	

public:	
//methods
//public
	SQLMgr();
	SQLMgr(QString hostName, QString DBName, QString userName, QString password);
	virtual ~SQLMgr();											   
//	connection settings	
	void setHost(QString);
	void setConnectionName(QString);
	void setDBName(QString);
	void setUName(QString);
	void setPWD(QString);
	void setSqlDRV(QString SQLDRV);
//	/connection settings
//	connection init	& configurate
	int connect();
	virtual int configurateConnection();
//	/connection init & configurate
//	requests
	bool request(QString SQL);
	int createDB();
	int createTable(QString TableName, QString , int *FIELDTYPE);
	int reqSelect(QString fields, QString tablesNames);
	int reqSelectWhere(QString fields, QString tablesNames, QString WHERE);
//	/requests
///public
protected:
//protected
	void _disconnect();
	
	bool validationTNames(QString TNames);
	bool validationFNames(QString FNames);
///protected
///methods
};

