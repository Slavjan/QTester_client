#include "sqlwhere.h"

bool SqlWhere::isValid(const QString &sql) const
{
    /// \todo Complete later
    /// \warning incomplete !!!
    return sql.isEmpty() == false;
}

SqlWhere::SqlWhere(const QString &where)
{
    if( isValid(where) ){
        _where = where;
    }
}

bool SqlWhere::AND(const QString &where)
{
    if( isValid(where) ){
        _where += " AND " + where;
        return true;
    }
    return false;
}

bool SqlWhere::OR(const QString &where)
{
    if( isValid(where) ){
        _where += " OR " + where;
        return true;
    }
    return false;
}

bool SqlWhere::isValid() const
{
    return isValid(_where);
}

QString SqlWhere::toString() const
{
    return _where;
}

