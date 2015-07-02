#pragma once
#include "sqlmgr.h"

class SQLiteMgr : public SQLMgr
{
private:
    static SQLiteMgr* _instance;

    SQLiteMgr();
    SQLiteMgr(const QString &dbHost,
              const QString	&dbPath);

public:
    static SQLiteMgr* instance( const QString &dbHost = "localhost",
                                const QString &dbPath = "");

    virtual qlonglong size(const QString &tableName);

    virtual bool sessionConfigurate(const DataMap &data) override;
};

