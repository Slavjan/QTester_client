#ifndef API_H
#define API_H

#include <QUrl>
#include "sqlmgr.h"

namespace ApiRequests {
    namespace Params {
        const QString API_VERSION = "api_version";
    }
}

class Api
{
public:
    virtual QJsonObject responseRequest(const QUrl &url, const SQLMgr &db, int &code) = 0;
};

#endif // API_H
