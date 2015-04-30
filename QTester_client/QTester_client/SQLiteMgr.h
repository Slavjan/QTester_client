#pragma once
#include "SQLMgr.h"
class SQLiteMgr : SQLMgr
{

public:
	SQLiteMgr(const QString &dbHost,
			  const QString &dbUser,
			  const QString &dbPass) ; 
	~SQLiteMgr();

	static bool sescionConfigurate(QStringList &parameters, QStringList &values, qint64 limit);
};

