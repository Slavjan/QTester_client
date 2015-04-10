#pragma once
#include "stdHeaders.h"

class SQLMgr //SQL Manadger the base class for work with Data Bases
{
private:
	// connection info
	string _host;
	string _DBName;
	string _userName;
	string _pwd;
	// base info
	vector<string> tablesNames;
	vector<string> fieldsNames;
	

	virtual void _connect();
	virtual void _disconnect();
	
	virtual bool request(string SQL);
	bool validationTNames(string TNames);
	bool validationFNames(string FNames);

	
public:
	SQLMgr();
	SQLMgr(string hostName, string DBName, string userName, string password);
	~SQLMgr();

	void connect();
	void createDB();
//	void connect
	void reqSelect(string fields, string tableNames);
	void reqSelectWhere(string fields, string tableNames, string WHERE);

	void setHost(string host = "localhost");
	void setDBName(string);
	void setUName(string);
	void setPWD(string);

};

