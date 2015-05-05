#ifndef iSQL_H
#define iSQL_H

#include <QString>
#include "ConnectionMgr.h"
#include "SQLMgr.h"

#include <QMap>
#include <QString>
#include <QStringList>
#include <QSqlQuery>



class iSQL
{
public:	
	virtual ~iSQL()	{};

	virtual bool createTable() = 0;

	virtual QSqlQuery select() = 0;
	virtual QSqlQuery insert() = 0;
};
#endif