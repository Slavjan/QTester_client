#pragma once
#ifndef SQLORDER_H
#define SQLORDER_H

#include <QString>

class SqlOrderBy
{
	QString _order = " ORDER BY ";

	bool isValid(const QString &sql) const;

public:
	SqlOrderBy(const QString &order);

	       SqlOrderBy    ASC(const QString &order);
	       SqlOrderBy    DESC(const QString &order);
	static SqlOrderBy    RANDOM();

	bool    isValid() const;
	QString toString() const;
};
#endif