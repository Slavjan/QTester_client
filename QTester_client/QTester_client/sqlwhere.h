#ifndef SQLWHERE_H
#define SQLWHERE_H

#include <QString>

class SqlWhere
{
    QString _where = "WHERE ";

    bool isValid(const QString &sql) const;

public:
    SqlWhere(const QString &where);

    bool    AND(const QString &where);
    bool    OR( const QString &where);

    bool    isValid() const;
    QString toString() const;
};

#endif // SQLWHERE_H
