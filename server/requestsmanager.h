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
    static void autorisation( const SQLMgr &db, const QUrlQuery &urlQuery );
    static void report( const SQLMgr &db, const QString &request );
public:                                  
    static void request( const SQLMgr &db, const QUrl &url );

};
#endif