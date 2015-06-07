#pragma once
#include <QObject>
#include <QUrlQuery>
#include "tcpclient.h"

class NetworkQueryManager :
    public QObject
{
    Q_OBJECT
    TcpClient *_client;

public slots:

    void authorisation(const QString &login, const QString &password);

public:
    NetworkQueryManager(const QString &host, const int port);
    ~NetworkQueryManager();
};

