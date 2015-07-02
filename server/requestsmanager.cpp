#include "requestsmanager.h"

namespace DefaultValues {
    const QString API_VERSION = "1.0";
}

QJsonDocument RequestsManager::request(const QUrl &url, const SQLMgr &db)
{
    QString request = url.path();
    QUrlQuery query( url );

    QString apiVersion = query.queryItemValue( ApiRequests::Params::API_VERSION );
    if( apiVersion.isEmpty() )
        apiVersion = DefaultValues::API_VERSION;

    Api *api = ApiFactory::createApi( apiVersion );

    int code = 0;

    QJsonObject response = api->responseRequest( url, db, code );

    delete api;

    return report(code, request, response);
}

QJsonDocument RequestsManager::report(const int code, const QString &request, const QJsonObject &response)
{
    QJsonObject report{
      {"code", code },
      {"request", request},
      {"response", response}
    };

    QJsonDocument doc;
    doc.setObject( report );

    return doc;
}
