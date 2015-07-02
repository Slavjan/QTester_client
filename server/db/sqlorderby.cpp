#include "sqlorderby.h"


SqlOrderBy::SqlOrderBy(const QString &order)
{
	if (isValid(order)){
		if (order.contains("ORDER BY", Qt::CaseInsensitive)){
			QString o(order);
			_order += o.remove("ORDER BY", Qt::CaseInsensitive);
		}
		else _order += order;
	}
}

bool SqlOrderBy::isValid(const QString &sql) const
{
	/// \todo Complete later
	/// \warning incomplete !!!
	return true;//sql.isEmpty() == false;
}

SqlOrderBy SqlOrderBy::ASC(const QString &order)
{
	if (isValid(order)){
		_order += order;
	    _order += " ASC ";
		return *this;
	}
	return SqlOrderBy("");
}

SqlOrderBy SqlOrderBy::DESC(const QString &order)
{
	if (isValid(order)){
		_order += order;
		_order += " DESC ";
		return *this;
	}
	return SqlOrderBy("");
}

SqlOrderBy SqlOrderBy::RANDOM()
{
	return SqlOrderBy("ORDER BY RANDOM()");
}

bool SqlOrderBy::isValid() const
{
	return isValid(_order);
}
QString SqlOrderBy::toString() const
{
	return _order;
}