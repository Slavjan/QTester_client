#pragma once

#include <QString>

class SqlOrderBy
{
	QString _order = "ORDER BY ";

	bool isValid(const QString &sql) const;

public:
	SqlOrderBy(const QString &order);

	bool    ASC(const QString &order);
	bool    DESC(const QString &order);
	bool	RANDOM();

	bool    isValid() const;
	QString toString() const;
};

