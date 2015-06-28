#pragma once
#ifndef REQUESTSMANAGER_H
#define REQUESTSMANAGER_H

#include "sqlmgr.h"
#include "jsonformat.h"
//#include "tcpSoket" TODO: merge
#include "usercontrol.h"
#include "profession.h"
#include "api/api.h"
#include "api/apifactory.h"

#include <QUrlQuery>


namespace userGroups
{
    enum UserGroups
    {
        Admin = 0, Prepod, Student
    };
}


class RequestsManager
{
private:
    static QJsonObject autorisation( const SQLMgr &db, const QUrlQuery &urlQuery );
    static QJsonObject report( const SQLMgr &db, const QString &request, const QUrlQuery &query = QUrlQuery()/*TODO DEFAULT*/ );

    static QJsonDocument report(const int code, const QString &request, const QJsonObject &response);

public:
    static QString request( const SQLMgr &db, const QUrl &url );
    static QJsonDocument request( const QUrl &url, const SQLMgr &db );

    QJsonObject qCountToJsonObj(qint64 maxQCount);
};


#endif
