#include "apifactory.h"

Api *ApiFactory::createApi(const QString &apiVersion)
{
    if( apiVersion == "1.0" )
        return new Api_1_0;

    return new Api_1_0;
}

