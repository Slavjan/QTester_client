#pragma once
#include "sqlmgr.h"
class SQLiteMgr : public SQLMgr
{

public:
	SQLiteMgr();
	SQLiteMgr(const QString &dbHost,
					QString	 dbPath,
			  const QString &dbUser,
			  const QString &dbPass);

	virtual qlonglong size(const QString &tableName);

    virtual bool sessionConfigurate(const DataMap &data) override;
};

