#ifndef APIFACTORY_H
#define APIFACTORY_H

#include "api.h"
#include "api_1_0.h"

class ApiFactory
{
    ApiFactory();
public:
    static Api* createApi(const QString &apiVersion);
};

#endif // APIFACTORY_H
