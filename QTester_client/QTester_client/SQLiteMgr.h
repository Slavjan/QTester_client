#pragma once
#include "SQLMgr.h"
class SQLiteMgr : public SQLMgr
{

public:
	SQLiteMgr();
	SQLiteMgr(const QString &dbHost,
					QString	 dbPath,
			  const QString &dbUser,
			  const QString &dbPass);
	~SQLiteMgr();

	virtual qint64 size(const QString &tableName);

    virtual bool sessionConfigurate(const DataMap &data) override;
};

