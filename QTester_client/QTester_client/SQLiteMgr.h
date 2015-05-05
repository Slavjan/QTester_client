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
	

	virtual bool createTable(QString &tableName, DataMap &data) override;

	virtual QSqlQuery select(QString &tableName,
						QStringList &fields,
						qint64 limit = 25) override;

	virtual QSqlQuery insert(QString& tableName_to,
							 QStringList& fields_to,
							 QString& tableName_from,
							 QStringList& fields_from,
							 QString& where_field,
							 QString& where_value,
							 qint64 limit) override;
	//static bool createTable(QString &tableName, DataMap &data);

	virtual bool sescionConfigurate(QStringList &parameters, QStringList &values, qint64 limit);
};

