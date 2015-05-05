#pragma once
#include "SQLMgr.h"
class SQLiteMgr : public SQLMgr
{

public:
	SQLiteMgr(); 
	~SQLiteMgr();

	void init(const QString &dbHost,
		      const QString &dbUser,
			  const QString &dbPass);	

	virtual bool sescionConfigurate(QStringList &parameters, QStringList &values, qint64 limit);
};

