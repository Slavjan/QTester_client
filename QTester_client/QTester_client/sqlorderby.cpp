#include "orderby.h"


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

bool SqlOrderBy::ASC(const QString &order)
{
	if (isValid(order)){
		_order += order + " ASC ";
		return true;
	}
	return false;
}

bool SqlOrderBy::DESC(const QString &order)
{
	if (isValid(order)){
		_order += order + " DESC ";
		return true;
	}
	return false;
}

bool SqlOrderBy::RANDOM()
{
	_order += " RANDOM() ";			
}

bool SqlOrderBy::isValid() const
{
	return isValid(_order);
}
QString SqlOrderBy::toString() const
{
	return _order;
}