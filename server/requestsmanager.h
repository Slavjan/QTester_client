#pragma once
#ifndef REQUESTSMANAGER_H
#define REQUESTSMANAGER_H

#include "sqlmgr.h"
#include "jsonformat.h"
//#include "tcpSoket" TODO: merge
#include "usercontrol.h"
#include "profession.h"

#include <QUrlQuery>

class RequestsManager
{
private:
    static QJsonObject autorisation( const SQLMgr &db, const QUrlQuery &urlQuery );
    static QJsonObject report( const SQLMgr &db, const QString &request, const QUrlQuery &query = QUrlQuery()/*TODO DEFAULT*/ );

public:
    static QString request( const SQLMgr &db, const QUrl &url );

    QJsonObject qCountToJsonObj(qint64 maxQCount);
};


#endif
