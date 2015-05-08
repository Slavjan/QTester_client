#pragma once
#include "SQLMgr.h"
class SQLiteMgr : public SQLMgr
{

public:
	SQLiteMgr();
	SQLiteMgr(const QString &dbHost,
			  QString		 dbPath,
			  const QString &dbUser,
			  const QString &dbPass);
	~SQLiteMgr();

	void init(const QString &dbHost,
		      const QString &dbUser,
			  const QString &dbPass);	

	virtual bool sessionConfigurate(QStringList &parameters, QStringList &values, qint64 limit) override;
};

